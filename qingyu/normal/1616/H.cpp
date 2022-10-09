#include <bits/stdc++.h>

const int N = 1e6 + 50;
const int mod = 998244353;

inline int inc(int x, int y) { x += y - mod; return x + (x >> 31 & mod); } 
inline int dec(int x, int y) { x -= y; return x + (x >> 31 & mod); }
inline int mul(int x, int y) { return 1ll * x * y % mod; }

inline void upd(int &x, int y) { x = inc(x, y); }
inline void dpu(int &x, int y) { x = dec(x, y); }
inline void pud(int &x, int y) { x = mul(x, y); }

int n, x, pw2[N];

int comb(int l, int r) {
	int x = dec(pw2[l], 1);
	int y = dec(pw2[r], 1);
	return mul(x, y);
}

void output(auto &a) {
	for (int x : a) printf("%d, ", x);
}

int solve(std::vector<int> l, std::vector<int> r, int k) {

	if (l.empty() || r.empty()) return 0;
	if (k == -1) {
		if (!l.empty() && !r.empty()) {
			return comb(l.size(), r.size());
		}
		else return 0;
	}
	std::vector<int> l0, l1, r0, r1;
	for (int x : l)
		if (x >> k & 1)
			l1.push_back(x);
		else 
			l0.push_back(x);
	for (int x : r)
		if (x >> k & 1)
			r1.push_back(x);
		else 
			r0.push_back(x);
	if (x >> k & 1) {
		int y0 = solve(l1, r0, k - 1);
		int y1 = solve(l0, r1, k - 1);
		int ans = 0; 
		upd(ans, y0); // l0, r1
		upd(ans, mul(pw2[l0.size()] - 1, y0)); // r1 empty, l0, r0, r1 non empty
		upd(ans, mul(pw2[r1.size()] - 1, y0)); // l0 empty, l1, r0, r1 non empty
		upd(ans, y1); // l1, r0
		upd(ans, mul(y1, pw2[r0.size()] - 1)); // l1
		upd(ans, mul(y1, pw2[l1.size()] - 1)); // r0
		// l0, r0
		upd(ans, mul(pw2[l0.size()] - 1, pw2[r0.size()] - 1));
		upd(ans, mul(pw2[l1.size()] - 1, pw2[r1.size()] - 1));
		upd(ans, mul(y0, y1)); // all non-empty
		return ans;
	}
	else {
		int ans = inc(solve(l0, r0, k - 1), solve(l1, r1, k - 1));
		return ans;
	}
}

int solve(std::vector<int> a, int k) {
	if (a.empty()) return 0;

	if (k == -1) {
		return dec(pw2[a.size()], 1);
	}
	if (x >> k & 1) {
		std::vector<int> x0, x1;
		for (int x : a)
			if (x >> k & 1)
				x1.push_back(x);
			else
				x0.push_back(x);
		int ans = inc(dec(pw2[x0.size()], 2), pw2[x1.size()]);
		upd(ans, solve(x0, x1, k - 1));
		return ans;
	}
	else {
		std::vector<int> x0, x1;
		for (int x : a)
			if (x >> k & 1)
				x1.push_back(x);
			else 
				x0.push_back(x);
		return inc(solve(x0, k - 1), solve(x1, k - 1));
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::cin >> n >> x;
	std::vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	pw2[0] = 1;
	for (int i = 1; i <= n; ++i)
		pw2[i] = mul(2, pw2[i - 1]);
	std::cout << solve(a, 30);
}