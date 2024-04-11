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

	constexpr friend bool operator<(const static_mint &lhs, const static_mint &rhs) {
		return lhs.val < rhs.val;
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

	int k; mint A, h;
	cin >> k >> A >> h;

	auto compute = [&](vector<int> v) -> vector<vector<int>> {
		int n = (int) v.size();
		vector<vector<int>> ans(1 << (n - 1), vector<int>(n));
		for (int mask = 0; mask < (1 << (n - 1)); mask++) {
			vector<int> temp = v;
			for (int j = 0; j < n - 1;) {
				int loss_score = temp.size() / 2 + 1;
				for (int k = 0; k < temp.size(); k += 2, j++) {
					if (mask >> j & 1) {
						ans[mask][temp[k]] = loss_score;
						temp[k] = -1;
					} else {
						ans[mask][temp[k + 1]] = loss_score;
						temp[k + 1] = -1;
					}
				}
				temp.erase(remove_if(temp.begin(), temp.end(), [&](int x) { return x == -1; }), temp.end());
			}
			ans[mask][temp[0]] = 1;
		}
		return ans;
	};

	if (k <= 4) {
		int n = (1 << k);
		vector<int> ids(n);
		iota(ids.begin(), ids.end(), 0);
		auto ans = compute(ids);

		for (int mask = 0; mask < (1 << (n - 1)); mask++) {
			mint hash = 0;
			for (int i = 0; i < n; i++) {
				hash += (i + 1) * A.pow(ans[mask][i]);
			}
			if (hash == h) {
				for (auto &x : ans[mask]) {
					cout << x << ' ';
				}
				return cout << '\n', 0;
			}
		}
	} else {
		int n = (1 << 4);

		vector<int> ids(n);
		iota(ids.begin(), ids.end(), 0);
		auto ans = compute(ids);

		for (int mask = 0; mask < (1 << (n - 1)); mask++) {
			for (int i = 0; i < n; i++) {
				if (ans[mask][i] != 1) {
					ans[mask][i] = 2 * ans[mask][i] - 1;
				} else {
					ans[mask][i] = 2;
				}
			}
		}

		vector<pair<mint, int>> hashes0;
		for (int win0 = 0; win0 < n; win0++) {
			for (int mask = 0; mask < (1 << (n - 1)); mask++) {
				if (ans[mask][win0] == 2) {
					mint hash = 0;
					for (int i = 0; i < n; i++) {
						hash += (i + 1) * A.pow(ans[mask][i]);
					}
					hashes0.emplace_back(hash, mask);
				}
			}

			vector<int> ind(hashes0.size());
			iota(ind.begin(), ind.end(), 0);
			sort(ind.begin(), ind.end(), [&](int i, int j) {
				return hashes0[i].first < hashes0[j].first;
			});

			auto binary_search = [&](mint hash) -> int {
				int lo = 0, hi = (int) hashes0.size() - 1;
				while (lo <= hi) {
					int mid = lo + (hi - lo) / 2;
					if (hashes0[ind[mid]].first == hash) {
						return mid;
					} else if (hashes0[ind[mid]].first < hash) {
						lo = mid + 1;
					} else {
						hi = mid - 1;
					}
				}
				return -1;
			};

			for (int mask = 0; mask < (1 << (n - 1)); mask++) {
				int win1 = -1;
				mint hash = 0;
				for (int i = 0; i < n; i++) {
					hash += (i + 1 + 16) * A.pow(ans[mask][i]);
					if (ans[mask][i] == 2) {
						win1 = i + 16;
					}
				}

				mint target_hash0 = hash - (win0 + 1) * (A.pow(2) - A.pow(1));
				mint target_hash1 = hash - (win1 + 1) * (A.pow(2) - A.pow(1));

				int idx = binary_search(h - target_hash0);
				if (idx != -1) {
					idx = hashes0[ind[idx]].second;
					for (int i = 0; i < n; i++) {
						if (i == win0) {
							cout << 1 << ' ';
						} else {
							cout << ans[idx][i] << ' ';
						}
					}
					for (int i = 0; i < n; i++) {
						cout << ans[mask][i] << ' ';
					}
					return cout << '\n', 0;
				}

				idx = binary_search(h - target_hash1);
				if (idx != -1) {
					idx = hashes0[ind[idx]].second;
					for (int i = 0; i < n; i++) {
						cout << ans[idx][i] << ' ';
					}
					for (int i = 0; i < n; i++) {
						if (i + 16 == win1) {
							cout << 1 << ' ';
						} else {
							cout << ans[mask][i] << ' ';
						}
					}
					return cout << '\n', 0;
				}
			}
			hashes0.clear();
		}
	}
	cout << "-1\n";
	return 0;
}