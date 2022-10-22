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
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
#define lc (x<<1)
#define rc ((x<<1)|1)
#define sz(x) ((int)x.size())
using namespace std;
P<int,int> p[64][100005];
int suml[64][100005],sumr[64][100005];
int a[100005];
int n;
int dp[64][100005];
const int inf=1e18;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	FOR(i,1,n)cin>>a[i];
	FOR(i,0,63)FOR(j,0,n)dp[i][j]=inf;
	dp[0][n]=0;
	FOR(i,0,63){
		FOR(j,1,n){
			p[i][j]=MP(a[j]&((1ll<<i)-1),j);
		}
		sort(p[i]+1,p[i]+n+1);
		FOR(j,1,n)suml[i][j]+=suml[i][j-1]+((a[p[i][j].S]&(1ll<<i))==0);
		for(int j=n;j>=1;j--)sumr[i][j]+=sumr[i][j+1]+((a[p[i][j].S]&(1ll<<i))>0);
	}
	rep(i,0,63){
		FOR(j,0,n)if(dp[i][j]!=inf){
			int to=p[i][j].F+(1ll<<i);
			int it=upb(p[i+1]+1,p[i+1]+n+1,MP(to,n+1))-p[i+1]-1;
			gmin(dp[i+1][it],dp[i][j]+suml[i][j]+sumr[i][j+1]);
			to=p[i][j].F;
			it=upb(p[i+1]+1,p[i+1]+n+1,MP(to,n+1))-p[i+1]-1;
			gmin(dp[i+1][it],dp[i][j]+n-(suml[i][j]+sumr[i][j+1]));
		}
	}
	cout<<dp[63][n];
	RE 0;
}