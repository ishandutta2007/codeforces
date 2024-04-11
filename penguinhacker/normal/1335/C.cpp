#include <bits/stdc++.h>
using namespace std;

#define ll long long

int n;

void solve() {
	cin >> n;
	vector<int> cnt(n+1, 0);
	for (int i=0, a; i<n; ++i) {
		cin >> a;
		cnt[a]++;
	}
	int numDistinct=-1, maxSame=0;
	for (int i=1; i<=n; ++i) {
		if (cnt[i]) {
			numDistinct++;
			maxSame=max(maxSame, cnt[i]);
		}
	}
	cout << max(min(numDistinct, maxSame), min(numDistinct+1, maxSame-1)) << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}