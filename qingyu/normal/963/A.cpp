#include <bits/stdc++.h>

using namespace std;

#define QINGYU_LOCAL
#ifdef QINGYU_LOCAL
#define debug(x) \
        cerr << "Func " << __FUNCTION__ << ", " << "L" << __LINE__ << ": " << #x << " = " << x << '\n'
#else
#define debug(x) 0
#endif

const int mod = 1e9 + 9;

inline int inc(int x, int y) { x += y - mod; return x + (x >> 31 & mod); }
inline int dec(int x, int y) { x -= y; return x + (x >> 31 & mod); }  
inline int mul(int x, int y) { return 1ll * x * y % mod; }

inline void upd(int &x, int y) { x = inc(x, y); }
inline void dpu(int &x, int y) { x = dec(x, y); }
inline void pud(int &x, int y) { x = mul(x, y); }

inline int fastpow(int x, int64_t p) {
	int r = 1;
	while (p) {
		if (p & 1) pud(r, x);
		pud(x, x);
		p >>= 1;
	}
	return r;
}

const int N = 1e5 + 50;

int s[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, a, b, k;
	cin >> n >> a >> b >> k;
	string str;
	cin >> str;
	for (int i = 0; i < k; ++i) {
		s[i] = (str[i] == '+' ? 1 : -1);
	}
	int sum = 0;
	for (int i = 0; i < k; ++i) {
		if (str[i] == '+') {
			upd(sum, mul(fastpow(b, i), fastpow(a, n - i)));
		}
		else {
			dpu(sum, mul(fastpow(b, i), fastpow(a, n - i)));
		}
	}
	int w = fastpow(mul(b, fastpow(a, mod - 2)), k);
	int bound = (n + 1) / k - 1;
	int ans = 0;
	if (w == 1) {
		ans = mul(sum, bound + 1);
	}
	else {
		ans = mul(dec(1, fastpow(w, bound + 1)), fastpow(dec(1, w), mod - 2));
		pud(ans, sum);
	}
	cout << ans << '\n';
}