#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll ;
typedef double db;
typedef pair<int, int> pii;
 
#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)3e4 + 1;
const int DIF = 250;
const int SZ = DIF * 2 + 9;

int g[N];

int dp[N][SZ];

int main(){
	fastIO;
	int n, d;
	cin >> n >> d;
	int loc;
	for(int i = 1; i <= n; i ++ ){
		cin >> loc;
		g[loc] ++ ;
	}
	for(int i = 0 ; i < N ; i ++ ){
		for(int j = 0 ; j < SZ; j ++ ){
			dp[i][j] = -1;
		}
	}
	dp[d][DIF] = g[d];
	int jump;
	int ans = 0;
	for(int i = d; i < N; i ++ ){
		for(int j = 0 ; j < SZ ; j ++ ){
			if(dp[i][j] == -1){
				continue;
			}
			jump = d + (j - DIF);
			if(i + jump < N){
				dp[i + jump][j] = max(dp[i + jump][j], dp[i][j] + g[i + jump]);
			}
			if(jump > 1 && i + jump - 1 < N){
				dp[i + jump - 1][j - 1] = max(dp[i + jump - 1][j - 1], dp[i][j] + g[i + jump - 1]);
			}
			if(i + jump + 1 < N){
				dp[i + jump + 1][j + 1] = max(dp[i + jump + 1][j + 1], dp[i][j] + g[i + jump + 1]);
			}
		}
	}
	for(int i = 0; i < N ; i ++ ){
		for(int j = 0 ; j < SZ; j ++ ){
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans << "\n";
	return 0;
}