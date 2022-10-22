#include<bits/stdc++.h>
#define ll long long
#define lb long double
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
#define lc (x<<1)
#define rc ((x<<1)^1)
#define y1 yyyy1111
#define mod 998244353
using namespace std;
P<int,int> p[2005],used[2005];
int dp[2][2005][2005],f[2005][2005],C[2005][2005];
void add(int &x,int y){
	x+=y;
	if(x>=mod)x-=mod;
}
int A[2005][2005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,k;
	cin>>n>>k;
	FOR(i,0,n){
		C[i][0]=1;
		FOR(j,1,i)C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	}
	FOR(i,0,n){
		A[i][0]=1;
		FOR(j,1,i)A[i][j]=1ll*A[i][j-1]*(i-j+1)%mod;
	}
	FOR(i,1,n){
		used[i]=MP(n,0);
		int x;
		cin>>x;
		p[i]=MP(max(0,x-k),min(n,x+k));
	}
	int T=0;
	dp[T][0][0]=1;
	rep(i,0,n){
		FOR(j,0,i)FOR(mex,p[i].F,p[i].S)if(dp[T][j][mex]){
			gmin(used[i+1].F,mex);gmax(used[i+1].S,mex);
			add(dp[T^1][j][mex],1ll*dp[T][j][mex]*(mex+j)%mod);
			add(dp[T^1][j+1][mex],dp[T][j][mex]);
			add(f[j][mex+1],dp[T][j][mex]);
		}
		FOR(mex,p[i].F+1,p[i+1].S){
			FOR(j,0,i)if(f[j][mex]){
				gmin(used[i+1].F,mex);gmax(used[i+1].S,mex);
				add(dp[T^1][j][mex],f[j][mex]);
				if(j)add(f[j-1][mex+1],1ll*f[j][mex]*j%mod);
			}
		}
		FOR(mex,used[i].F,used[i].S)FOR(j,0,i)dp[T][j][mex]=0;
		FOR(mex,p[i].F+1,max(p[i+1].S+1,p[i].S+1))FOR(j,0,i)f[j][mex]=0;
		T^=1;
	}
	int ans=0;
	FOR(mex,p[n].F,p[n].S)FOR(i,0,n)add(ans,1ll*dp[T][i][mex]*A[n-mex][i]%mod);
	cout<<ans;
	RE 0;
}