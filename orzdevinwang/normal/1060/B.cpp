#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 6e5 + 7;
void Min(int &x, int y) {
	if(x > y) x = y;
}
void Max(int &x, int y) {
	if(x < y) x = y;
}
ll n, ans;
int dp[N][2];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	ll now = 1;
	memset(dp, -0x3f, sizeof(dp));
	dp[0][0] = 0;
	L(i, 0, 12) {
		int t = ( n / now ) % 10;
		if(t) Max(dp[i + 1][0], dp[i][1] + (t - 1));
		Max(dp[i + 1][0], dp[i][0] + t);

		t += 10;
		Max(dp[i + 1][1], dp[i][1] + (t - 1));
		if(t <= 18) Max(dp[i + 1][1], dp[i][0] + t);
		now *= 10;
	}
	cout << dp[13][0] << endl;
	return 0;
}