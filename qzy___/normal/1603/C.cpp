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
	const int P = 998244353;
	inline int add(int x, int y) {return x + y >= P ? x + y - P : x + y;}
	inline int sub(int x, int y) {return x < y ? x - y + P : x - y;}
	inline int mul(int x, int y) {return (long long)x * y % P;}
	inline void inc(int &x, int y) {x = add(x, y);}
	inline void dec(int &x, int y) {x = sub(x, y);}
	inline void upd(int &x, int y) {x = mul(x, y);}
};
using namespace MOD;

const int N = 1e5 + 10;

int n, a[N];
vector <int> b[2];
vector <int> f[2];

void solve() {
	read(n);
	for (int i = 1; i <= n; i++)
		read(a[i]);
	int ans = 0;
	b[0].clear(), b[1].clear();
	f[0].clear(), f[1].clear();
	b[0].push_back(1e9);
	f[0].push_back(0);
	for (int k = 1; k <= n; k++) {
		int up = (k & 1);
		b[up].clear(), f[up].clear();
		int t = a[k];
		for (int i = 1, j; i <= t; i = j + 1) {
			j = min(t, t / (t / i));
			b[up].push_back(i);
			if (i < j) b[up].push_back(j);
		}
		for (int i = 0; i < b[up].size(); i++)
			f[up].push_back(0);
		int s = 0;
		for (int j = 0; j < b[up].size(); j++) {
			int t1 = ceil(a[k] * 1.0 / b[up][j]);
			int t2 = a[k] / t1;
			//cout << i << " " << j << " " << b[i][j] << " " << t1 << " " << t2 << endl;
			while (s + 1 < b[up ^ 1].size() && b[up ^ 1][s + 1] <= t2)
				s++;
			f[up][j] = add(f[up ^ 1][s], mul(k, t1 - 1));
		}
		inc(ans, f[up].back());
	}
	print(ans, '\n');
}

int T;

int main() {
	for (read(T); T; T--) solve();
	return 0;
}