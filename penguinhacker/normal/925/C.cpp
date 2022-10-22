#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e5;
int n;
vector<ll> oc[60], ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i=0; i<n; ++i) {
		ll x;
		cin >> x;
		oc[63-__builtin_clzll(x)].push_back(x);
	}
	for (int i=59; ~i; --i) {
		if (oc[i].empty())
			continue;
		int valid=1;
		for (ll j : ans)
			valid+=(j>>i&1);
		if (oc[i].size()>valid) {
			cout << "No\n";
			return 0;
		}
		vector<ll> ans2={oc[i].back()};
		oc[i].pop_back();
		for (ll j : ans) {
			ans2.push_back(j);
			if (j&1ll<<i&&oc[i].size()) {
				ans2.push_back(oc[i].back());
				oc[i].pop_back();
			}
		}
		swap(ans, ans2);
	}
	cout << "Yes\n";
	for (ll i : ans)
		cout << i << " ";
	return 0;
}