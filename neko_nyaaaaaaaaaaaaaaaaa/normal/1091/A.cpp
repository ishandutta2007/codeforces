#include <bits/stdc++.h>
using namespace std;

#define int long long

int modpow(int n, int k, int MOD);

signed main() {
      ios::sync_with_stdio(0); cin.tie(0);

      int y, b, r; cin >> y >> b >> r;
      int ans = min(y, min(b-1, r-2));

      cout << ans+ans+1+ans+2;

      return 0;
}

int modpow(int n, int k, int MOD) {
      if (k == 0) return 1;
      int tmp = modpow(n, k/2, MOD);
      tmp = (tmp*tmp) % MOD;
      if (k % 2) tmp = (tmp*n) % MOD;
      return tmp;
}