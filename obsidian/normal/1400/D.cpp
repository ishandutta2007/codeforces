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
const int V = 3100;
int _, n, a[V];
int s[V][V];
int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
        for (int i = 1; i <= n; ++i) s[0][i] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) s[i][j] = s[i - 1][j];
            s[i][a[i]]++;
        }
        LL ans = 0;
        for (int j = 1; j <= n; ++j) {
            for (int k = j + 1; k <= n; ++k) {
                int sj = s[n][a[j]] - s[k][a[j]];
                int sk = s[j - 1][a[k]];
                ans += sj * sk;
            }
        }
        printf("%I64d\n", ans);
    }
    return 0;
}

/*
2
5
2 2 2 2 2
6
1 3 3 1 2 3
*/