#pragma GCC optimize("Ofast", "inline", "-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
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
using namespace std;
V<P<P<int,int>,int> > v[100005];
int n,m,a[100005],dp[105][100005],maxi=1e9;
P<P<int,int>,int> lst[105][100005];
V<int> ans;
P<P<int,int>,int> p[100005];
int len;
int check(int x){
	len=0;
	for(auto u:v[x])p[++len]=u;
	FOR(i,0,100)FOR(j,0,len)dp[i][j]=maxi+1;
	dp[0][0]=0;
	FOR(i,0,100){
		rep(j,0,len){
			auto u=p[j+1];
			if(dp[min(i+u.F.S,100)][j+1]>dp[i][j]+u.F.F){
				dp[min(i+u.F.S,100)][j+1]=dp[i][j]+u.F.F;
				lst[min(i+u.F.S,100)][j+1]=MP(MP(i,j),u.S);
			}
			if(dp[i][j+1]>dp[i][j]){
				dp[i][j+1]=dp[i][j];
				lst[i][j+1]=MP(MP(i,j),-1);
			}
		}
	}
	if(dp[100][len]>maxi){
		RE maxi+1;
	}
	int nowx=100,nowy=len;
	while(nowx){
		if(lst[nowx][nowy].S!=-1)ans.PB(lst[nowx][nowy].S);
		P<int,int> to=lst[nowx][nowy].F;
		nowx=to.F;nowy=to.S;
	}
	RE dp[100][len];
}
void solve(){
	cin>>n>>m;
	FOR(i,1,n)cin>>a[i],v[i].clear();
	ans.clear();
	int ti=0;
	FOR(i,1,m){
		int to,t,tv;
		cin>>to>>t>>tv;
		v[to].PB(MP(MP(t,tv),i));
	}
	FOR(i,1,n){
		int cost=check(i);
		ti+=cost;
		if(ti>a[i]){
			cout<<-1<<'\n';RE;
		}
	}
	cout<<ans.size()<<'\n';
	for(auto u:ans)cout<<u<<' ';
	cout<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)solve();
	RE 0;
}