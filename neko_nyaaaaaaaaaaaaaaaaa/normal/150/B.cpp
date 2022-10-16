#include <bits/stdc++.h>
using namespace std;

#define int long long

int M = 1e9+7;

int modpow(int n, int k) {
      if (k == 0) return 1;
      if (k == 1) return n;

      int tmp = modpow(n, k/2);
      tmp = (tmp*tmp) % M;

      if (k % 2) return (tmp*n) % M;
      else return tmp;
}

signed main() {
      ios::sync_with_stdio(0); cin.tie(0);

      int n, m, k; cin >> n >> m >> k;
      if (k == 1 || k > n) {
            cout << modpow(m, n);
            return 0;
      }
      if (k == n) {
            cout << modpow(m, (n+1)/2);
            return 0;
      }
      if (k % 2) {
            cout << modpow(m, 2);
            return 0;
      }
      cout << m;

      return 0;
}