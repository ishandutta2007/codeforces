//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()

const int maxn = 200 + 10;
LD dp[maxn][maxn][maxn*2],
   p[maxn];
int a[maxn];
int n, l, bag;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> l >> bag;
	for(int i = 0; i < n; i++)
		cin >> p[i], p[i] /= 100.;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	dp[0][0][bag+200] = 1;
	for(int i = 0; i < n; i++){
		for(int j = 0; j <= i; j++){
			for(int k = -200; k <= 200; k++){
				int kk = k + a[i];
				smin(kk, 200);
				dp[i + 1][j][k+200] += dp[i][j][k+200] * (1. - p[i]);
				dp[i + 1][j + 1][kk+200] += dp[i][j][k+200] * p[i];
			}
		}
	}
	LD ans = 0;
	for(int j = l; j <= n; j++)
		for(int k = 0; k <= 200; k++)
			ans += dp[n][j][k+200];
	cout.precision(10);
	cout << fixed << ans << endl;
	return 0;
}