#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;
const int N = 2e5 + 5;

int n, cnt[N][26];
ll sum1[N][26], sum2[N][26];
string s, t;

ll f(ll x) {
	return (x * (x + 1) * (2 * x + 1)) / 6;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> s >> t;
	s = ' ' + s;
	t = ' ' + t;

	for (int i = 1; i <= n; i++) {
		memcpy(cnt[i], cnt[i - 1], sizeof(cnt[i]));
		memcpy(sum1[i], sum1[i - 1], sizeof(sum1[i]));
		cnt[i][s[i]- 'A']++;
		sum1[i][s[i] - 'A'] += i;
	}

	for (int i = n; i >= 1; i--) {
		memcpy(sum2[i], sum2[i + 1], sizeof(sum2[i]));
		sum2[i][s[i] - 'A'] += n - i + 1;
	}

	ld ans = 0;
	for (int i = 1; i <= n; i++) {
		int c = t[i] - 'A';
		ans += (ll)sum1[i - 1][c] * (n - i + 1);
		ans += (ll)sum2[i][c] * i;
	}
	ans /= f(n);

	cout << fixed << setprecision(12);
	cout << ans << '\n';
	return 0;
}