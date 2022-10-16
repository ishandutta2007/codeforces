#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	
	ll x, d;
	cin >> x >> d;
	d += 2;
	vector<ll> bi;
	for (ll i = 2; i <= 1e9; i*=2) {
		bi.push_back(i-1);
	}
	
	vector<ll> ans;
	ll cur = 1;
	
	int pt = bi.size() - 1;
	while (x) {
		while (bi[pt] > x) {
			pt--;
		}
		x -= bi[pt];
		for (int i = 0; i <= pt; i++) {
			ans.push_back(cur);
		}
		cur += d;
	}
	
	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	
	return 0;
}