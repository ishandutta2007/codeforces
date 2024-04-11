#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 998244353;
const double pi = acos(-1.0);
const int inf = INT_MAX;

template<const int M>
struct ModInt {
	int val;
	ModInt(ll x = 0) : val(x % M) { if (val < 0) { val += M; }}
	ModInt pow(ll n) const { ModInt ans = 1, x = val; while (n) { if (n & 1) ans *= x; x *= x; n /= 2; } return ans; }
	ModInt inv() const { return pow(M - 2); }

	ModInt operator- () const { return M - val; }
	ModInt operator+ (ModInt m) const { m.val += val; if (m.val >= M) m.val -= M; return m; }
	ModInt operator- (ModInt m) const { m.val = val - m.val; if (m.val < 0) m.val += M; return m; }
	ModInt operator* (ModInt m) const { m.val = m.val * (ll) val % M; return m; }
	ModInt operator/ (ModInt m) const { return *this * m.inv(); }
	ModInt operator+=(ModInt m) { return *this = *this + m; }
	ModInt operator-=(ModInt m) { return *this = *this - m; }
	ModInt operator*=(ModInt m) { return *this = *this * m; }
	ModInt operator/=(ModInt m) { return *this = *this / m; }

	friend ModInt operator+(int lhs, ModInt m) { return ModInt(lhs) + m; }
	friend ModInt operator-(int lhs, ModInt m) { return ModInt(lhs) - m; }
	friend ModInt operator*(int lhs, ModInt m) { return ModInt(lhs) * m; }
	friend ModInt operator/(int lhs, ModInt m) { return ModInt(lhs) / m; }
	friend ModInt operator+(ll  lhs, ModInt m) { return ModInt(lhs) + m; }
	friend ModInt operator-(ll  lhs, ModInt m) { return ModInt(lhs) - m; }
	friend ModInt operator*(ll  lhs, ModInt m) { return ModInt(lhs) * m; }
	friend ModInt operator/(ll  lhs, ModInt m) { return ModInt(lhs) / m; }

	friend ostream &operator<<(ostream &os, const ModInt &m) {
		os << m.val;
		return os;
	}
	friend istream &operator>>(istream &is, ModInt &m) {
		ll x; is >> x; m = x;
		return is;
	}
};

using mint = ModInt<mod>;
const int N = 5e5 + 5;

struct cond {
	int l, r, x;
};

int n, k, m;
vector<int> add[N], rem[N];
cond a[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k >> m;
	for (int i = 0; i < m; i++) {
		cin >> a[i].l >> a[i].r >> a[i].x;
		--a[i].l; --a[i].r;
		add[a[i].l].push_back(i);
		rem[a[i].r].push_back(i);
	}

	mint final = 1;
	for (int b = 0; b < k; b++) {
		int cnt[2] = {0};
		vector<int> bad(n, n);
		vector<bool> ones(n);

		for (int i = 0; i < n; i++) {
			for (int j : add[i]) {
				if (a[j].x & (1 << b)) {
					cnt[1]++;
				} else {
					bad[i] = min(bad[i], a[j].r);
					cnt[0]--;
				}
			}
			if (cnt[1]) {
				ones[i] = true;
			}
			for (int j : rem[i]) {
				if (a[j].x & (1 << b)) {
					cnt[1]--;
				} else {
					cnt[0]--;
				}
			}
		}

		vector<mint> dp(n + 1);
		dp[n] = 1;

		int pos = n;
		mint sum = 0;
		if (!ones[n - 1]) {
			sum = 1;
		}
		bool plus_one = true;
		for (int i = n - 1; i >= 0; i--) {
			if (bad[i] != n) {
				plus_one = false;
			}
			while (pos > bad[i] + 1) {
				if (!ones[pos - 1]) {
					sum -= dp[pos];
				}
				pos--;
			}
			dp[i] = sum + plus_one;
			if (i > 0 && !ones[i - 1]) {
				sum += dp[i];
			}
		}
		final *= dp[0];
	}
	cout << final << '\n';
	return 0;
}