#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, k, a[200000];
ll ans=0;
map<int, ll> mp1, mp2;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i=0; i<n; ++i) {
		cin >> a[i];
	}
	for (int i=0; i<n; ++i) {
		if (a[i]/k/k*k*k==a[i])
			ans+=mp2[a[i]/k];
		if (a[i]/k*k==a[i])
			mp2[a[i]]+=mp1[a[i]/k];
		mp1[a[i]]++;
	}
	cout << ans;
	return 0;
}