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

int T, n, a[N];
vector <int> ans;

void solve(int l, int r) {
	for (int i = l - 3; i >= 1; i -= 2)
		ans.pb(i), ans.pb(i + 1);
	if (l % 2 == 1 && l != 1) ans.pb(1);
	for (int i = r + 1; i + 2 <= n; i += 2)
		ans.pb(i), ans.pb(i - 1);
	if ((n - r) % 2 == 0 && r != n) ans.pb(n - 2);
	puts("YES");
	print((int)ans.size(), '\n');
	if (ans.size()) {
		for (int i : ans)
			print(i, ' ');
		puts("");
	}
}

int main() {
	for (read(T); T; T--) {
		ans.clear();
		read(n);
		for (int i = 1; i <= n; i++) read(a[i]);
		int c = 0;
		for (int i = 1; i <= n; i++) c += a[i] == 1;
		if (c % 2 == 1) {
			puts("NO");
			continue;
		}
		c = 0; int flag = 0;
		for (int i = 1; i <= n; i++) {
			c += a[i] == 1;
			if (!a[i] && c % 2 == 0) {
				solve(i, i);
				flag = 1;
				break;
			}
		}
		if (flag == 1) continue;
		int c0 = 0, lst = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i] == 1) {
				if (c0 > 0 && c0 % 2 == 1) {
					int j = lst, t = i;
					for (; j < t; j += 2)
						ans.pb(j);
					for (j -= 2; j - 2 >= lst; j -= 2)
						ans.pb(j - 2);
					a[lst] = a[i] = 0;
					solve(lst, i);
					flag = 1;
					break;
				}
				lst = i;
			}
			else c0++;
		}
		if (!flag) puts("NO");
	}
	return 0;
}