#include <bits/stdc++.h>
using namespace std;

template<int M>
struct static_mint {
	static_assert(0 < M, "Module must be positive");

	int val;

	static_mint() : val() {}

	static_mint(long long x) : val(x % M) { if (val < 0) val += M; }

	static_mint pow(long long n) const {
		static_mint ans = 1, x(*this);
		for (; n > 0; n /= 2) {
			if (n & 1) ans *= x;
			x *= x;
		}
		return ans;
	}

	static_mint inv() const {
		return pow(M - 2);
	}

	static_mint operator+() const {
		static_mint m;
		m.val = val;
		return m;
	}

	static_mint operator-() const {
		static_mint m;
		m.val = (val == 0 ? 0 : M - val);
		return m;
	}

	static_mint &operator+=(const static_mint &m) {
		if ((val += m.val) >= M) val -= M;
		return *this;
	}

	static_mint &operator-=(const static_mint &m) {
		if ((val -= m.val) < 0) val += M;
		return *this;
	}

	static_mint &operator*=(const static_mint &m) {
		val = (long long) val * m.val % M;
		return *this;
	}

	static_mint &operator/=(const static_mint &m) {
		val = (long long) val * m.inv().val % M;
		return *this;
	}

	friend static_mint operator+(const static_mint &lhs, const static_mint &rhs) {
		return static_mint(lhs) += rhs;
	}

	friend static_mint operator-(const static_mint &lhs, const static_mint &rhs) {
		return static_mint(lhs) -= rhs;
	}

	friend static_mint operator*(const static_mint &lhs, const static_mint &rhs) {
		return static_mint(lhs) *= rhs;
	}

	friend static_mint operator/(const static_mint &lhs, const static_mint &rhs) {
		return static_mint(lhs) /= rhs;
	}

	friend bool operator==(const static_mint &lhs, const static_mint &rhs) {
		return lhs.val == rhs.val;
	}

	friend bool operator!=(const static_mint &lhs, const static_mint &rhs) {
		return lhs.val != rhs.val;
	}

	static_mint &operator++() {
		return *this += 1;
	}

	static_mint &operator--() {
		return *this -= 1;
	}

	static_mint operator++(int) {
		static_mint result(*this);
		*this += 1;
		return result;
	}

	static_mint operator--(int) {
		static_mint result(*this);
		*this -= 1;
		return result;
	}

	template<typename T>
	explicit operator T() const {
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

	constexpr int N = (int)1e5;

	vector<mint> fact(N + 1), inv_fact(N + 1);
	fact[0] = inv_fact[0] = 1;
	for (int i = 1; i <= N; i++) {
		fact[i] = i * fact[i - 1];
		inv_fact[i] = fact[i].inv();
	}

	auto choose = [&](int n, int k) -> mint {
		return fact[n] * inv_fact[n - k] * inv_fact[k];
	};

	auto partition = [&](int n, int k) -> mint {
		return choose(n + k - 1, n);
	};

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		string s;
		cin >> s;

		if (count(s.begin(), s.end(), '1') == 0) {
			cout << 1 << '\n';
			continue;
		}

		int len = 0;
		vector<int> lens;

		for (int i = 0; i < n; i++) {
			if (s[i] == '1') {
				len += 1;
			} else if (len % 2 != 0) {
				lens.push_back(len);
				len = 0;
			}
		}

		if (len > 0) {
			lens.push_back(len);
		}

		if (lens.size() > 1 && lens.back() % 2 == 0) {
			lens[(int) lens.size() - 2] += lens.back();
			lens.pop_back();
		}

		int zeroes = count(s.begin(), s.end(), '0');
		if (lens.back() % 2 == 0) {
			cout << partition(zeroes, lens.back() / 2 + 1) << '\n';
		} else {
			int even = 0;
			for (auto &segment : lens) {
				even += segment - 1;
			}
			cout << partition(even / 2, zeroes + 1) << '\n';
		}
	}
	return 0;
}