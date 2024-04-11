#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<ll> a;

void gen(string s) {
      if (s.size() == 10) return;
      a.push_back(stoll(s));
      gen(s + '4');
      gen(s + '7');
}


int main() {
	ios::sync_with_stdio(0);
	gen("4"); gen("7");
	a.push_back(4444444444LL);
	sort(a.begin(), a.end());
	ll l, r;
	cin >> l >> r;
      ll ans=0;
      for (ll i = 0; i < a.size(); i++) {
            if (l > r) break;
            if (a[i] < l) continue;
            int t = min(a[i], r);
            ans += a[i]*(t-l+1);
            l = t+1;
      }
      cout << ans;
}