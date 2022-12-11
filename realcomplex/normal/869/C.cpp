#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll mod = 998244353;
const int N = 5005;
ll dp[N][N];//i,j how to connect i,j diffrent bridges

void calc(){
	for(int j = 0;j<=5000;j++){
		for(int i = 0;i<=5000;i++){
			if(i == 0||j==0)dp[j][i] = 1;
			else dp[j][i] = (dp[j-1][i]+(i*(dp[j-1][i-1])))%mod;
		}
	}
}

int main(){
	calc();
	int a,b,c;
	cin >> a >> b >> c;
	ll ans =(((dp[a][b]*dp[b][c])%mod)*dp[a][c])%mod;
	cout << ans;
	return 0;
}