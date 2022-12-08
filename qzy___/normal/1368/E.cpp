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

const int N = 2e5 + 10;

int T, n, m, vis[N];
vector <int> G[N];

int main() {
	for (read(T); T; T--) {
		read(n), read(m);
		lep (i, 1, n) vis[i] = 0, G[i].clear();
		lep (i, 1, m) {
			int x, y; read(x), read(y);
			G[y].pb(x);
		}
		lep (i, 1, n) {
			for (int j : G[i]) {
				if (vis[j]) continue;
				for (int k : G[j]) {
					if (vis[k]) continue;
					vis[i] = 1;
					if (vis[i]) break;
				}
				if (vis[i]) break;
			}
		}
		int ans = 0;
		lep (i, 1, n) ans += vis[i];
		print(ans, '\n');
		lep (i, 1, n) if (vis[i]) print(i, ' '); puts("");
	}
	return 0;
}