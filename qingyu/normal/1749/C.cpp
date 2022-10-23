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

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	multiset<int> se;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int k = n; k >= 0; --k) {
		se.clear();
		for (int x : a) se.insert(x);
		bool okk = true;
		for (int j = 1; j <= k; ++j) {
			if (se.empty()) break;
			auto it = se.upper_bound(k - j + 1);
			--it;
			if (it == se.end()) {
				okk = false;
				break;
			}
			if (*it <= k - j + 1) {
				se.erase(it);
				if (!se.empty()) {
					it = se.begin();
					int x = *it;
					se.erase(it);
					se.insert(x + k - j + 1);
				}
			}
			else {
				okk = false;
				break;
			}
		}
		if (okk) {
			cout << k << "\n";
			return;
		}
	}
	throw;
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int T;
	cin >> T;
	while (T--) {
		solve();
	}

}