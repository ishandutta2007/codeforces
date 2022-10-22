#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define arr array

int n, a[100000];
map<int, int> mp;

bool ok() {
	for (auto i : mp)
		if (i.second > 1)
			return 0;
	return 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> a[i];
		mp[a[i]]++;
	}

	int lb = 0;
	int rb = -1;
	int best = 1e9;
	while (rb < n) {
		if (ok()) {
			best = min(best, rb-lb+1);
			mp[a[lb]]++;
			lb++;
		}
		else if (rb < n-1) {
			rb++;
			mp[a[rb]]--;
		}
		else
			break;
	}
	if (best<0)
		best = 0;

	cout << best;
	return 0;
}