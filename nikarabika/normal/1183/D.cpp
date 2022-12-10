//sobskdrbhvk
//remember...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

int solve() {
	int n;
	cin >> n;
	map<int, int> mp;
	vector<int> vec;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		mp[x]++;
	}
	for (auto cnt : mp)
		vec.PB(cnt.R);
	sort(all(vec), greater<int>());
	int sum = 0;
	int mx = 1e9;
	for (auto val : vec) if (mx >= 0) {
		if (val >= mx) {
			sum += mx;
			mx--;
		}
		else {
			sum += val;
			mx = val - 1;
		}
	}
	cout << sum << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int q;
	cin >> q;
	while (q--)
		solve();
	return 0;
}