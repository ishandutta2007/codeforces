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
	map<int, int> mp, fmp;
	vector<pii> vec;
	multiset<int> s;
	for (int i = 0; i < n; i++) {
		int fi, se;
		cin >> fi >> se;
		mp[fi]++;
		if (se)
			fmp[fi]++;
	}
	for (auto cnt : mp) {
		vec.PB(MP(cnt.R, fmp[cnt.L]));
	}
	sort(all(vec), greater<pii>());
	int sum = 0;
	int mx = 1e9;
	vector<int> nums;
	for (auto cnt : vec) if (mx >= 0) {
		auto val = cnt.L;
		if (val >= mx) {
			sum += mx;
			nums.PB(mx);
			mx--;
		}
		else {
			sum += val;
			nums.PB(val);
			mx = val - 1;
		}
	}
	int ptr = 0;
	int fsum = 0;
	for (int i = 0; i < sz(nums); i++) {
		while (ptr < sz(vec) and vec[ptr].L >= nums[i]) {
			s.insert(vec[ptr].R);
			ptr++;
		}
		auto it = s.end();
		it--;
		fsum += min(*it, nums[i]);
		s.erase(it);
	}
	cout << sum << ' ' << fsum << '\n';
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