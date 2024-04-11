#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define arr array

int removed = 0;
ll n, m, k, a[100000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	for (int i=0, x; i<m; ++i)
		cin >> a[i];
	int cnt = 0;

	while (removed < m) {
		cnt++;
		ll x = (a[removed]-removed+k-1)/k * k;
		int toRemove = 0;
		while (removed+toRemove<n && a[removed+toRemove]-removed <= x)
			toRemove++;
		removed += toRemove;
	}

	cout << cnt;
	return 0;
}