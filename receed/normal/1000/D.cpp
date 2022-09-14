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
typedef long long ll;
typedef long double ld;
  
using namespace std;

const int MOD = 998244353, N = 1002;

ll dp[N][N], a[N];

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
#endif
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    scanf("%d", &n);
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        for (int j = 0; j < n; j++)
            dp[i + 1][j] = (dp[i][j] + dp[i][j + 1]) % MOD;
        if (a[i] > 0 && a[i] <= n)
            dp[i + 1][a[i]] = (dp[i + 1][a[i]] + dp[i][0]) % MOD;
    }
    printf("%lld", (dp[n][0] + MOD - 1) % MOD);
}