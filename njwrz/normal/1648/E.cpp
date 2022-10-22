#pragma GCC optimize("Ofast", "inline", "-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include<bits/stdc++.h>
#define int long long
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
P<int,P<int,int> > p[200005];
int n,m;
int fa[400005];
V<int> v[400005];
int val[400005],it[400005],dfn[400005],pos,pos2;
int siz;
int get(int x){
	RE (fa[x]==x)?x:(fa[x]=get(fa[x]));
}
int merge(int x,int y){
	x=get(x);y=get(y);
	if(x!=y){
		fa[x]=y;
		RE 1;
	}
	RE 0;
}
P<int,P<int,int> > ed[1200005];
V<int> g[200005];
bool era[200005];
int maxi=1e18;
int l2[800005];
int dep[400005];
P<int,int> st[800005][20];
int tim[400005];
void dfs(int x,int y){
	if(x<=n){
		dfn[x]=++pos;
		it[pos]=x;
	}
	for(auto u:v[x])if(u!=y){
		st[++pos2][0]=MP(dep[x],x);
		dep[u]=dep[x]+1;
		dfs(u,x);
	}
	st[++pos2][0]=MP(dep[x],x);
	tim[x]=pos2;
}
int getval(int l,int r){
	l=tim[l],r=tim[r];
	if(l>r)swap(l,r);
	int t=l2[r-l+1];
	RE val[min(st[l][t],st[r-(1<<t)+1][t]).S];
}
int tu[200005],tv[200005],tval[200005];
void solve(){
	pos=0;pos2=0;
	cin>>n>>m;
	FOR(i,1,n+n)fa[i]=i;
	FOR(i,1,n)g[i].clear();
	FOR(i,1,m){
		cin>>p[i].S.F>>p[i].S.S>>p[i].F;
		g[p[i].S.F].PB(p[i].S.S);
		g[p[i].S.S].PB(p[i].S.F);
		tu[i]=p[i].S.F;tv[i]=p[i].S.S;tval[i]=p[i].F;
	}
	sort(p+1,p+m+1);
	FOR(i,1,n+n)val[i]=0;
	int cnt=n;
	FOR(i,1,n+n)v[i].clear();
	FOR(i,1,m){
		if(get(p[i].S.F)!=get(p[i].S.S)){
			++cnt;
			val[cnt]=p[i].F;
			int t1=get(p[i].S.F),t2=get(p[i].S.S);
			merge(p[i].S.F,cnt);
			merge(p[i].S.S,cnt);
			v[cnt].PB(t1);v[t1].PB(cnt);
			v[cnt].PB(t2);v[t2].PB(cnt);
		}
	}
	int root=get(1);
	dfs(root,-1);
	rep(i,1,20){
		FOR(j,1,n*4-(1<<i)+1)st[j][i]=min(st[j][i-1],st[j+(1<<(i-1))][i-1]);
	}
//	if(n>=200000)cout<<pos2<<' ';
	siz=0;
	FOR(i,1,n){
		int pp=g[i].size()+1;
		for(auto u:g[i])era[u]=1;
		era[i]=1;
		int now=dfn[i];
		FOR(_,1,pp){
			while(now&&era[it[now]])now--;
			if(now>0){
				ed[++siz]=MP(getval(it[now],i),MP(it[now],i));
			}else break;
			now--;
		}
		now=dfn[i];
		FOR(_,1,pp){
			while(now<=n&&era[it[now]])now++;
			if(now<=n){
				ed[++siz]=MP(getval(it[now],i),MP(it[now],i));
			}else break;
			now++;
		}
//		if(siz>=1000000)break;
		era[i]=0;
		for(auto u:g[i])era[u]=0;
	}
//	if(n>=200000)RE;
//	assert(siz<=1000000);
	FOR(i,1,n+n)fa[i]=i;
	FOR(i,1,n+n)val[i]=0;
	cnt=n;
	FOR(i,1,n+n)v[i].clear();
	sort(ed+1,ed+siz+1);
	FOR(i,1,siz){
		if(get(ed[i].S.F)!=get(ed[i].S.S)){
			++cnt;
			val[cnt]=ed[i].F;
			int t1=get(ed[i].S.F),t2=get(ed[i].S.S);
			merge(ed[i].S.F,cnt);
			merge(ed[i].S.S,cnt);
			v[cnt].PB(t1);v[t1].PB(cnt);
			v[cnt].PB(t2);v[t2].PB(cnt);
		}
	}
//	assert(cnt==n+n-1);
	pos=pos2=0;
	dfs(get(1),-1);
	rep(i,1,20){
		FOR(j,1,n*4-(1<<i)+1)st[j][i]=min(st[j][i-1],st[j+(1<<(i-1))][i-1]);
	}
	FOR(i,1,m){
		cout<<getval(tu[i],tv[i])<<' ';
	}
	cout<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	FOR(i,2,800000)l2[i]=l2[i/2]+1;
	int T;
	cin>>T;
	while(T--)solve();
	RE 0;
}