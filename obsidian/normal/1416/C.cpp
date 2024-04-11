#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define PB push_back
#define fi first
#define se second
#define MP make_pair
const int P = 1000000007;
const int V = 300100;
const int M = 30;
int p[M + 10];
int a[V];
vector<int> g[2][V], b[2];
int cnt[2];
int n;
int main() {
    p[0] = 1;
    for (int i = 1; i <= M; ++i) p[i] = p[i - 1] * 2;
    while (~scanf("%d", &n)) {
        for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
        LL inv = 0;
        int ans = 0;
        int cur = 0, nxt = -1;
        g[0][0].clear();
        for (int i = 1; i <= n; ++i) g[0][0].PB(a[i]);
        cnt[cur] = 1;
        for (int i = M; i >= 0; --i) {
            nxt = 1 - cur;
            cnt[nxt] = 0;
            LL old = 0;
            LL total = 0;
            for (int j = 0; j < cnt[cur]; ++j) {
                int c1 = 0;
                b[0].clear(), b[1].clear();
                for (int k = 0; k < g[cur][j].size(); ++k) {
                    if (g[cur][j][k] & (1 << i)) ++c1, b[1].PB(g[cur][j][k]);
                    else old += c1, b[0].PB(g[cur][j][k]);
                }
                total += (LL) b[0].size() * b[1].size();
                for (int k = 0; k < 2; ++k) {
                    if (b[k].size() == 0) continue;
                    g[nxt][cnt[nxt]].clear();
                    for (int l = 0; l < b[k].size(); ++l) g[nxt][cnt[nxt]].PB(b[k][l]);
                    ++cnt[nxt];
                }
            }
            //printf("%d %I64d %I64d\n", i, old, total);
            if (old * 2 > total) ans += p[i], inv += total - old;
            else inv += old;
            cur = nxt;
        }
        printf("%I64d %d\n", inv, ans);
    }
    return 0;
}

/*
4
0 1 3 2
9
10 7 9 10 7 5 5 3 5
3
8 10 3
*/