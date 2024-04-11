#include <bits/stdc++.h>
using namespace std;

#include <algorithm>
#include <cassert>
#include <numeric>
#include <string>
#include <vector>

namespace atcoder {

namespace internal {

std::vector<int> sa_naive(const std::vector<int>& s) {
	int n = int(s.size());
	std::vector<int> sa(n);
	std::iota(sa.begin(), sa.end(), 0);
	std::sort(sa.begin(), sa.end(), [&](int l, int r) {
		if(l == r) return false;
		while(l < n && r < n) {
			if(s[l] != s[r]) return s[l] < s[r];
			l++;
			r++;
		}
		return l == n;
	});
	return sa;
}

std::vector<int> sa_doubling(const std::vector<int>& s) {
	int n = int(s.size());
	std::vector<int> sa(n), rnk = s, tmp(n);
	std::iota(sa.begin(), sa.end(), 0);
	for(int k = 1; k < n; k *= 2) {
		auto cmp = [&](int x, int y) {
			if(rnk[x] != rnk[y]) return rnk[x] < rnk[y];
			int rx = x + k < n ? rnk[x + k] : -1;
			int ry = y + k < n ? rnk[y + k] : -1;
			return rx < ry;
		};
		std::sort(sa.begin(), sa.end(), cmp);
		tmp[sa[0]] = 0;
		for(int i = 1; i < n; i++) {
			tmp[sa[i]] = tmp[sa[i - 1]] + (cmp(sa[i - 1], sa[i]) ? 1 : 0);
		}
		std::swap(tmp, rnk);
	}
	return sa;
}

// SA-IS, linear-time suffix array construction
// Reference:
// G. Nong, S. Zhang, and W. H. Chan,
// Two Efficient Algorithms for Linear Time Suffix Array Construction
template <int THRESHOLD_NAIVE = 10, int THRESHOLD_DOUBLING = 40>
std::vector<int> sa_is(const std::vector<int>& s, int upper) {
	int n = int(s.size());
	if(n == 0) return {};
	if(n == 1) return {0};
	if(n == 2) {
		if(s[0] < s[1]) {
			return {0, 1};
		} else {
			return {1, 0};
		}
	}
	if(n < THRESHOLD_NAIVE) {
		return sa_naive(s);
	}
	if(n < THRESHOLD_DOUBLING) {
		return sa_doubling(s);
	}

	std::vector<int> sa(n);
	std::vector<bool> ls(n);
	for(int i = n - 2; i >= 0; i--) {
		ls[i] = (s[i] == s[i + 1]) ? ls[i + 1] : (s[i] < s[i + 1]);
	}
	std::vector<int> sum_l(upper + 1), sum_s(upper + 1);
	for(int i = 0; i < n; i++) {
		if(!ls[i]) {
			sum_s[s[i]]++;
		} else {
			sum_l[s[i] + 1]++;
		}
	}
	for(int i = 0; i <= upper; i++) {
		sum_s[i] += sum_l[i];
		if(i < upper) sum_l[i + 1] += sum_s[i];
	}

	auto induce = [&](const std::vector<int>& lms) {
		std::fill(sa.begin(), sa.end(), -1);
		std::vector<int> buf(upper + 1);
		std::copy(sum_s.begin(), sum_s.end(), buf.begin());
		for(auto d : lms) {
			if(d == n) continue;
			sa[buf[s[d]]++] = d;
		}
		std::copy(sum_l.begin(), sum_l.end(), buf.begin());
		sa[buf[s[n - 1]]++] = n - 1;
		for(int i = 0; i < n; i++) {
			int v = sa[i];
			if(v >= 1 && !ls[v - 1]) {
				sa[buf[s[v - 1]]++] = v - 1;
			}
		}
		std::copy(sum_l.begin(), sum_l.end(), buf.begin());
		for(int i = n - 1; i >= 0; i--) {
			int v = sa[i];
			if(v >= 1 && ls[v - 1]) {
				sa[--buf[s[v - 1] + 1]] = v - 1;
			}
		}
	};

	std::vector<int> lms_map(n + 1, -1);
	int m = 0;
	for(int i = 1; i < n; i++) {
		if(!ls[i - 1] && ls[i]) {
			lms_map[i] = m++;
		}
	}
	std::vector<int> lms;
	lms.reserve(m);
	for(int i = 1; i < n; i++) {
		if(!ls[i - 1] && ls[i]) {
			lms.push_back(i);
		}
	}

	induce(lms);

	if(m) {
		std::vector<int> sorted_lms;
		sorted_lms.reserve(m);
		for(int v : sa) {
			if(lms_map[v] != -1) sorted_lms.push_back(v);
		}
		std::vector<int> rec_s(m);
		int rec_upper = 0;
		rec_s[lms_map[sorted_lms[0]]] = 0;
		for(int i = 1; i < m; i++) {
			int l = sorted_lms[i - 1], r = sorted_lms[i];
			int end_l = (lms_map[l] + 1 < m) ? lms[lms_map[l] + 1] : n;
			int end_r = (lms_map[r] + 1 < m) ? lms[lms_map[r] + 1] : n;
			bool same = true;
			if(end_l - l != end_r - r) {
				same = false;
			} else {
				while(l < end_l) {
					if(s[l] != s[r]) {
						break;
					}
					l++;
					r++;
				}
				if(l == n || s[l] != s[r]) same = false;
			}
			if(!same) rec_upper++;
			rec_s[lms_map[sorted_lms[i]]] = rec_upper;
		}

		auto rec_sa =
		    sa_is<THRESHOLD_NAIVE, THRESHOLD_DOUBLING>(rec_s, rec_upper);

		for(int i = 0; i < m; i++) {
			sorted_lms[i] = lms[rec_sa[i]];
		}
		induce(sorted_lms);
	}
	return sa;
}

}  // namespace internal

std::vector<int> suffix_array(const std::vector<int>& s, int upper) {
	assert(0 <= upper);
	for(int d : s) {
		assert(0 <= d && d <= upper);
	}
	auto sa = internal::sa_is(s, upper);
	return sa;
}

template <class T>
std::vector<int> suffix_array(const std::vector<T>& s) {
	int n = int(s.size());
	std::vector<int> idx(n);
	iota(idx.begin(), idx.end(), 0);
	sort(idx.begin(), idx.end(), [&](int l, int r) { return s[l] < s[r]; });
	std::vector<int> s2(n);
	int now = 0;
	for(int i = 0; i < n; i++) {
		if(i && s[idx[i - 1]] != s[idx[i]]) now++;
		s2[idx[i]] = now;
	}
	return internal::sa_is(s2, now);
}

std::vector<int> suffix_array(const std::string& s) {
	int n = int(s.size());
	std::vector<int> s2(n);
	for(int i = 0; i < n; i++) {
		s2[i] = s[i];
	}
	return internal::sa_is(s2, 255);
}

// Reference:
// T. Kasai, G. Lee, H. Arimura, S. Arikawa, and K. Park,
// Linear-Time Longest-Common-Prefix Computation in Suffix Arrays and Its
// Applications
template <class T>
std::vector<int> lcp_array(const std::vector<T>& s,
                           const std::vector<int>& sa) {
	int n = int(s.size());
	assert(n >= 1);
	std::vector<int> rnk(n);
	for(int i = 0; i < n; i++) {
		rnk[sa[i]] = i;
	}
	std::vector<int> lcp(n - 1);
	int h = 0;
	for(int i = 0; i < n; i++) {
		if(h > 0) h--;
		if(rnk[i] == 0) continue;
		int j = sa[rnk[i] - 1];
		for(; j + h < n && i + h < n; h++) {
			if(s[j + h] != s[i + h]) break;
		}
		lcp[rnk[i] - 1] = h;
	}
	return lcp;
}

std::vector<int> lcp_array(const std::string& s, const std::vector<int>& sa) {
	int n = int(s.size());
	std::vector<int> s2(n);
	for(int i = 0; i < n; i++) {
		s2[i] = s[i];
	}
	return lcp_array(s2, sa);
}

// Reference:
// D. Gusfield,
// Algorithms on Strings, Trees, and Sequences: Computer Science and
// Computational Biology
template <class T>
std::vector<int> z_algorithm(const std::vector<T>& s) {
	int n = int(s.size());
	if(n == 0) return {};
	std::vector<int> z(n);
	z[0] = 0;
	for(int i = 1, j = 0; i < n; i++) {
		int& k = z[i];
		k = (j + z[j] <= i) ? 0 : std::min(j + z[j] - i, z[i - j]);
		while(i + k < n && s[k] == s[i + k]) k++;
		if(j + z[j] < i + z[i]) j = i;
	}
	z[0] = n;
	return z;
}

std::vector<int> z_algorithm(const std::string& s) {
	int n = int(s.size());
	std::vector<int> s2(n);
	for(int i = 0; i < n; i++) {
		s2[i] = s[i];
	}
	return z_algorithm(s2);
}

}  // namespace atcoder

