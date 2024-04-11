#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	
	ll a, b;
	cin >> a >> b;
	vector<ll> ans = {b};
	while (b > a) {
	      if (b % 2 == 0) {
	            b /= 2;
	            ans.push_back(b);
	            continue;
	      }
	      if (b % 10 == 1) {
	            b /= 10;
	            ans.push_back(b);
	            continue;
	      }
	      cout << "NO"; return 0;
	}
	if (b == a) {
	      cout << "YES\n" << ans.size() << endl;
	      reverse(ans.begin(), ans.end());
	      for (int i = 0; i < ans.size(); i++) {
	            cout << ans[i] << " ";
	      }
	}
	else {cout << "NO";}
	
	return 0;
}