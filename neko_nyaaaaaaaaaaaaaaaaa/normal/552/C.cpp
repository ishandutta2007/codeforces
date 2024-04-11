#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

signed main() {
      ios::sync_with_stdio(0); cin.tie(0);

      ll n, m, p = 0; cin >> n >> m;
      vector<ll> dig(200);
      while (m) {
            dig[p++] = m % n;
            m /= n;
      }
      for (int i = 0; i <= p; i++) {
            if (dig[i] != 0 && dig[i] != 1 && dig[i] != n-1 && dig[i] != n) {
                  cout << "NO"; return 0;
            } else if (dig[i] == n-1 || dig[i] == n) {
                  dig[i+1]++;
            }
      }
      cout << "YES";

      return 0;
}