#define rep(i, l, r) for(int i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
template <class T>
void chmin(T& x, T y) { x = min(x, y); }
using ll = long long;

int main() {
	int n, m;
	ll k;
	string s;
	cin >> n >> m >> k >> s;
	const int N = 500000;
	vector nxt(N, vector(26, -1));
	vector val(N, '?');
	vector bef(N, 0);
	int now = 0;
	rep(i, 0, n) {
		int x = 0;
		rep(j, i, n) {
			auto& nx = nxt[x][s[j] - 'a'];
			if(nx == -1) {
				nx = ++now;
				bef[now] = x;
				val[now] = s[j];
			}
			x = nx;
		}
	}

	vector<int> order;
	auto dfs = [&](auto dfs, int now) -> void {
		rep(i, 0, 26) {
			const auto& nx = nxt[now][i];
			if(nx != -1) {
				order.push_back(nx);
				dfs(dfs, nx);
			}
		}
	};
	dfs(dfs, 0);

	auto get_string = [&](int now) {
		string res = "";
		while(now) {
			res.push_back(val[now]);
			now = bef[now];
		}
		reverse(all(res));
		return res;
	};

	auto judge = [&](int mid) -> bool {
		string t = get_string(order[mid]);
		vector dp(m + 1, vector(n + 1, 0ll));
		auto z = atcoder::z_algorithm(t + s);
		vector lcp(n, 0);
		rep(i, 0, n) lcp[i] = min(z[i + t.size()], (int)t.size() - 1);
		dp[0][0] = 1;
		rep(i, 0, m) {
			rep(j, 0, n) {
				if(s[j + lcp[j]] >= t[lcp[j]]) {
					dp[i + 1][j + lcp[j] + 1] += dp[i][j];
					chmin(dp[i + 1][j + lcp[j] + 1], k);
				}
			}
			rep(j, 1, n + 1) {
				dp[i + 1][j] += dp[i + 1][j - 1];
				chmin(dp[i + 1][j], k);
			}
		}
		return dp.back()[n] >= k;
	};

	int ok = 0, ng = order.size(), mid;
	while(mid = (ok + ng) >> 1, abs(ok - ng) > 1)
		(judge(mid) ? ok : ng) = mid;

	cout << get_string(order[ok]) << '\n';

	return 0;
}