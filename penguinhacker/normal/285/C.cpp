#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define arr array

int n, a[300000];
ll ans=0;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i) cin >> a[i];
	sort(a, a+n);
	for (int i=0; i<n; ++i) ans+=abs(a[i]-(i+1));
	cout << ans;
	return 0;
}