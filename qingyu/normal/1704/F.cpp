#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 50;
const int mod = 998244353;
 
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

typedef long long ll;

int sg[N], vis[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin >> t;
	auto pre_sg = [&](int n) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 0; j <= i - 2; ++j)
				vis[sg[j] ^ sg[i - j - 2]] = i;
			while (vis[sg[i]] == i) ++sg[i];
		}
	};
	pre_sg(200);
	auto SG = [&](int n) {
		// A002187
		if (n <= 51) return sg[n];
		return sg[n % 34 + 68];
	};
	//for (int i = 1; i <= 1000; ++i)
	//	printf("SG(%d) = %d\n", i, SG(i));
	auto solve = [&](int n, std::string s) {
		int cR = 0, cB = 0;
		for (char ch : s) {
			if (ch == 'R') ++cR;
			else ++cB;
		}
		if (cR != cB) return cR > cB;
		int sum = 0;
		for (int i = 0; i < n; ++i) {
			int j = i;
			while (j + 1 < n && s[j] != s[j + 1]) ++j;
			sum ^= SG(j - i + 1);
			i = j;
		}
		return sum != 0;
	};
	while (t--) {
		int n;
		std::string s;
		std::cin >> n >> s;
		std::cout << (solve(n, s) ? "Alice" : "Bob") << '\n';
	}
	return 0;
}