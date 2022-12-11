#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 1005;
const ll MOD = 998244353;

int dp[N][2 * N + 1][2][2];

int main(){
	fastIO;
	int n, k;
	cin >> n >> k;
	dp[1][1][1][1] = 1;
	dp[1][1][0][0] = 1;
	dp[1][2][0][1] = 1;
	dp[1][2][1][0] = 1;
	int extra;
	for(int i = 2; i <= n;i ++ ){
		for(int j = 1; j <= k; j ++ ){
			for(int up = 0;up < 2; up ++ ){
				for(int down = 0; down < 2; down ++ ){
					for(int cup = 0; cup < 2; cup ++ ){
						for(int cdown = 0; cdown < 2; cdown ++ ){
							extra = 0;
							if(up == cup and down == cdown){
								extra = 0;
							}
							else if(up == cup or down == cdown){
								extra = 1;
								extra -= (cup == cdown);
							}
							else{
								extra = (cup != cdown) + 1;
							}
							dp[i][j + extra][cup][cdown] += dp[i - 1][j][up][down];
							dp[i][j + extra][cup][cdown] %= MOD;
						}
					}
				}
			}
		}
	}
	int ans = 0;
	for(int i = 0;i < 2; i ++ ){
		for(int j = 0;j < 2; j ++ ){
			ans += dp[n][k][i][j];
			ans %= MOD;
		}
	}
	cout << ans << "\n";
	return 0;
}