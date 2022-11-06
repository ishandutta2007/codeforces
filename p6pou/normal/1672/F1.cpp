#include <bits/stdc++.h>

using namespace std;

mt19937 Rand(0x1672f1);
const int MAX_N = 200000 + 5;

int T, N;
int a[MAX_N], b[MAX_N];

vector<int> p[MAX_N];
pair<int,int> val[MAX_N];
vector<int> c[MAX_N];
int loc[MAX_N], vis[MAX_N];

int main() {
    for (scanf("%d", &T); T --; ) {
        scanf("%d", &N);
        for (int i = 1; i <= N; i ++) {
            scanf("%d", &a[i]);
        }
        for (int i = 1; i <= N; i ++) {
            p[a[i]].push_back(i);
        }
        int K = 0;
        for (int i = 1; i <= N; i ++) {
            if (p[i].empty()) continue;
            val[++ K] = make_pair((int)p[i].size(), i);
        }
        sort(val + 1, val + 1 + K, greater<pair<int,int>>());
        // for (int i = 1; i <= K; i ++) {
        //     printf("val[%d]=(%d,%d)\n", i, val[i].first, val[i].second);
        // }
        // fflush(stdout);
        int C = val[1].first;
        if (C * 2 > N) {
            int x = val[1].second;
            shuffle(p[x].begin(), p[x].end(), Rand);
            for (int i = C * 2 - N; i >= 1; i --) {
                int j = p[x].back();
                p[x].pop_back();
                b[j] = a[j];
            }
        }
        // printf("C=min(%d,%d)\n", C, N - C);
        // fflush(stdout);
        C = min(C, N - C);
        for (int i = 1; i <= C; i ++) {
            int j;
            do {
                j = Rand() % N + 1;
            } while (a[j] == val[1].second || loc[j]);
            loc[j] = i;
            // printf("loc[%d]=%d\n", j, i);
            // fflush(stdout);
        }
        for (int i = 1; i <= K; i ++) {
            int x = val[i].second;
            for (int pb: p[x]) {
                if (loc[pb]) {
                    int j = loc[pb];
                    c[j].push_back(pb);
                    vis[j] = x;
                }
            }
            for (int pb: p[x]) {
                if (!loc[pb]) {
                    int j;
                    do {
                        j = Rand() % C + 1;
                    } while (vis[j] == x);
                    c[j].push_back(pb);
                    vis[j] = x;
                }
            }
        }
        for (int i = 1; i <= C; i ++) {
            // printf("c[%d]=", i);
            // for (int j = 0; j < c[i].size(); j ++) {
            //     printf("%d,", c[i][j]);
            // }
            // printf("\n");
            for (int j = 0; j < c[i].size(); j ++) {
                int x = c[i][j], y = j ? c[i][j - 1] : c[i].back();
                b[x] = a[y];
            }
        }
        for (int i = 1; i <= N; i ++) {
            printf("%d%c", b[i], i < N ? ' ' : '\n');
        }
        for (int i = 1; i <= N; i ++) {
            p[i].clear(), c[i].clear();
            loc[i] = vis[i] = b[i] = 0;
        }
    }
    return 0;
}