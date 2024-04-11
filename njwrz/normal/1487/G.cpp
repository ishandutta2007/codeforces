/*

DP





ll int
 dp 










*/
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define ll long long
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
int dp1[405][405][2],dp2[405][405][405][3],mod=998244353;
int n;
int c[405]; 
void add(int &x,int y){
	x+=y;
	if(x>=mod)x-=mod;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	FOR(i,1,26)cin>>c[i];
	int ans=26*26;
	FOR(i,1,n-2)ans=1ll*ans*25%mod;
	dp1[1][1][1]=1;
	dp1[1][0][0]=25;
	FOR(i,2,n)FOR(j,0,n){
		if(i!=n/2+1){
			if(j){
				dp1[i][j][1]=dp1[i-1][j-1][0];
			}
			dp1[i][j][0]=(1ll*dp1[i-1][j][0]*24+1ll*dp1[i-1][j][1]*25)%mod;
		}else{
			if(j){
				dp1[i][j][1]=(dp1[i-1][j-1][0]+dp1[i-1][j-1][1])%mod;
			}
			dp1[i][j][0]=(1ll*dp1[i-1][j][0]*25+1ll*dp1[i-1][j][1]*25)%mod;
		}
	}
	FOR(i,1,26){
		FOR(j,c[i]+1,n){
			ans=(0ll+ans-dp1[n][j][0]-dp1[n][j][1]+mod+mod)%mod;
		}
	}
	dp2[1][1][0][1]=1;
	dp2[1][0][1][2]=1;
	dp2[1][0][0][0]=24;
	FOR(i,2,n)FOR(j,0,n)FOR(k,0,n){
		if(i!=n/2+1){
			if(j){
				dp2[i][j][k][1]=(dp2[i-1][j-1][k][0]+dp2[i-1][j-1][k][2])%mod;
			}
			if(k){
				dp2[i][j][k][2]=(dp2[i-1][j][k-1][0]+dp2[i-1][j][k-1][1])%mod;
			}
			dp2[i][j][k][0]=(1ll*dp2[i-1][j][k][0]*23+1ll*dp2[i-1][j][k][1]*24+1ll*dp2[i-1][j][k][2]*24)%mod;
		}else{
			if(j){
				dp2[i][j][k][1]=(0ll+dp2[i-1][j-1][k][0]+dp2[i-1][j-1][k][2]+dp2[i-1][j-1][k][1])%mod;
			}
			if(k){
				dp2[i][j][k][2]=(0ll+dp2[i-1][j][k-1][0]+dp2[i-1][j][k-1][1]+dp2[i-1][j][k-1][2])%mod;
			}
			dp2[i][j][k][0]=(1ll*dp2[i-1][j][k][0]*24+1ll*dp2[i-1][j][k][1]*24+1ll*dp2[i-1][j][k][2]*24)%mod;
		}
	}
	FOR(i,1,26){
		FOR(j,i+1,26){
			FOR(k,c[i]+1,n){
				FOR(z,c[j]+1,n){
					ans=(0ll+ans+dp2[n][k][z][0]+dp2[n][k][z][1]+dp2[n][k][z][2])%mod;
				}
			}
		}
	}
	cout<<ans;
	RE 0;
}