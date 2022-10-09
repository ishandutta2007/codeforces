#include <bits/stdc++.h>

const int mod = 998244353;
const int N = 1e6 + 50;

inline int inc(int x, int y) { x += y - mod; return x + (x >> 31 & mod); }
inline int dec(int x, int y) { x -= y; return x + (x >> 31 & mod); }
inline int mul(int x, int y) { return 1ll * x * y % mod; }

inline void upd(int &x, int y) { x = inc(x, y); }
inline void dpu(int &x, int y) { x = dec(x, y); }
inline void pud(int &x, int y) { x = mul(x, y); }

inline int fastpow(int x, int p) {
	int r = 1;
	while (p) {
		if (p & 1) pud(r, x);
		pud(x, x);
		p >>= 1;
	}
	return r;
}

int pc[26];
std::vector<int> ch[26];

inline int lowbit(int x) {
	return x & -x;
}

int64_t solve() {
	memset(pc, 0, sizeof pc);
	int n;
	std::string s, t;
	std::cin >> n >> s >> t;
	int SIZ = n + 50;
	std::vector<int> tr(SIZ, 0);
	auto add = [&](int p, int v) {
		p += 10;
		for (; p <= SIZ; p += lowbit(p))
			tr[p] += v;
	};
	auto qry = [&](int p) -> int {
		p += 10;
		int ans = 0;
		for (; p; p -= lowbit(p))
			ans += tr[p];
		return ans;
	};
	if (s < t) {
		return 0;
	}
	int p = 0;
	while (p < n && s[p] == t[p]) ++p;	
	for (int i = 0; i + 1 < p; ++i) {
		if (s[i] > s[i + 1]) {
			return 1;
		}
	}
	if (p == n) {
		return -1;
	}
	std::string r = s;
	std::sort(r.begin(), r.end());
	if (r > t) {
		return -1;
	}

	for (int i = 0; i < 26; ++i) ch[i].clear();
	for (int i = 0; i < n; ++i) {
		int c = s[i] - 'a';
		ch[c].push_back(i);
	}
	int64_t ans = 1e18, cur = 0;
	for (int i = 0; i < n; ++i) {
		int j = 0, c = t[i] - 'a';
		if (c > 0) {
			int64_t min_d = 1e18;
			for (int k = 0; k < c; ++k) {
				if (pc[k] < ch[k].size()) {
					
					int dis = ch[k][pc[k]] + qry(ch[k][pc[k]]) - i;
					if (min_d > dis) {
						min_d = dis;
					}
				}
			}
			ans = std::min(ans, cur + min_d);
		}
		int k = c;
		if (pc[k] >= ch[k].size()) break;
		assert(pc[k] < ch[k].size());
		int real_p = ch[k][pc[k]] + qry(ch[k][pc[k]]);
		add(0, 1);
		add(ch[k][pc[k]], -1);
		cur += real_p - i;
		++pc[k];
		if (cur > ans) break;
	}
	if (ans >= 1e18) ans = -1;
	return ans;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	int t;
	std::cin >> t;
	while (t--) {	
		std::cout << solve() << '\n';	
	}
	return 0;
}