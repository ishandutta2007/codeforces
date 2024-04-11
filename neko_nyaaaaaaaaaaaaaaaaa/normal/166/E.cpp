#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll m = 1000000007;

int main() {
      ll n;
      cin >> n;
      ll ans = 1, abc = 0;
      for (ll i = 1; i <= n; i++) {
            ll d = abc * 3 % m;
      	int z = (abc * 2 + ans) % m;
      	ans = d;
      	abc = z;
      }
      cout << ans%m;
}