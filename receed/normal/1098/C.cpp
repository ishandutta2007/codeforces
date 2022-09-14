#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <random>
#include <bitset>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); i++)
 
typedef long long ll;
typedef long double ld;
using namespace std;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	// /ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, s;
	cin >> n >> s;
	if (s < 2 * n - 1 || s > n * (n + 1) / 2) {
		cout << "No";
		return 0;
	}
	cout << "Yes\n";
	ll l = 0, r = n - 1, m;
	while (r - l > 1) {
		m = (l + r) / 2;
		ll cs = 0, pr = 1, cn = n, cr;
		for (ll i = 1; cn > 0; i++) {
			cr = min(pr, cn);
			cn -= cr;
			cs += i * cr;
			pr *= m;
		}
		if (s >= cs)
			r = m;
		else
			l = m;
	}
	ll ch = 2;
	s--;
	vector<deque<pair<ll, ll>>> v {{{1, r}}, {}};
	for (ll i = 2; i <= n; i++) {
		if (v[ch - 2].empty() || (n - i + 1) * (ch * 2 + n - i) / 2 < s) {
			v.emplace_back();
			ch++;
		}
		s -= ch;
		cout << v[ch - 2][0].first << ' ';
		cout << endl;
		v[ch - 2][0].second--;
		while (!v[ch - 2].empty() && v[ch - 2][0].second == 0)
			v[ch - 2].pop_front();
		v[ch - 1].push_back({i, r});
	}
}