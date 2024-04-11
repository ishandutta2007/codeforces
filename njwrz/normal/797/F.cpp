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
int n,m,a[5005];
int dp[2][5005];
P<int,int> p[5005];
const int inf=1e18;
int cost[5005];
P<int,int> q[5005];
signed main(){
//	freopen("jandt.in","r",stdin);
//	freopen("jandt.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	FOR(i,1,n)cin>>a[i];
	sort(a+1,a+n+1);
	FOR(i,1,m)cin>>p[i].F>>p[i].S;
	sort(p+1,p+m+1);
	int T=0;
	FOR(i,1,n)dp[0][i]=1e18;
	FOR(i,1,m){
		FOR(j,1,n)cost[j]=cost[j-1]+abs(a[j]-p[i].F);
		int s=1,t=0;
		FOR(j,0,n){
			P<int,int> now=MP(dp[T][j]-cost[j],j);
			while(s<=t&&q[t].F>now.F)t--;
			q[++t]=now;
			while(s<=t&&j-q[s].S>p[i].S)s++;
			dp[T^1][j]=min(inf,q[s].F+cost[j]);
		}T^=1;
	}
	if(dp[T][n]>=inf){
		cout<<-1;
	}else cout<<dp[T][n];
	RE 0;
}