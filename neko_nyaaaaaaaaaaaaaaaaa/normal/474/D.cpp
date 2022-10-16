#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll m = 1e9+7;

int main() {
      
      ll t, k;
      cin >> t >> k;
      vector<ll> s(100008, 0);
      for (int i = 0; i < k; i++) {
            s[i] = 1;
      }
      for (int i = k; i <= 100000; i++) {
            s[i] = (s[i-1] + s[i-k])%m;
      }
      vector<ll> ans(100008, 0);
      for (int i = 1; i <= 100000; i++) {
            ans[i] = (ans[i-1] + s[i])%m;
      }
      ll a, b;
      while (t--) {
            cin >> a >> b;
            ll k = (ans[b] - ans[a-1])%m;
            if (k < 0) {k += m;}
            cout << k << endl;
      }
      /////
}