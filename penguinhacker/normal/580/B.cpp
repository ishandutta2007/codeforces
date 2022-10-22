#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define arr array

int n, d;
vector<pair<int, int>> a;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> d;
	a.resize(n);
	for (int i=0; i<n; ++i)
		cin >> a[i].first >> a[i].second;
	sort(a.begin(), a.end());

	int lb = 0;
	int rb = -1;
	ll money=0, ans=0;

	while (rb < n-1) {
		if (a[rb+1].first - a[lb].first < d) {
			rb++;
			money += a[rb].second;
			ans = max(ans, money);
		}
		else {
			money -= a[lb].second;
			lb++;
		}
	}
	
	cout << ans;
	return 0;
}