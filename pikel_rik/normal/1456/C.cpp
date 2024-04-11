#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;
const int N = 5e5 + 5;

int n, k, c[N], cnt[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> c[i];

	sort(c, c + n, greater<>());

	if (k == 0) {
		ll ans = 0, sum = 0;
		for (int i = 0; i < n; i++) {
			ans += sum;
			sum += c[i];
		}
		cout << ans << '\n';
		return 0;
	}

	++k;
	ll cur = 0, sum = 0;

	for (int i = 0; i < n; i++) {
		cur += sum;
		sum += c[i];
	}

	multiset<int> s;

	ll ans = cur;
	for (int j = n - 1; j >= 0; j--) {
		sum -= c[j];
		cur -= sum;
		if (s.size() >= k) {
			s.erase(s.find(cnt[j % k]));
		}
		cur += (ll) (cnt[j % k]++) * c[j];
		s.insert(cnt[j % k]);
		ans = max(ans, cur + sum * (*s.rbegin()));
	}
	cout << ans << '\n';
	return 0;
}