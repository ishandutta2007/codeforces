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
const int V = 1001000;

vector<PII> g[120];
int n, m, use[120], last[120], x, y;
int u[120], v[120];

int main() {
    while (~scanf("%d%d", &n, &m)) {
        int K = (n + m - 2) / (m - 1);
        for (int i = 0; i < K; ++i) g[i].clear();
        for (int i = 1; i <= n * m; ++i) {
            scanf("%d", &x);
            int gp = (x - 1) / (m - 1);
            g[gp].PB({(x - 1) % (m - 1), i});
        }
        for (int i = 0; i < K; ++i) {
            for (int j = 0; j < m - 1; ++j) use[j] = 0, last[j] = -1;
            for (int k = 0; k < g[i].size(); ++k) {
                x = g[i][k].fi;
                y = g[i][k].se;
                if (!use[x]) {
                    if (last[x] == -1) last[x] = y;
                    else {
                        u[x + i * (m - 1)] = last[x];
                        v[x + i * (m - 1)] = y;
                        for (int j = 0; j < m - 1; ++j) last[j] = -1;
                        use[x] = 1;
                    }
                }
            }
        }
        for (int i = 0; i < n; ++i) printf("%d %d\n", u[i], v[i]);
    }
    return 0;
}

/*
4 3
2 4 3 1 1 4 2 3 2 1 3 4
1 2
1 1
3 3
3 1 2 3 2 1 2 1 3
2 3
2 1 1 1 2 2
*/