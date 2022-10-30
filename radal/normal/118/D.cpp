#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define ll long long int 
#define rep(i,l,r) for(int i=l; i<r; i++)
#define repr(i,r,l) for(int i=r; i>=l; --i)
#define pb push_back
#define mp make_pair
#define Y second
#define X first
using namespace std; 
const long long int mod=1e8,N=1e2+10;
ll dp[N][N][2];
int main(){
	ios_base::sync_with_stdio(false);	
	cout.tie(0);
	ll n1,n2,k1,k2;
	cin >> n1 >> n2 >> k1 >> k2;
	dp[1][0][0] = 1;
	dp[0][1][1] = 1;
	dp[0][0][0] =1;
	dp[0][0][1] = 1;
	rep (i,0,n1+1){
		rep (j,0,n2+1){
			if (i+j <= 1) continue;
			if (i > 0){
				dp[i][j][0] += (dp[i-1][j][0]+dp[i-1][j][1])%mod;
				if (i > k1){
					dp[i][j][0] = (dp[i][j][0]-dp [i-k1-1][j][1]+mod)%mod;
				}
			}
			if (j > 0){
				dp[i][j][1] += (dp[i][j-1][0] + dp[i][j-1][1])%mod;
				if (j > k2){
					dp[i][j][1] = (dp[i][j][1]-dp[i][j-k2-1][0]+mod)%mod;
				}
			}
		}
	}
	cout << (dp[n1][n2][0]+dp[n1][n2][1])%mod;
}