#include <cstdio>
#include <vector>   
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <random>
#include <ctime>
#include <iomanip>
#include <deque>
#include <queue> 
#include <cmath>
#include <cstring>
#include <cassert>
#include <bitset>
#include <unordered_set>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int N = 100001, M = 201, MOD = 998244353;
int dp[2][2][M], a[N];
int n, s;

int add(int x, int y) {
    s = x + y;
    return s >= MOD ? s - MOD : s;
}

int sub(int x, int y) {
    return x > y ? x - y : x + MOD - y;
}

void f(int i, int i1, int x) {
    dp[0][i1][x] = add(dp[0][i][x - 1], dp[1][i][x - 1]);
    dp[1][i1][x] = add(sub(dp[0][i][x], dp[0][i][x - 1]), sub(dp[1][i][x], dp[1][i][x - 1]));
    dp[1][i1][x] = add(dp[1][i1][x], sub(dp[1][i][M - 1], dp[1][i][x]));
    /*for (int j = 0; j < x; j++)
        dp[0][i1][x] = add(add(dp[0][i1][x], dp[0][i][j]), dp[1][i][j]);
    dp[1][i1][x] = add(add(dp[1][i1][x], dp[0][i][x]), dp[1][i][x]);
    for (int j = x + 1; j < M; j++)
        dp[1][i1][x] = add(dp[1][i1][x], dp[1][i][j]);*/
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
#else
    //freopen("f.in", "r", stdin); 
    //freopen("f.out", "w", stdout);
#endif
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    scanf("%d", &n);
    for (int i = 0; i < M; i++)
        dp[1][0][i] = 1;
    for (int i = 0; i < n; i++) {
        int t = i % 2, t1 = t ^ 1;
        scanf("%d", &a[i]);
        memset(dp[0][t ^ 1], 0, M * sizeof(int));
        memset(dp[1][t ^ 1], 0, M * sizeof(int));
        if (a[i] > -1)
            f(t, t1, a[i]);
        else
            for (int j = 1; j < M; j++)
                f(t, t1, j);
        for (int i = 1; i < M; i++) {
            dp[0][t1][i] = add(dp[0][t1][i], dp[0][t1][i - 1]);
            dp[1][t1][i] = add(dp[1][t1][i], dp[1][t1][i - 1]);
        }
    }
    printf("%d", dp[1][n % 2][M - 1]);
}