#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;
const int N = 1e5 + 5;

ll split(ll x, ll n) {
	ll length = x / n;
	return (x % n) * (length + 1) * (length + 1) + (n - x % n) * length * length;
}

int n, k, a[N];

struct comp {
	bool operator()(const pair<int, int>& i, const pair<int, int>& j) const {
		return split(i.first, i.second) - split(i.first, i.second + 1) > split(j.first, j.second) - split(j.first, j.second + 1);
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> a[i];

	multiset<pair<int, int>, comp> s;
	for (int i = 0; i < n; i++) {
		s.emplace(a[i], 1);
	}

	for (int i = 0; i < k - n; i++) {
		auto p = *s.begin();
		s.erase(s.begin());
		p.second++;
		s.insert(p);
	}

	ll ans = 0;
	for (auto& [x, n] : s) {
		ans += split(x, n);
	}
	cout << ans << '\n';
	return 0;
}