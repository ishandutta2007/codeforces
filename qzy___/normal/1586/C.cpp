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

const int N = 1e6 + 10;

struct BIT {
	long long s[N]; int n;
	void init(int x) {
		n = x;
		for (int i = 1; i <= n; i++) s[i] = 0;
	}
	void Mdf(int x, long long v) {
		for (; x <= n; x += x & (-x)) s[x] += v;
	}
	long long Query(int x) {
		long long ret = 0;
		for (; x; x -= x & (-x)) ret += s[x];
		return ret;
	}
	long long Qry(int l, int r) {
		return Query(r) - Query(l - 1);
	}
}	bit;

int n, m, q;

int main() {
	read(n), read(m);
	bit.init(m);
	vector <vector<char> > b(n + 1, vector<char>(m + 1));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf(" %c", &b[i][j]);
	for (int i = 1; i < n; i++)
		for (int j = 2; j <= m; j++)
			if (b[i][j] == 'X' && b[i + 1][j - 1] == 'X')
				bit.Mdf(j, 1);
	read(q);
	for (int i = 1; i <= q; i++) {
		int x1, x2; read(x1), read(x2);
		if (x1 == x2) puts("Yes");
		else {
			int t = bit.Qry(x1 + 1, x2);
			if (t) puts("No");
			else puts("Yes");
		}
	}
	return 0;
}