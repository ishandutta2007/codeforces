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
	ModInt(): val(-1) {}
	ModInt(ll x) : val(x % M) { if (val < 0) { val += M; }}
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
const int N = 5000 + 5;

mint fact[N], inv[N];
mint choose(int n, int k) {
    return fact[n] * inv[n - k] * inv[k];
}

int n, a[N], smaller[N];
mint dp[N];

mint recurse(int i) {
	if (dp[i].val != -1) {
		return dp[i];
	}
	if (i == n) {
		return dp[i] = 1;
	}
	dp[i] = 0;
	for (int j = i + 1; j <= n; j++) {
		if (a[j] >= 2 * a[i]) {
			int cnt = smaller[i] + j - i - 1 - smaller[j];
			mint factor = choose(n - i - 1 + smaller[i], cnt) * fact[cnt];
			dp[i] += factor * recurse(j);

		}
	}
//	cout << i << ' ' << dp[i] << '\n';
	return dp[i];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	fact[0] = inv[0] = 1;
	for (int i = 1; i < N; i++) {
		fact[i] = i * fact[i - 1];
		inv[i] = fact[i].inv();
	}

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a, a + n + 1);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			smaller[i] += 2 * a[j] > a[i];
		}
	}

	if (smaller[n]) {
		cout << 0 << '\n';
		return 0;
	}

	cout << recurse(0) << '\n';
	return 0;
}