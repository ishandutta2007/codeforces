#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

const int MAX_N = 200000 + 5;

int T, N;
i64 W;
pair<i64, int> w[MAX_N];

int main() {
    scanf("%d", &T);
    for (; T --;)  {
        scanf("%d%lld", &N, &W);
        for (int i = 1; i <= N; i ++) {
            scanf("%lld", &w[i].first);
            w[i].second = i;
        }
        sort(w + 1, w + 1 + N);
        int k;
        for (k = N; k >= 1 && w[k].first > W; k --);
        i64 s = 0;
        vector<int> ans;
        for (; k >= 1 && s < W + 1 >> 1; k --) {
            if (s + w[k].first <= W) {
                s += w[k].first;
                ans.push_back(w[k].second);
            }
        }
        if (s < W + 1 >> 1) {
            printf("-1\n");
        } else {
            printf("%d\n", (int) ans.size());
            for (int i: ans) {
                printf("%d ", i);
            }
            printf("\n");
        }
    }
    return 0;
}