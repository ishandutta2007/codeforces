#include <bits/stdc++.h>
using namespace std;

template<int M>
struct static_mint {
	static_assert(0 < M, "Module must be positive");

	constexpr static auto get_m() {
		return M;
	}

	int val;

	constexpr static_mint() : val() {}

	constexpr static_mint(long long x) : val(x % M) { if (val < 0) val += M; }

	constexpr static_mint pow(long long n) const {
		static_mint ans = 1, x(*this);
		for (; n > 0; n /= 2) {
			if (n & 1) ans *= x;
			x *= x;
		}
		return ans;
	}

	constexpr static_mint inv() const {
		return pow(M - 2);
	}

	constexpr static_mint operator+() const {
		static_mint m;
		m.val = val;
		return m;
	}

	constexpr static_mint operator-() const {
		static_mint m;
		m.val = (val == 0 ? 0 : M - val);
		return m;
	}

	constexpr static_mint &operator+=(const static_mint &m) {
		if ((val += m.val) >= M) val -= M;
		return *this;
	}

	constexpr static_mint &operator-=(const static_mint &m) {
		if ((val -= m.val) < 0) val += M;
		return *this;
	}

	constexpr static_mint &operator*=(const static_mint &m) {
		val = (long long) val * m.val % M;
		return *this;
	}

	constexpr static_mint &operator/=(const static_mint &m) {
		val = (long long) val * m.inv().val % M;
		return *this;
	}

	constexpr friend static_mint operator+(const static_mint &lhs, const static_mint &rhs) {
		return static_mint(lhs) += rhs;
	}

	constexpr friend static_mint operator-(const static_mint &lhs, const static_mint &rhs) {
		return static_mint(lhs) -= rhs;
	}

	constexpr friend static_mint operator*(const static_mint &lhs, const static_mint &rhs) {
		return static_mint(lhs) *= rhs;
	}

	constexpr friend static_mint operator/(const static_mint &lhs, const static_mint &rhs) {
		return static_mint(lhs) /= rhs;
	}

	constexpr friend bool operator==(const static_mint &lhs, const static_mint &rhs) {
		return lhs.val == rhs.val;
	}

	constexpr friend bool operator!=(const static_mint &lhs, const static_mint &rhs) {
		return lhs.val != rhs.val;
	}

	constexpr static_mint &operator++() {
		return *this += 1;
	}

	constexpr static_mint &operator--() {
		return *this -= 1;
	}

	constexpr static_mint operator++(int) {
		static_mint result(*this);
		*this += 1;
		return result;
	}

	constexpr static_mint operator--(int) {
		static_mint result(*this);
		*this -= 1;
		return result;
	}

	template<typename T>
	constexpr explicit operator T() const {
		return T(val);
	}

	friend std::ostream &operator<<(std::ostream &os, const static_mint &m) {
		return os << m.val;
	}

	friend std::istream &operator>>(std::istream &is, static_mint &m) {
		long long x;
		return is >> x, m = x, is;
	}
};



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    using mint = static_mint<998244353>;

    constexpr int sz = (int) 1e6;

    vector<mint> fact(sz + 1), inv(sz + 1);

    fact[0] = inv[0] = 1;
    for (int i = 1; i <= sz; i++) {
        fact[i] = i * fact[i - 1];
        inv[i] = fact[i].inv();
    }

    auto choose = [&](int n, int k) -> mint {
        return fact[n] * inv[k] * inv[n - k];
    };

    auto can_be_BW = [](const string &s) -> bool {
        return (s[0] == 'B' || s[0] == '?') && (s[1] == 'W' || s[1] == '?');
    };

    auto can_be_WB = [](const string &s) -> bool {
        return (s[0] == 'W' || s[0] == '?') && (s[1] == 'B' || s[1] == '?');
    };

    int n;
    cin >> n;

    vector<string> a(n);
    for (auto &s : a) cin >> s;

    //equal number of BBs and WWs
    //If something is BW, then others cannot all be WBs
    //If something is WB, then others cannot all be BWs

    int offset = 0, binom_pw = 0;
    for (auto &s : a) {
        if (s == "WW") {

        } else if (s == "BB") {
            offset += 2;
        } else if (s == "W?" || s == "?W") {
            binom_pw += 1;
        } else if (s == "B?" || s == "?B") {
            binom_pw += 1;
            offset += 1;
        } else if (s == "??") {
            binom_pw += 2;
        } else {
            offset += 1;
        }
    }

    if (0 <= n - offset && n - offset <= binom_pw) {
        mint ans = choose(binom_pw, n - offset);

        mint invalid = 1;

        int all_BW = 1, all_WB = 1;
        for (int i = 0; i < n; i++) {
            mint ways = can_be_BW(a[i]) + can_be_WB(a[i]);
            invalid *= ways;
            all_BW &= can_be_BW(a[i]);
            all_WB &= can_be_WB(a[i]);
        }

        ans -= invalid;
        ans += all_BW + all_WB;
        cout << ans << '\n';
    } else {
        cout << 0 << '\n';
    }
    return 0;
}