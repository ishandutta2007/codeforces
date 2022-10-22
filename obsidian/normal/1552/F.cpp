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
const int P = 998244353;
const int V = 200100;
int s[V], dp[V], x[V], y[V], z[V], n, nxt[V];
PII e[V];

int main() {
    while (~scanf("%d", &n)) {
        for (int i = 1; i <= n; ++i) scanf("%d%d%d", &x[i], &y[i], &z[i]);
        for (int i = 1; i <= n; ++i) e[i] = {y[i], i};
        sort(e + 1, e + n + 1);
        int p = 1;
        for (int i = 1; i <= n; ++i) {
            while (p != n + 1 && x[p] <= e[i].fi) ++p;
            nxt[e[i].se] = p;
        }
        s[0] = 0;
        for (int i = 1; i <= n; ++i) {
            dp[i] = x[i] - y[i];
            dp[i] += (s[i - 1] - s[nxt[i] - 1] + P) % P;
            dp[i] %= P;
            s[i] = (s[i - 1] + dp[i])% P;
            //printf("Dp %d %d\n", i, dp[i]);
        }
        int ans = (x[n] + 1) % P;
        for (int i = 1; i <= n; ++i) if (z[i]) ans = (ans + dp[i]) % P;
        printf("%d\n", ans);
    }
    return 0;
}

/*
4
3 2 0
6 5 1
7 4 0
8 1 1

1
454971987 406874902 1

5
243385510 42245605 0
644426565 574769163 0
708622105 208990040 0
786625660 616437691 0
899754846 382774619 0

5
200000000 100000000 1
600000000 400000000 0
800000000 300000000 0
900000000 700000000 1
1000000000 500000000 0
*/