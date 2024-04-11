#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair
#define int long long

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
	return ((a.first - a.second) > (b.first - b.second));
}

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int n; cin >> n;
	vector<pair<int, int>> a(n); for (int o = 0; o < n; o++) { cin >> a[o].first >> a[o].second; }
	sort(a.begin(), a.end(), comp);
	int re = 0;
	for (int i = 0; i < n; ++i) {
		re += ((a[i].first - a[i].second) * (i + 1ll) + (a[i].second * n - a[i].first));
	}
	cout << re;
}