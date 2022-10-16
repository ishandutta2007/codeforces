#include <bits/stdc++.h>
using namespace std;

#define int long long

int modpow(int n, int k, int MOD);

vector<int> ans;

void solve(int n, int k) {
      int people = n/k;
      int step = k;

      int a = people*(people-1)/2;
      a *= step;
      a += people;

      ans.push_back(a);
}

signed main() {
      ios::sync_with_stdio(0); cin.tie(0);

      int n; cin >> n;
      for (int i = 1; i*i <= n; i++) {
            if (n % i == 0) {
                  solve(n, i);
                  if (n/i != i) solve(n, n/i);
            }
      }
      sort(ans.begin(), ans.end());
      for (int i: ans) cout << i << ' ';

      return 0;
}

int modpow(int n, int k, int MOD) {
      if (k == 0) return 1;
      int tmp = modpow(n, k/2, MOD);
      tmp = (tmp*tmp) % MOD;
      if (k % 2) tmp = (tmp*n) % MOD;
      return tmp;
}