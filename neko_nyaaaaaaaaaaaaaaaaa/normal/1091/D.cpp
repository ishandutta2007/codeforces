#include <bits/stdc++.h>
using namespace std;

#define int long long

int modpow(int n, int k, int MOD);
int M = 998244353;
int ft[1000006];

void init() {
    ft[0] = ft[1] = 1;
    for (int i = 2; i <= 1000000; i++) {
        ft[i] = (ft[i-1] * i) % M;
    }
}

int binomcoeff(int n, int k) {
    int p = ft[n];
    int q = (ft[k]*ft[n-k]) % M;
    return (p*modpow(q, M-2, M)) % M;
}

signed main() {
      ios::sync_with_stdio(0); cin.tie(0);
      init();

      int n; cin >> n;
      int ans = (ft[n]*n) % M;

      for (int i = 1; i < n; i++) {
            int k = binomcoeff(n, i)*ft[n-i];
            k %= M;
            ans -= k;
            ans %= M;
      }
      while (ans < 0) ans += M;
      cout << ans;

      return 0;
}

int modpow(int n, int k, int MOD) {
      if (k == 0) return 1;
      int tmp = modpow(n, k/2, MOD);
      tmp = (tmp*tmp) % MOD;
      if (k % 2) tmp = (tmp*n) % MOD;
      return tmp;
}