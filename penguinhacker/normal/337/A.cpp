#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define arr array

int n, m, a[50], best=1e9;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=0; i<m; ++i) cin >> a[i];
	sort(a, a+m);
	for (int i=0; i<=m-n; ++i) best=min(best, a[i+n-1]-a[i]);
	cout << best;
	return 0;
}