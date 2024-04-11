#include<bits/stdc++.h>
using namespace std;
#define L(i, j, k) for(int i = (j), i##E = (k); i <= i##E; i++) 
#define R(i, j, k) for(int i = (j), i##E = (k); i >= i##E; i--) 
#define ll long long 
#define db double
#define mkp make_pair 
const int N = 1e5 + 7;
int n, m, dp[61][N];
ll a[N], Maxa;
void myMin(int &x, int y) {
	if(x > y) x = y;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	L(i, 1, n) cin >> a[i], Maxa = max(Maxa, a[i]);
	L(i, 1, n) a[i] = Maxa - a[i];
	memset(dp, 0x3f, sizeof(dp));
	dp[0][0] = 0;
	L(i, 0, 59) {
		ll tmp = (i == 0 ? 0 : (1LL << i) - 1);
		sort(a + 1, a + n + 1, [&](ll x, ll y) { return (x & tmp) > (y & tmp); });
		int cnt = 0, all = 0;
		L(j, 1, n) all += (a[j] >> i & 1);
		L(j, 0, n) {
			if(j) cnt += (a[j] >> i & 1); //  cnt  0
			myMin(dp[i + 1][cnt], dp[i][j] + all + j - cnt * 2); // choose zero ! 
			myMin(dp[i + 1][all + j - cnt], dp[i][j] + n - all - j + cnt * 2); // choose one ! 
		}
	} 
	cout << dp[60][0] << endl;
	return 0;
}