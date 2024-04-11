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

int T, n;
vector <int> a[N], ans;

int main() {
	for (read(T); T; T--) {
		read(n);
		for (int i = 0; i <= n; i++) a[i].clear();
		for (int i = 1, x; i <= n; i++)
			read(x), a[x].push_back(i);
		for (int i = 0; i <= n; i++)
			reverse (a[i].begin(), a[i].end());
		ans.clear();
		int lst = 0;
		while (1) {
			int p = -1;
			if (!a[0].size()) {
				for (int i = lst + 1; i <= n; i++)
					ans.push_back(0);
				break;
			}
			while (a[p + 1].size()) ++p;
			int mx = 0;
			for (int i = 0; i <= p; i++)
				mx = max(mx, a[i].back());
			ans.push_back(p + 1);
			lst = mx;
			for (int i = 0; i <= p; i++)
				while (a[i].size() && a[i].back() <= lst)
					a[i].pop_back();
		}
		print((int)ans.size(), '\n');
		for (int x : ans) print(x, ' ');
		puts("");
	}
	return 0;
}