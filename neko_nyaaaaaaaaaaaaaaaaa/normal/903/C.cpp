#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n;
	cin >> n;
	vector<ll> a(n);
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	vector<ll> ans;
	ans.push_back(0);
	while (a.size()) {
		ll i = 0;
		while (i < a.size()) {
			if (a[i] > ans[ans.size()-1]) {
				ans[ans.size()-1] = a[i];
				a.erase(a.begin()+i);
			} else {i++;}
		}
		if (a.size()) {ans.push_back(0);}
	}
	cout << ans.size();
	
	return 0;
}