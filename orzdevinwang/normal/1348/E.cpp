#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
#define sz(x) ((int) (x).size())
using namespace std;
const int N = 505;
template<typename T> void cmax(T &aa, T bb) { if(aa < bb) aa = bb; }
template<typename T> void cmin(T &aa, T bb) { if(bb < aa) aa = bb; }
int n, m, a[N], b[N], sum;
ll dp[N][N], ans;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	memset(dp, -0x3f, sizeof(dp));
	dp[0][0] = 0;
	L(i, 1, n) {
		cin >> a[i] >> b[i];
		L(j, 0, m - 1) cmax(dp[i][(j + a[i]) % m], dp[i - 1][j] + 
		(j + a[i]) / m + ((sum + m - j) % m + b[i]) / m); 
		
		L(t, 0, m) if(a[i] >= t && b[i] >= m - t) 
			L(j, 0, m - 1) cmax(dp[i][(j + a[i] - t) % m], dp[i - 1][j] + 
		(j + a[i] - t) / m + ((sum + m - j) % m + b[i] - m + t) / m + 1);
		
		(sum += a[i] + b[i]) %= m;
	}
	L(i, 0, m - 1) ans = max(ans, dp[n][i]);
	cout << ans << "\n";
	return 0;
}