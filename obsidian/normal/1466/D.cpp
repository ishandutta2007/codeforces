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
const int V = 100100;
int w[V], a[V], dg[V];
int _, n, u, v, m;

int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) scanf("%d", &w[i]);
        for (int i = 1; i <= n; ++i) dg[i] = 0;
        for (int i = 1; i < n; ++i) {
            scanf("%d%d", &u, &v);
            dg[u]++;
            dg[v]++;
        }
        m = 0;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j < dg[i]; ++j)
                a[m++] = w[i];
        sort(a, a + m);
        LL ans = 0;
        for (int i = 1; i <= n; ++i) ans += w[i];
        for (int i = m - 1; i >= 0; --i) {
            printf("%I64d ", ans);
            ans += a[i];
        }
        printf("%I64d\n", ans);
    }
    return 0;
}

/*
4
4
3 5 4 6
2 1
3 1
4 3
2
21 32
2 1
6
20 13 17 13 13 11
2 1
3 1
4 1
5 1
6 1
4
10 6 6 6
1 2
2 3
4 1
*/