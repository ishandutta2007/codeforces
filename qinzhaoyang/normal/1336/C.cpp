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

const int P = 998244353, N = 3010;

int n, m, dp[N][N], ans;
char a[N], b[N];

int main() {
	scanf("%s%s", a + 1, b + 1);
	n = strlen(a + 1), m = strlen(b + 1);
	for (int i = 1; i <= m; i++)
		if (a[1] == b[i]) dp[i][i] = 2;
	for (int i = m + 1; i <= n; i++)
		dp[i][i] = 2;
	for (int len = 1; len < n; len++)
		for (int i = 1; i + len - 1 <= n; i++) {
			int j = i + len - 1;
			// -> dp,i-1,j
			if (i > 1 && (a[len + 1] == b[i - 1] || i - 1 > m))
				(dp[i-1][j] += dp[i][j]) %= P;
			// -> dp,i,j+1;
			if (j + 1 > m || b[j + 1] == a[len + 1])
				(dp[i][j+1] += dp[i][j]) %= P;
		}
	for (int j = m; j <= n; j++)
		(ans += dp[1][j]) %= P;
	print(ans, '\n');
	return 0;
}