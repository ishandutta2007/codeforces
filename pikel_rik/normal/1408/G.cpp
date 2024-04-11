#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 998244353;
const double pi = acos(-1.0);
const int inf = INT_MAX;
const int N = 5000;

template <const int M>
struct ModInt {
    int val;
    ModInt(ll x = 0): val(x % M) { if (val < 0) { val += M; } }
    ModInt pow(ll n) const { ModInt ans = 1, x = val; while (n) { if (n & 1) ans *= x; x *= x; n /= 2; } return ans; }
    ModInt inverse() const { return pow(M - 2); }
    ModInt operator- () const { return M - val; }
    ModInt operator+ (ModInt m) const { m.val += val; if (m.val >= M) m.val -= M; return m; }
    ModInt operator- (ModInt m) const { m.val -= val; if (m.val < 0)  m.val += M; return m; }
    ModInt operator* (ModInt m) const { m.val = m.val * (ll)val % M; return m; }
    ModInt operator/ (ModInt m) const { return *this * m.inverse(); }
    ModInt operator+=(ModInt m) { return *this = *this + m; }
    ModInt operator-=(ModInt m) { return *this = *this - m; }
    ModInt operator*=(ModInt m) { return *this = *this * m; }
    ModInt operator/=(ModInt m) { return *this = *this / m; }

    friend ModInt operator+(int lhs, ModInt m) { return m + lhs; }
    friend ModInt operator-(int lhs, ModInt m) { return m - lhs; }
    friend ModInt operator*(int lhs, ModInt m) { return m * lhs; }
    friend ModInt operator/(int lhs, ModInt m) { return m / lhs; }
    friend ModInt operator+(ll  lhs, ModInt m) { return m + lhs; }
    friend ModInt operator-(ll  lhs, ModInt m) { return m - lhs; }
    friend ModInt operator*(ll  lhs, ModInt m) { return m * lhs; }
    friend ModInt operator/(ll  lhs, ModInt m) { return m / lhs; }

    friend ostream& operator<<(ostream& os, const ModInt& m) {
        os << m.val;
        return os;
    }
    friend istream& operator>>(istream& is, ModInt& m) {
        ll x; is >> x; m = x;
        return is;
    }
};

using mint = ModInt<mod>;

int n, a[N][N], p[N], r[N], e[N];
pair<int, int> edges[(N * N - N) / 2];
vector<mint> dp[N];

int find(int x) {
	return x == p[x] ? x : p[x] = find(p[x]);
}

void merge(int u, int v) {
	int l1 = find(u), l2 = find(v);
	if (l1 == l2) {
		e[l1]++;
	} else {
		vector<mint> dp1(dp[l1].size() + dp[l2].size() - 1);
		for (int i = 0; i < dp[l1].size(); i++) {
			for (int j = 0; j < dp[l2].size(); j++) {
				dp1[i + j] += dp[l1][i] * dp[l2][j];
			}
		}
		p[l2] = l1;
		r[l1] += r[l2];
		e[l1] += 1 + e[l2];
		dp[l1].swap(dp1);
		dp[l2].clear();
	}
	if (e[l1] == (r[l1] * r[l1] - r[l1]) / 2) {
		dp[l1][1] += 1;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++) {
		p[i] = i;
		r[i] = 1;
		dp[i] = {0, 1};
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			if (i != j) {
				edges[--a[i][j]] = make_pair(i, j);
			}
		}
	}

	for (int i = 0; i < (n * n - n) / 2; i++) {
		auto [u, v] = edges[i];
		merge(u, v);
	}

	int final = find(0);
	for (int i = 1; i <= n; i++) {
		cout << dp[final][i] << ' ';
	}
	cout << '\n';
	return 0;
}