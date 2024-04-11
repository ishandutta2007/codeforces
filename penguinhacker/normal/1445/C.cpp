#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

vector<int> factor(int x) {
	vector<int> f;
	for (int i=2; i*i<=x; ++i) {
		if (x%i) continue;
		f.push_back(i);
		while(x%i==0) x/=i;
	}
	if (x>1) f.push_back(x);
	return f;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		ll p, q;
		cin >> p >> q;
		vector<int> f = factor(q);
		ll ans = -1;
		for (int i : f) {
			ll cur = p;
			while(cur % q == 0) cur /= i;
			ans = max(ans, cur);
		}
		cout << ans << "\n";
	}
	return 0;
}