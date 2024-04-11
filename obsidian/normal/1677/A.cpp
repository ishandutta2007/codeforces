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
const int V = 5010;
int _, n, a[V], pre[V][V], suf[V][V];
int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
        for (int i = 0; i <= n + 1; ++i)
            for (int j = 1; j <= n; ++j)
                pre[i][j] = suf[i][j] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j)
                pre[i][j] = pre[i - 1][j];
            for (int j = a[i]; j <= n; ++j)
                pre[i][j]++;
        }
        for (int i = n; i > 0; --i) {
            for (int j = 1; j <= n; ++j)
                suf[i][j] = suf[i + 1][j];
            for (int j = a[i]; j <= n; ++j)
                suf[i][j]++;
        }
        LL ans = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                ans += pre[i - 1][a[j] - 1] * suf[j + 1][a[i] - 1];
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}

/*
3
6
5 3 6 1 4 2
4
1 2 3 4
10
5 1 6 2 8 3 4 10 9 7
*/