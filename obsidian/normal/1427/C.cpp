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
const int oo = 1000000000;
const int V = 100100;

int x[V], y[V], t[V], dp[V], mx[V];

int m, n;
int main() {
    while (~scanf("%d%d", &m, &n)) {
        x[0] = y[0] = 1;
        t[0] = 0;
        dp[0] = 0;
        mx[0] = 0;
        int ans = 0;
        for (int i = 1; i <= n; ++i) scanf("%d%d%d", &t[i], &x[i], &y[i]);
        for (int i = 1; i <= n; ++i) {
            dp[i] = -oo;
            for (int j = i - 1; j >= 0; --j) {
                if (t[i] - t[j] >= 2 * m) {
                    dp[i] = max(dp[i], mx[j] + 1);
                    break;
                }
                if (abs(x[i] - x[j]) + abs(y[i] - y[j]) > t[i] - t[j]) continue;
                dp[i] = max(dp[i], dp[j] + 1);
            }
            mx[i] = max(mx[i - 1], dp[i]);
            ans = max(ans, dp[i]);
        }
        printf("%d\n", ans);
    }
    return 0;
}

/*
10 1
11 6 8

6 9
1 2 6
7 5 1
8 5 5
10 3 1
12 4 4
13 6 2
17 6 6
20 1 4
21 5 4

10 4
1 2 1
5 10 9
13 8 8
15 9 9

500 10
69 477 122
73 186 235
341 101 145
372 77 497
390 117 440
494 471 37
522 300 498
682 149 379
821 486 359
855 157 386
*/