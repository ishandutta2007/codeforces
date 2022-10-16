#include <bits/stdc++.h>
using namespace std;

map<long long, long long> mp;

long long phi(long long n) {
      if (mp[n]) return mp[n];
      long long k = n;

      long long ans = n;
      for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                  while (n % i == 0) {
                        n /= i;
                  }
                  ans -= ans / i;
            }
      }

      if (n > 1) {
            ans -= ans / n;
      }

      return mp[k] = ans;
}


long long md(long long a, long long b) {
      return (a < b ? a : a % b + b);
}

long long modpow(long long n, long long k, long long M) {
      if (k == 0) return md(1, M);

      long long tmp = modpow(n, k/2, M);
      tmp = md(tmp*tmp, M);

      if (k % 2) return md(tmp*n, M);
      else return tmp;
}
long long solve(int l, int r, long long M, long long a[]) {
      if (r == l || M == 1) return md(a[l], M);

      return modpow(a[l], solve(l+1, r, phi(M), a), M);
}

signed main() {
      ios::sync_with_stdio(0); cin.tie(0);

      int n; long long M; cin >> n >> M;
      long long a[n+1];
      for (int i = 1; i <= n; i++) {
            cin >> a[i];
      }

      int q; cin >> q;
      while (q--) {
            int l, r; cin >> l >> r;
            cout << solve(l, r, M, a) % M << '\n';
      }

      return 0;
}