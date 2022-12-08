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

const int P = 31607, N = 22;

inline int add(int x, int y) {return x + y >= P ? x + y - P : x + y;}
inline int sub(int x, int y) {return x < y ? x - y + P : x - y;}
inline int mul(int x, int y) {return x * y % P;}

void exgcd(ll a, ll b, ll &x, ll &y) {
	if (b == 0) return x = 1, y = 0, void();
	exgcd(b, a % b, y, x), y -= (a / b) * x;
}
ll Inv(ll a, ll b) {
	ll x, y; exgcd(a, b, x, y);
	return (x % b + b) % b;
}

int n, p[N][N];
int s[1 << N][N], sl[N];

int ste[1 << N];

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++)
		ste[1 << i - 1] = i;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++)
		cin >> p[i][j], p[i][j] = mul(p[i][j], Inv(10000, P));
	//clock_t st = clock();
	for (int j = 1; j <= n; j++)
		for (int i = 0; i < (1 << n); i++) {
			s[i][j] = 1;
			if (i == 0) continue;
			int t = (i & (-i));
			s[i][j] = mul(s[i - t][j], p[j][ste[t]]);
			//for (int k = 1; k <= n; k++)
			//	if ((i >> (k - 1)) & 1) s[i][j] = mul(s[i][j], p[j][k]);
		}
	for (int j = 1; j <= n; j++) {
		sl[j] = 1;
		for (int i = 1; i <= n; i++)
			sl[j] = mul(sl[j], p[i][j]);
	}
	int ans = 0;
	for (int d = 0; d <= 1; d++)
		for (int ad = 0; ad <= 1; ad++) {
			//cout << d << " " << ad << endl;
			for (int b = 0; b < (1 << n); b++) {
				int ct = d + ad;
				for (int i = 1; i <= n; i++)
					if ((b >> (i - 1)) & 1) ct++;
				int dp[2][2] = {0};
				int P = 1;
				for (int i = 1; i <= n; i++)
					if ((b >> (i - 1)) & 1) P = mul(P, sl[i]);
				if (d)
					for (int i = 1; i <= n; i++) {
						if ((b >> (i - 1)) & 1) continue;
						P = mul(P, p[i][i]);
					}
				if (ad)
					for (int j = 1; j <= n; j++) {
						if ((b >> (j - 1)) & 1) continue;
						if (d && n % 2 == 1 && j == n / 2 + 1) continue;
						P = mul(P, p[n - j + 1][j]);
					}
				dp[0][(ct % 2)] = P;
				dp[0][!(ct % 2)] = 0;
				for (int i = 1; i <= n; i++) {
					if (i != 1) {
						dp[0][0] = dp[1][0];
						dp[0][1] = dp[1][1];
						dp[1][0] = dp[1][1] = 0;
					}
					int B = b;
					if (d) B = (B | (1 << i - 1));
					if (ad) B = (B | (1 << (n - i + 1 - 1)));
					B = (1 << n) - 1 - B;
					P = s[B][i];
					dp[1][0] = add(mul(P, dp[0][1]), dp[0][0]);
					dp[1][1] = add(mul(P, dp[0][0]), dp[0][1]);
				}
				if (d == 0 && ad == 0 && b == 0) dp[1][0] = sub(dp[1][0], 1);
				ans = add(ans, sub(dp[1][1], dp[1][0]));
			}
		}
	cout << ans << endl;
	//cout << ((double)clock() - (double)st) / CLOCKS_PER_SEC << endl;
	return 0;
}