//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
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

const int l = 3,
	  maxn = 50;
LL dp[maxn][l][l];
LL a[l][l];
int n;

void print(int i){
	for(int j= 0; j < l; j++, cout << endl)
		for(int k = 0; k < l; k++)
			cout << dp[i][j][k] << ' ';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for(int i = 0; i < l; i++)
		for(int j = 0; j < l; j++)
			cin >> a[i][j];
	cin >> n;
	for(int j = 0; j < l; j++)
		for(int k = 0; k < l; k++)
			dp[1][j][k] = min(a[j][k], a[j][3 - j - k] + a[3 - j - k][k]);
	for(int x = 0; x < l; x++)
		for(int j = 0; j < l; j++)
			for(int k = 0; k < l; k++)
				smin(dp[1][j][k], dp[1][j][x] + dp[1][x][k]);
	for(int i = 2; i <= n; i++){
		for(int j = 0; j < l; j++){
			for(int k = 0; k < l; k++) if(j != k){
				int tmp = 3 - j - k;
				dp[i][j][k] = dp[i - 1][j][tmp] + a[j][k] + dp[i - 1][tmp][k];
				smin(dp[i][j][k], dp[i - 1][j][k] + a[j][tmp] + dp[i - 1][k][j] + dp[i - 1][j][k] + a[tmp][k]);
			}
		}
		for(int x = 0; x < l; x++)
			for(int j = 0; j < l; j++)
				for(int k = 0; k < l; k++)
					smin(dp[i][j][k], dp[i][j][x] + dp[i][x][k]);
	}
	cout << dp[n][0][2] << '\n';
	return 0;
}