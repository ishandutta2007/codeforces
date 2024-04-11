#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB emplace_back
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
using namespace std;
int dp[2][105][105][105];
int C[105][105];
int mod=1e9+7; 
void add(int &x,int y){
	x+=y;
	if(x>=mod)x-=mod;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	C[0][0]=1;
	FOR(i,1,100){
		C[i][0]=1;
		FOR(j,1,i)C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
	}
	FOR(i,1,n)dp[0][i][i][1]=1;
	int ans=0,T=0;
	FOR(_,2,m){
		T^=1;
		FILL(dp[T],0);
		FOR(i,1,n){
			FOR(j,1,n){
				FOR(num,1,k)if(dp[T^1][i][j][num]){
					FOR(cnt,i,n-j)if(num*C[cnt-1][i-1]<=k){
						add(dp[T][cnt-i][j+cnt][num*C[cnt-1][i-1]],dp[T^1][i][j][num]);
					}
				}
			}
		}
		FOR(i,1,n)FOR(j,1,k)ans=(ans+dp[T][0][i][j]*(m-_+1))%mod;
	}
	cout<<ans;
	RE 0;
}