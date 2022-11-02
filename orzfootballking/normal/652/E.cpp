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
int num,cnt,it,low[300005],d[300005];
V<P<int,int> > v[300005];
V<P<int,int> > g[300005];
int s[300005],c[300005];
P<P<int,int>,int>  p[300005];
bool f[300005];
void tarjan(int x,int fa){
	s[++it]=x;
	d[x]=low[x]=++num;
	for(auto u:v[x])if(u.F!=fa){
		if(!d[u.F]){
			tarjan(u.F,x);
		}
		gmin(low[x],low[u.F]);
	}
	if(low[x]==d[x]){
		cnt++;
		while(s[it]!=x){
			c[s[it]]=cnt;
			it--;
		}
		c[s[it]]=cnt;
		it--;
	}
}
void dfs(int now,int end,int lst,bool t){
	t|=f[now];
	if(now==end){
		if(t){
			cout<<"YES";exit(0);
		}
		RE;
	}
	for(auto u:g[now])if(u.F!=lst){
		dfs(u.F,end,now,t|u.S);
	} 
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	int x,y,z;
	FOR(i,1,m){
		cin>>x>>y>>z;
		v[x].PB(MP(y,z));
		v[y].PB(MP(x,z));
		p[i]=MP(MP(x,y),z);
	}
	FOR(i,1,n){
		if(!d[i])tarjan(i,-1);
	}
	FOR(i,1,m){
		int x,y;
		x=p[i].F.F;
		y=p[i].F.S;
		if(c[x]==c[y]){
			f[c[x]]|=p[i].S;
		}else {
			g[c[x]].PB(MP(c[y],p[i].S));
			g[c[y]].PB(MP(c[x],p[i].S));
		}
	}
	cin>>x>>y;
	dfs(c[x],c[y],-1,0);
	cout<<"NO";
	RE 0;
}