#include <stdio.h>
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define puu pair<ull,ull>
#define fi first
#define se second
#define inf 2e9+10
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

ll n, a[N], dp[N][35], pre[N];

void solve() {
	read(n);
	for (int i = 1; i <= n; i++) read(a[i]);
	for (int i = 1; i <= n; i++) dp[i][1] = infll;
	for (int j = 2; j <= 30; j++)
		for (int i = n; i >= 1; i--) {
			int l = i + 1, r = n;
			while (l < r) {
				int mid = (l + r) >> 1;
				if (a[mid] - a[i] > dp[mid][j - 1] + a[i] - a[mid]) r = mid;
				else l = mid + 1;
			}
			dp[i][j] = -1;
			if (i < r - 1 && dp[r - 1][j - 1] != -1) dp[i][j] = max(dp[i][j], min(a[r - 1] - a[i], dp[r - 1][j - 1] + a[i] - a[r - 1]));
			if (i < r && r <= n && dp[r][j - 1] != -1) dp[i][j] = max(dp[i][j], min(a[r] - a[i], dp[r][j - 1] + a[i] - a[r]));
			if (r + 1 <= n && dp[r + 1][j - 1] != -1) dp[i][j] = max(dp[i][j], min(a[r + 1] - a[i], dp[r + 1][j - 1] + a[i] - a[r + 1]));
		}
	pre[1] = 0;
	for (int i = 2; i <= n; i++)
		pre[i] = a[i] == a[i - 1] ? pre[i - 1] + 1 : 0;
	ll ans = 0;
	for (int j = 1; j <= 30; j++)
		for (int i = 1; i <= n; i++)
			if (dp[i][j] != -1) ans = max(ans, pre[i] + j);
	print(n - ans, '\n');
}

int T;

int main() {
	for (read(T); T; T--) solve();
	return 0;
}