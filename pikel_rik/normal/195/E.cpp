#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;
const int N = 1e5 + 5;

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

int n;
mint nxt[N], ans;
pair<int, mint> p[N];

pair<int, mint> find(int x) {
	if (x == p[x].first) {
		return p[x];
	}
	p[x] = find(p[x].first);
	nxt[x] = p[x].second + nxt[x];
	p[x].second = nxt[x];
	return p[x];
}

void merge(int i, int v, int x) {
	auto pp = find(v);
	int l = pp.first;
	p[l].first = i;
	nxt[l] = p[l].second = pp.second + x;
	ans = ans + nxt[l];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 1, k; i <= n; i++) {
		p[i].first = i;
		cin >> k;
		for (int j = 0, v, x; j < k; j++) {
			cin >> v >> x;
			merge(i, v, x);
		}
	}
	cout << ans << '\n';
	return 0;
}