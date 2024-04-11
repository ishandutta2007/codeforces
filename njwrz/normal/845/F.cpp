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
char c[255][255],to[255][255];
int n,m;
int dp[2][1<<15][2][2],mod=1e9+7;
bool f[20],tp[1<<15][16];
void add(int &x,int y){
	x+=y;
	if(x>=mod)x-=mod;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	FOR(i,1,n)FOR(j,1,m)cin>>c[i][j];
	if(n<m){
		FOR(i,1,n){
			FOR(j,1,m)to[j][i]=c[i][j];
		}
		swap(n,m);
		FOR(i,1,n)FOR(j,1,m)c[i][j]=to[i][j];
	}
	int T=0;
	dp[T][0][0][0]=1;
	FOR(i,1,n){
		FOR(j,1,m){
			FILL(dp[T^1],0);
			if(c[i][j]=='x'){
				FOR(num,0,1)FOR(num2,0,1)rep(mask,0,1<<m){
					add(dp[T^1][mask&((1<<m)-1-(1<<(j-1)))][num][0],dp[T][mask][num][num2]);
				}
				T^=1;
				continue;
			}
			if(j==1){
				rep(mask,0,1<<m)FOR(num1,0,1)add(dp[T][mask][num1][0],dp[T][mask][num1][1]),
				dp[T][mask][num1][1]=0;
			}
			rep(mask,0,1<<m)FOR(num2,0,1){
				int now=(mask&(1<<(j-1)))|num2;
				if(now){
					add(dp[T^1][mask][0][num2],dp[T][mask][0][num2]%mod);
					add(dp[T^1][mask][1][num2],dp[T][mask][1][num2]%mod);
					add(dp[T^1][mask|(1<<(j-1))][0][1],dp[T][mask][0][num2]%mod);
					add(dp[T^1][mask|(1<<(j-1))][1][1],dp[T][mask][1][num2]%mod);
				}else {
					add(dp[T^1][mask][1][num2],dp[T][mask][0][num2]);
					rep(k,0,2)add(dp[T^1][mask|(1<<(j-1))][k][1],dp[T][mask][k][num2]);
				}
			}
			T^=1;
		}
	}
	int ans=0;
	rep(mask,0,1<<m)FOR(k,0,1)FOR(num2,0,1)add(ans,dp[T][mask][k][num2]);
	cout<<ans;
	RE 0;
}