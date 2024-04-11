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
V<P<int,int> > v[200005];
int d[200005],fa[200005];
int root[600005];
int dis[600005];
int tor[200005],ans[200005],siz[200005],itr[200005],add[200005];
int ts[600005],tt[600005];
bool vis[200005];
V<int> lo;
map<P<int,int>,int> g;
void dfs(int p,int fat){
	for(auto u:v[p])if(!d[u.F]&&u.F!=1){
		d[u.F]=d[p]+1;fa[u.F]=p;
		dfs(u.F,p);
	}
	for(auto u:v[p])if(d[u.F]&&u.F!=fat&&fa[u.F]!=p){
		V<int> v;
		int S=u.F,T=p;
		if(d[S]<d[T])swap(S,T);
		while(d[S]>d[T]){
			v.PB(S);
			S=fa[S];
		}
		V<int> d;
		while(S!=T){
			v.PB(S);
			d.PB(T);
			S=fa[S];
			T=fa[T];
		}
		v.PB(S);
		lo=v;reverse(ALL(d));
		for(auto now:d)lo.PB(now);
	}
}
void get(int p,int fat,int rt){
	siz[p]=1;ans[rt]+=tor[p];itr[p]=rt;
	for(auto u:v[p])if(!vis[u.F]&&u.F!=fat){
		tor[u.F]=tor[p]+u.S;fa[u.F]=p;
		get(u.F,p,rt);
		siz[p]+=siz[u.F];
	}
}
void geta(int p){
	for(auto u:v[p])if(!vis[u.F]&&u.F!=fa[p]){
		ans[u.F]=ans[p]-siz[u.F]*u.S+(siz[itr[p]]-siz[u.F])*u.S;
		geta(u.F);
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	FOR(i,1,n){
		int x,y,z;
		cin>>x>>y>>z;
		v[x].PB(MP(y,z));
		v[y].PB(MP(x,z));
		g[MP(x,y)]=z;
		g[MP(y,x)]=z;
	}
	dfs(1,-1);
	int cnt=0;
	for(auto u:lo)root[++cnt]=u;
	for(auto u:lo)root[++cnt]=u;
	for(auto u:lo)root[++cnt]=u;
	int sum=0;
	FOR(i,1,cnt/3){
		sum+=g[MP(root[i],root[i+1])];
	}
	rep(i,1,cnt){
		dis[i+1]=dis[i]+g[MP(root[i],root[i+1])];
	}
	int sumtr=0;
	FOR(i,1,cnt/3)vis[root[i]]=1;
	FOR(i,1,cnt/3){
		fa[root[i]]=-1;
		get(root[i],-1,root[i]);
		geta(root[i]);
		sumtr+=ans[root[i]];
	}
	FOR(i,1,cnt){
		tt[i]=tt[i-1]+siz[root[i]];
		ts[i]=ts[i-1]+siz[root[i]]*dis[i];
	}
	int it1,it2;
	it1=1;
	int len=cnt/3;
	it2=len;
	FOR(i,len+1,len*2){
		while(dis[it2+1]-dis[i]<dis[i]-dis[it1]){
			it1++;it2++;
		}
		add[root[i]]=ts[it2]-ts[i]-(dis[i]*(tt[it2]-tt[i]));
		add[root[i]]-=ts[i-1]-ts[it1-1]-(dis[i]*(tt[i-1]-tt[it1-1]));
	}
	FOR(i,1,n)
		cout<<tor[i]*(n-siz[itr[i]])+(sumtr-ans[itr[i]])+ans[i]+add[itr[i]]<<' ';
	RE 0;
}