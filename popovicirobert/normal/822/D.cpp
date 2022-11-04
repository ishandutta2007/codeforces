#include <bits/stdc++.h>
#define MAXN 5000000
#define MOD 1000000007

using namespace std;

long long dp[MAXN + 1];

int ciur[MAXN + 1];


inline void check(int i, int a) {
    dp[i] = min(dp[i], dp[i / a] + (1LL * (i / a) * dp[a]));
}

int main() {
  //  fstream cin("A.in");
  //  ofstream cout("A.out");
    int i, l, r, d, j;
    long long t;
    ios::sync_with_stdio(false);
    cin >> t >> l >> r;
    for(i = 2; i <= r; i++)
        if(ciur[i] == 0)
          for(j = i; j <= r; j += i)
             ciur[j] = i;
    dp[1] = 0;
    dp[2] = 1;
    for(i = 3; i <= r; i++) {
        dp[i] = (1LL << 62);
        if(ciur[i] == i)
            dp[i] = (1LL * i * (i - 1)) / 2;
        else {
            int aux = i;
            while(aux > 1) {
                check(i, ciur[aux]);
                aux /= ciur[aux];
            }
        }
    }
    long long p = 1;
    long long ans = 0;
    for(i = l; i <= r; i++) {
        dp[i] %= MOD;
        ans += (1LL * p * dp[i]);
        ans %= MOD;
        p = (1LL * p * t) % MOD;
    }
    cout << ans;
   // cin.close();
   // cout.close();
    return 0;
}