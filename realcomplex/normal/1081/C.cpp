#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll ;
typedef double db;
typedef pair<int, int> pii;
 
#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 2005;
const int MOD = 998244353;

int dp[N][N];

void add(int &a, int b){
	a += b;
	a %= MOD;
}

int multi(int a, int b){
	return (1ll * a * b) % MOD;
}

int main(){
	fastIO;
	int n, m, k;
	cin >> n >> m >> k;
	dp[1][0] = m;
	for(int i = 1; i < n; i ++ ){
		for(int j = 0 ; j <= k ; j ++ ){
			add(dp[i + 1][j], dp[i][j]);
			if(j < k){
				add(dp[i + 1][j + 1], multi(dp[i][j], m - 1));
			}
		}
	}
	cout << dp[n][k];
	return 0;
}