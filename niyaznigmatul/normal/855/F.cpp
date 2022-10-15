#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

using namespace std;

#define right lkjljzxlcjlk
#define left jahdskjhsdj
int const K = 333;
int const N = 100100;
int const INF = 1 << 30;
int type[N], left[N], right[N], blockMax[N], blockMin[N], xs[N], mx[N], mn[N], value[N];

int main() {
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        scanf("%d%d%d", type + i, left + i, right + i);
        if (type[i] == 1) {
            scanf("%d", value + i);
        }
    }
    for (int i = 0; i < N; i++) {
        mx[i] = INF;
        mn[i] = -INF;
    }
    for (int from = 0; from < q; from += K) {
        int to = std::min(q, from + K);
        int cn = 0;
        xs[cn++] = N;
        for (int i = 0; i < to; i++) {
            xs[cn++] = left[i];
            xs[cn++] = right[i];
        }
        std::sort(xs, xs + cn);
        cn = (int) (std::unique(xs, xs + cn) - xs);
        for (int i = 0; i < cn; i++) {
            blockMax[i] = INF;
        }
        for (int i = 0; i < cn; i++) {
            blockMin[i] = -INF;
        }
        // std::fill(blockMax, blockMax + cn, INF);
        // std::fill(blockMin, blockMin + cn, -INF);
        for (int i = 0, j = 0, *b1 = blockMax, *b2 = blockMin; i < N; i++) {
            if (xs[j] == i) {
                ++b1;
                ++b2;
                ++j;
            }
            // if (blockMax[j] > mx[i]) blockMax[j] = mx[i];
            // if (blockMin[j] < mn[i]) blockMin[j] = mn[i];
            // blockMax[j] = std::min(blockMax[j], mx[i]);
            // blockMin[j] = std::max(blockMin[j], mn[i]);
            *b1 = *b1 > mx[i] ? mx[i] : *b1;
            *b2 = *b2 < mn[i] ? mn[i] : *b2;
        }
        for (int i = from; i < to; i++) {
            int lb = (int) (std::lower_bound(xs, xs + cn, left[i]) - xs) + 1;
            int rb = (int) (std::lower_bound(xs, xs + cn, right[i]) - xs) + 1;
            if (type[i] == 1) {
                int k = value[i];
                if (k > 0) {
                    int *start = blockMax + lb;
                    int *end = blockMax + rb;
                    while (start != end) {
                        // if (*start > k) *start = k;
                        *start = *start > k ? k : *start;
                        ++start;
                    }
                } else {
                    int *start = blockMin + lb;
                    int *end = blockMin + rb;
                    while (start != end) {
                        // if (*start < k) *start = k;
                        *start = *start < k ? k : *start;
                        ++start;
                    }
                }
            } else {
                long long ans = 0;
                for (int j = lb; j < rb; j++) {
                    // ans += blockMax[j] != INF && blockMin[j] != -INF ? (long long) (blockMax[j] - blockMin[j]) * (xs[j] - xs[j - 1]) : 0;
                    if (blockMax[j] != INF && blockMin[j] != -INF) {
                        ans += (long long) (blockMax[j] - blockMin[j]) * (xs[j] - xs[j - 1]);
                    }
                }
                printf("%lld\n", ans);
            }
        }
        for (int i = 0, j = 0; i < N; i++) {
            if (xs[j] == i) ++j;
            mx[i] = mx[i] < blockMax[j] ? mx[i] : blockMax[j];
            mn[i] = mn[i] < blockMin[j] ? blockMin[j] : mn[i];
            // mx[i] = std::min(mx[i], blockMax[j]);
            // mn[i] = std::max(mn[i], blockMin[j]);
        }
    }
}