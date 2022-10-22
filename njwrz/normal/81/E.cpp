/*

DP





ll int
 dp 










*/
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
int n;
bool vis[100005],pt[2][100005][2];
bool f[100005],tf;
int p[2][100005][2];
V<int> v[100005];
bool to[100005];
P<int,int> dp[2][100005][2];
V<int> lst,loop;
V<P<int,int> > ans;
P<int,int> ansp;
void dfs(int x,int fa){
	if(vis[x]==1&&tf){
		bool ff=0;
		for(auto u:lst){
			if(u==x){
				ff=1;
			}
			if(ff&&!to[u])loop.PB(u),to[u]=1;
		}
		tf=0;
		RE;
	}
	if(vis[x]==1)RE;
	vis[x]=1;
	bool ttf=1;
	for(auto u:v[x]){
		if(u!=fa||!ttf){
			lst.PB(u);
			dfs(u,x);
			lst.pop_back();
		}else if(u==fa)ttf=0;
	}
}
void get(int x,int fa,int full,int col){
	if(pt[col][x][full])RE;
	pt[col][x][full]=1;
	P<int,int> now;
	for(auto u:v[x])if(u!=fa){
		get(u,x,0,col);
		get(u,x,1,col);
		now.F+=dp[col][u][1].F;
		now.S+=dp[col][u][1].S;
	}
	P<int,int> tw=now;
	if(full){
		for(auto u:v[x])if(u!=fa){
			P<int,int> tn=MP(now.F-dp[col][u][1].F+dp[col][u][0].F+1,now.S-dp[col][u][1].S+dp[col][u][0].S+(f[x]!=f[u]));
			if(tn>tw){
				tw=tn;
				p[col][x][full]=u;
			}
		}
	}
	dp[col][x][full]=tw;
}
void erase(int x,int y){
	V<int> tv;
	bool ttf=1;
	for(auto u:v[x]){
		if(u!=y||!ttf)tv.PB(u);
		else ttf=0;
	}
	v[x]=tv;
}
void into(int x,int full,int col,int fa){
	if(p[col][x][full]){
		ans.PB(MP(p[col][x][full],x));
		for(auto u:v[x])if(u!=fa){
			if(u==p[col][x][full]){
				into(u,0,col,x);
			}else into(u,1,col,x);
		}
	}else{
		for(auto u:v[x])if(u!=fa){
			into(u,1,col,x);
		}
	}
}
void solve(int x){
	lst.clear();
	lst.PB(x);
	loop.clear();
	tf=1;
	dfs(x,-1);
	int t=loop.back();
	int cnt=0;
	int p1=0,p2=0;
//	cout<<'\n';
//	for(auto u:loop)cout<<u<<' ';
//	cout<<'\n';
	for(auto u:v[t]){
		if(to[u]){
			cnt++;
			if(cnt==1)p1=u;
			else if(cnt==2){
				p2=u;break;
			}
		}
	}
	erase(p1,t);
	erase(t,p1);
	get(t,-1,1,0);
//	FOR(i,1,n){
//		for(auto u:v[i])cout<<u<<' ';
//		cout<<'\n';
//	}
	v[t].PB(p1);
	v[p1].PB(t);
	erase(p2,t);
	erase(t,p2);
	get(t,-1,1,1);
	v[t].PB(p2);
	v[p2].PB(t);
	if(dp[0][t][1]>dp[1][t][1]){
		ansp.F+=dp[0][t][1].F;
		ansp.S+=dp[0][t][1].S;
		erase(p1,t);
		erase(t,p1);
		into(t,1,0,-1);
	}else{
		ansp.F+=dp[1][t][1].F;
		ansp.S+=dp[1][t][1].S;
		erase(p2,t);
		erase(t,p2);
		into(t,1,1,-1);
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	int x,y;
	FOR(i,1,n){
		cin>>x>>y;
		if(y==1){
			f[i]=1;
		}else f[i]=0;
		v[i].PB(x);
		v[x].PB(i);
	}
	FOR(i,1,n){
		if(!vis[i]){
			solve(i);
		}
	}
	cout<<ansp.F<<' '<<ansp.S<<'\n';
	for(auto u:ans)cout<<u.F<<' '<<u.S<<'\n';
	RE 0;
}