#include <stdio.h>
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define puu pair<ull,ull>
#define fi first
#define se second
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define mset(a, b) memset(a, b, sizeof a)
#define lep(i, j, k) for (int i = (j); i <= (k); i++)
#define rep(i, j, k) for (int i = (j); i >= (k); i--)
#define Lep(i, j, k) for (int i = (j); i < (k); i++)
#define Rep(i, j, k) for (int i = (j); i > (k); i--)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

template <typename T>
inline void ckmin(T &A, T B) {A = A < B ? A : B;}
template <typename T>
inline void ckmax(T &A, T B) {A = A > B ? A : B;}

inline void read(int &x) {scanf("%d", &x);}
inline void print(int x) {printf("%d", x);}
inline void print(int x, char c) {printf("%d%c", x, c);}
inline void read(long long &x) {scanf("%lld", &x);}
inline void print(long long x) {printf("%lld", x);}
inline void print(long long x, char c) {printf("%lld%c", x, c);}

namespace MOD {
	const int P = 998244353;
	inline int add(int x, int y) {return x + y >= P ? x + y - P : x + y;}
	inline int sub(int x, int y) {return x < y ? x - y + P : x - y;}
	inline int mul(int x, int y) {return (long long)x * y % P;}
	inline void inc(int &x, int y) {x = add(x, y);}
	inline void dec(int &x, int y) {x = sub(x, y);}
	inline void upd(int &x, int y) {x = mul(x, y);}
	inline int Pow(int x, int y) {int r = 1; for (; y; y >>= 1, x = mul(x, x)) if (y & 1) r = mul(r, x); return r;}
};
using namespace MOD;

const int N = 2e5 + 10;
const int M = 2e5;

struct BIT {
	int s[N]; int n;
	void Mdf(int x, int v) {
		for (; x <= n; x += x & (-x)) inc(s[x], v);
	}
	long long Query(int x) {
		int ret = 0;
		for (; x; x -= x & (-x)) inc(ret, s[x]);
		return ret;
	}
	int Qry(int l, int r) {
		return sub(Query(r), Query(l - 1));
	}
}	bit;

int n, m, s[N], t[N], pw[N], ipw[N], c[N], ml = 1, ans = 0;

int main() {
	read(n), read(m), bit.n = M;
	for (int i = 1; i <= n; i++) read(s[i]), c[s[i]]++;
	for (int i = 1; i <= m; i++) read(t[i]);
	pw[0] = ipw[0] = 1;
	for (int i = 1; i <= n; i++) pw[i] = mul(pw[i - 1], i);
	ipw[n] = Pow(pw[n], P - 2);
	for (int i = n - 1; i >= 1; i--) ipw[i] = mul(ipw[i + 1], i + 1);
	for (int i = 1; i <= M; i++) if (c[i]) bit.Mdf(i, c[i]);
	for (int i = 1; i <= M; i++) ml = mul(ml, pw[c[i]]);
	ans = mul(pw[n], Pow(ml, P - 2));
	for (int i = 1; i <= n; i++) {
		if (i > m) {
			//cout << ml << " " << pw[n - i + 1] << endl;
			ans = sub(ans, mul(Pow(ml, P - 2), pw[n - i + 1]));
			break;
		}
		//cout << "Run " << endl;
		//cout << ml << " " << bit.Qry(t[i] + 1, M) << endl;
		//cout << mul(mul(pw[n - i], bit.Qry(t[i] + 1, M)), Pow(ml, P - 2)) << endl;
		ans = sub(ans, mul(mul(pw[n - i], bit.Qry(t[i] + 1, M)), Pow(ml, P - 2)));
		if (c[t[i]] == 0) break;
		bit.Mdf(t[i], P - c[t[i]]);
		ml = mul(ml, ipw[c[t[i]]]);
		c[t[i]]--;
		ml = mul(ml, pw[c[t[i]]]);
		if (c[t[i]] > 0) bit.Mdf(t[i], c[t[i]]);
		if (i == n && n == m) ans = sub(ans, 1);
		//for (int j = 1; j <= 5; j++)
		//	cout << bit.Qry(j, j) << " ";
		//cout << endl;
	}
	printf("%d\n", ans);
	return 0;
}