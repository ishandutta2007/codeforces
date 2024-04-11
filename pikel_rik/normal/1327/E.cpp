#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 998244353;
const double pi = acos(-1.0);
const int inf = INT_MAX;
const int N = 2e5 + 5;

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

mint ten[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ten[0] = 1;
	for (int i = 1; i < N; i++) {
		ten[i] = 10 * ten[i - 1];
	}

	int n;
	cin >> n;

	for (int i = 1; i < n; i++) {
		mint ans = 2 * (ten[n - i] - ten[n - i - 1]);
		if (n - i - 2 >= 0) {
			ans += (n - i - 1) * (ten[n - i] - (2 * ten[n - i - 1] - ten[n - i - 2]));
		}
		cout << ans * 10 << ' ';
	}

	cout << 10 << '\n';
	return 0;
}