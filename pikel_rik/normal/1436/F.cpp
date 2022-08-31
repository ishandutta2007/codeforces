#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 998244353;
const double pi = acos(-1.0);
const int inf = INT_MAX;
const int N = 1e5;

template <const int M>
struct ModInt {
    int val;
    ModInt(ll x = 0): val(x % M) { if (val < 0) { val += M; } }
    ModInt pow(ll n) const { ModInt ans = 1, x = val; while (n) { if (n & 1) ans *= x; x *= x; n /= 2; } return ans; }
    ModInt inv() const { return pow(M - 2); }
    ModInt operator- () const { return M - val; }
    ModInt operator+ (ModInt m) const { m.val += val; if (m.val >= M) m.val -= M; return m; }
    ModInt operator- (ModInt m) const { m.val -= val; if (m.val < 0)  m.val += M; return m; }
    ModInt operator* (ModInt m) const { m.val = m.val * (ll)val % M; return m; }
    ModInt operator/ (ModInt m) const { return *this * m.inv(); }
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

int n, mu[N + 1], freq[N + 1];
bool visited[N];

void comp() {
	fill(mu, mu + N + 1, 1);
	for (int i = 2; i <= N; i++) {
		if (!visited[i]) {
			for (int j = i; j <= N; j += i) {
				visited[j] = true;
				mu[j] = -mu[j];
			}
			if ((ll)i * i <= N) {
				for (int j = i * i; j <= N; j += i * i) {
					mu[j] = 0;
				}
			}
		}
	}
}

mint solve(int x) {
	mint sum = 0, sum_sq = 0;
	ll total = 0;
	for (int i = x; i <= N; i += x) {
		sum += mint(i) * freq[i];
		sum_sq += mint(i) * i * freq[i];
		total += freq[i];
	}
	mint sum_pairwise = sum * sum + - sum_sq;

	mint ans = 0;
	if (total >= 2) {
		ans = sum_sq * mint(2).pow(total - 2) * (total - 1);
		ans += sum_pairwise * (mint(2).pow(total - 2) * (total - 2) + mint(2).pow(total - 1)) / 2;
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	comp();

	cin >> n;
	for (int i = 0, x; i < n; i++) {
		cin >> x;
		cin >> freq[x];
	}

	mint ans = 0;
	for (int i = 1; i <= N; i++) {
		ans += mu[i] * solve(i);
	}
	cout << ans << '\n';
	return 0;
}