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

const int N = 1010;

int n, c[N];
ll lst1[N][N], lst2[N][N], ans;

int main() {
	read(n);
	lep (i, 1, n) read(c[i]);
	for (int i = 1; i <= n; i += 2) {
		ll t = c[i], lst = 0;
		for (int j = i + 1; j <= n; j++) {
			if (j % 2 == 0) {
				lst1[i][j] = t;
				if (c[j] >= lst) t -= c[j] - lst, lst = 0;
				else lst -= c[j];
			}
			else lst += c[j];
		}
	}
	for (int j = 2; j <= n; j += 2) {
		ll t = c[j], lst = 0;
		for (int i = j - 1; i >= 1; i--) {
			if (i % 2 == 1) {
				lst2[i][j] = t;
				if (c[i] >= lst) t -= c[i] - lst, lst = 0;
				else lst -= c[i];
			}
			else lst += c[i];
		}
	}
	for (int i = 1; i <= n; i += 2)
		for (int j = i + 1; j <= n; j += 2) {
			if (lst1[i][j] < 0 || lst2[i][j] < 0) continue;
			ans += max(min(lst1[i][j], lst2[i][j]), 0ll);
			if (c[i] > lst1[i][j] && c[j] > lst2[i][j]) ans++;
		}
	print(ans, '\n');
	return 0;
}