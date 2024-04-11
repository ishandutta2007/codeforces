#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define sz(a) ((int) (a).size())
#define vi vector < int >
#define me(a, x) memset(a, x, sizeof(a))
#define ull unsigned long long 
using namespace std;
const int N = 127;
ll dp[N][N];
ll t, x, y;
ll calc(ll w, int x, int y) {
	w -= x + y;
	if(w < 0) return 0;
	me(dp, 0);
	dp[0][0] = w;
	L(i, 0, x) {
		L(j, 0, y) {
			dp[i + 1][j] += (dp[i][j]) / 2;
			dp[i][j + 1] += (dp[i][j] + 1) / 2;
		}
	}
	return dp[x][y];
}
void Main() {
	cin >> t >> x >> y;
	if(calc(t + 1, x, y) - calc(t, x , y)) cout << "YES\n";
	else cout << "NO\n";
}
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) Main();
	return 0;
}