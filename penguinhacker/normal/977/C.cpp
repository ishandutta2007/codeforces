#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, k;
map<int, int> mp;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for (int i=0; i<n; ++i) {
		int x;
		cin >> x;
		++mp[x];
	}
	if (k==0) {
		cout << (mp.begin()->first!=1?1:-1);
		return 0;
	}
	int cnt=0;
	for (auto& x : mp) {
		cnt+=x.second;
		if (cnt==k) {
			cout << x.first;
			return 0;
		}
	}
	cout << -1;
	return 0;
}