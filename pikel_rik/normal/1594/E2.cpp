#include <bits/stdc++.h>
using namespace std;

template<int M>
struct static_mint {
	static_assert(0 < M, "Module must be positive");

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

template <typename>
struct is_mint_helper : std::false_type { };

template <int M>
struct is_mint_helper<static_mint<M>> : std::true_type { };

template <typename T>
struct is_mint : is_mint_helper<typename std::decay<T>::type> { };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	using mint = static_mint<1000000007>;

	map<string, int> color_code = {
			{"white", 0},
			{"yellow", 1},
			{"green", 2},
			{"blue", 3},
			{"red", 4},
			{"orange", 5}
	};

	int k;
	cin >> k;

	long long total_nodes = (1ll << k) - 1;

	int m;
	cin >> m;

	vector<long long> v(m), c(m);
	for (int i = 0; i < m; i++) {
		string s;
		cin >> v[i] >> s;
		c[i] = color_code[s] / 2;
	}

	vector<long long> vertices;
	for (int i = 0; i < m; i++) {
		for (long long j = v[i]; j > 0; j /= 2) {
			vertices.push_back(j);
		}
	}

	sort(vertices.begin(), vertices.end());
	vertices.erase(unique(vertices.begin(), vertices.end()), vertices.end());
	int n = (int) vertices.size();

	vector<array<mint, 3>> dp(n);
	for (int i = 0; i < n; i++) {
		dp[i] = {0, 0, 0};
	}

	auto dfs = [&](int u, const auto &self) -> void {
		int left = lower_bound(vertices.begin(), vertices.end(), 2 * vertices[u]) - vertices.begin();
		if (left != n && vertices[left] != 2 * vertices[u]) {
			left = n;
		}

		int right = lower_bound(vertices.begin(), vertices.end(), 2 * vertices[u] + 1) - vertices.begin();
		if (right != n && vertices[right] != 2 * vertices[u] + 1) {
			right = n;
		}

		auto it = find(v.begin(), v.end(), vertices[u]);
		if (it != v.end()) {
			int color = c[it - v.begin()];
			dp[u][color] = 1;
		} else {
			dp[u][0] = dp[u][1] = dp[u][2] = 1;
		}

		for (int child : {left, right}) {
			if (child != n) {
				self(child, self);
				dp[u][0] *= dp[child][1] + dp[child][2];
				dp[u][1] *= dp[child][0] + dp[child][2];
				dp[u][2] *= dp[child][0] + dp[child][1];
			}
		}
	};

	dfs(0, dfs);

	mint ans = dp[0][0] + dp[0][1] + dp[0][2];
	ans *= mint(2).pow(n - m) * mint(4).pow(total_nodes - n);

	cout << ans << '\n';
	return 0;
}