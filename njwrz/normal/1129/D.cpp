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
int dp[100005];
int B;
V<P<int,int> > sum[100005]; 
int del[100005],val[100005],n,k,a[100005];
V<int> v[100005];
V<P<int,int> > op[100005]; 
const int mod=998244353;
void add(int &x,int y){
	x+=y;
	if(x>=mod)x-=mod;
}
void rebuild(int t){
	int tl=t*B,tr=min(t*B+B-1,n);
	FOR(i,tl,tr)val[i]+=del[t];
	del[t]=0;
	sum[t].clear();
	FOR(i,tl,tr){
		sum[t].PB(MP(val[i],dp[i]));
	}
	sort(ALL(sum[t]));
	rep(i,1,(int)sum[t].size())add(sum[t][i].S,sum[t][i-1].S);
	V<P<int,int> > now;
	rep(i,1,(int)sum[t].size())if(sum[t][i].F!=sum[t][i-1].F)now.PB(sum[t][i-1]);
	now.PB(sum[t].back());
	sum[t]=now;
}
void update(int x,int y){
	int t=x/B;
	rep(i,0,t)del[i]+=y;
	int tl=t*B;
	FOR(i,tl,x)val[i]+=y;
	rebuild(t);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k;
	B=min(100,(int)sqrt(n));
	dp[0]=1;
	sum[0].PB(MP(0,1));
	FOR(i,1,n){
		cin>>a[i];v[a[i]].PB(i);
	}
	FOR(i,1,n)if(!v[i].empty()){
		v[i].PB(0),v[i].PB(n+1);
		sort(ALL(v[i]));
		rep(j,0,(int)v[i].size()-2){
			op[v[i][j+1]].PB(MP(v[i][j+1]-1,1));
			if(v[i][j])op[v[i][j+1]].PB(MP(v[i][j]-1,-1));
			op[v[i][j+2]].PB(MP(v[i][j+1]-1,-1));
			if(v[i][j])op[v[i][j+2]].PB(MP(v[i][j]-1,1));
		}
	}
	FOR(i,1,n){
		for(auto u:op[i])update(u.F,u.S);
		FOR(j,0,i/B){
			int it=upb(ALL(sum[j]),MP(k-del[j],mod))-sum[j].begin();
			if(!it)continue;
			--it;
			add(dp[i],sum[j][it].S);
		}
		rebuild(i/B);
	}
	cout<<dp[n];
	RE 0;
}