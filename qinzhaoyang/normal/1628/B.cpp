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

int T, n, c[27][27], t[27][27][27], f[27][27];

int main() {
	ios::sync_with_stdio(false);
	for (cin >> T; T; T--) {
		cin >> n; int flag = 0;
		for (int i = 0; i < 26; i++)
			for (int j = 0; j < 26; j++)
				c[i][j] = f[i][j] = 0;
		for (int i = 0; i < 26; i++)
			for (int j = 0; j < 26; j++)
				for (int k = 0; k < 26; k++)
					t[i][j][k] = 0;
		for (int i = 1; i <= n; i++) {
			string s; cin >> s;
			if (s.size() == 1) flag = 1;
			else if (s.size() == 2) {
				int c0 = s[0] - 'a', c1 = s[1] - 'a';
				if (c0 == c1) flag = 1;
				else {
					if (c[c1][c0] || f[c1][c0]) flag = 1;
					c[c0][c1]++;
				}
			}
			else {
				int c0 = s[0] - 'a', c1 = s[1] - 'a', c2 = s[2] - 'a';
				if (c0 == c2) flag = 1;
				else {
					if (t[c2][c1][c0]) flag = 1;
					if (c[c2][c1]) flag = 1;
					f[c0][c1] = 1;
					t[c0][c1][c2] = 1;
				}
			}
		}
		puts(flag ? "YES" : "NO");
	}
	return 0;
}