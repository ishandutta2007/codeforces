#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	ll n;
	cin >> n;
	vector<ll> a(n);
	ll min = 100000000000000;
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] < min) {min = a[i];}
	}
	vector<ll> ind;
	for (ll i = 0; i < n; i++) {
		if (a[i] == min) {ind.push_back(i);}
	}
	ll ans = 10000000;
	for (ll i = 1; i < ind.size(); i++) {
		if (ind[i] - ind[i-1] < ans) {ans = ind[i] - ind[i-1];}
	}
	cout << ans;
	
	return 0;
}