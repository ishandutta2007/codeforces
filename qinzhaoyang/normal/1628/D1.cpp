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
void ckmin(T &A, T B) {A = A < B ? A : B;}
template <typename T>
void ckmax(T &A, T B) {A = A > B ? A : B;}

inline void read(int &x) {scanf("%d", &x);}
inline void print(int x) {printf("%d", x);}
inline void print(int x, char c) {printf("%d%c", x, c);}
inline void read(long long &x) {scanf("%lld", &x);}
inline void print(long long x) {printf("%lld", x);}
inline void print(long long x, char c) {printf("%lld%c", x, c);}

namespace MOD {
	const int P = 1e9 + 7;
	inline int add(int x, int y) {return x + y >= P ? x + y - P : x + y;}
	inline int sub(int x, int y) {return x < y ? x - y + P : x - y;}
	inline int mul(int x, int y) {return (long long)x * y % P;}
	inline void inc(int &x, int y) {x = add(x, y);}
	inline void dec(int &x, int y) {x = sub(x, y);}
	inline void upd(int &x, int y) {x = mul(x, y);}
	inline int Pow(int x, int y) {int r = 1; for (; y; y >>= 1, x = mul(x, x)) if (y & 1) r = mul(r, x); return r;}
};
using namespace MOD;

int T, n, m, k, dp[2010][2010];

int main() {
	int p2 = Pow(2, P - 2);
	for (int i = 1; i <= 2000; i++) {
		dp[i][i] = i;
		for (int j = 1; j < i; j++)
			dp[i][j] = mul(add(dp[i - 1][j - 1], dp[i - 1][j]), p2);
	}
	for (read(T); T; T--) {
		read(n), read(m), read(k);
		printf("%d\n", mul(k, dp[n][m]));
	}
	return 0;
}