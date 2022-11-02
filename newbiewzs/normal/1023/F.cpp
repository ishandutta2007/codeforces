#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<vector>
#include<queue>
#include<map>
#include<ctime>
#include<bitset>
#include<set>
#include<math.h>
//#include<unordered_map>
#define fi first
#define se second
#define mp make_pair
#define pii pair<int,int>
#define pb push_back
#define pil pair<int,long long>
#define pll pair<long long,long long>
#define vi vector<int>
#define vl vector<long long>
#define ci ios::sync_with_stdio(false)
#define int long long
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int read(){
	char c=getchar();
	ll x=1,s=0;
	while(c<'0'||c>'9'){
	   if(c=='-')x=-1;c=getchar();
	}
	while(c>='0'&&c<='9'){
	   s=s*10+c-'0';c=getchar();
	}
	return s*x;
}
const int N=5e5+5;
int n,m,s,x,y,z,head,bj[N],f[N],siz[N],son[N],fu[N],deep[N],top[N],dfn[N],tot;
vector<pii>v[N];
int find(int x){
	if(f[x]!=x)return f[x]=find(f[x]);
	else return x;
}
struct node{
	int x,y,w;
	friend bool operator < (node x,node y){
		return x.w<y.w;
	}
}g[N],q[N];
void dfs(int u,int fa){
	fu[u]=fa;siz[u]=1;deep[u]=deep[fa]+1;
	for(int i=0;i<v[u].size();i++){
		if(v[u][i].fi==fa)continue;
		if(v[u][i].se==1)bj[v[u][i].fi]=1;
		dfs(v[u][i].fi,u);
		siz[u]+=siz[v[u][i].fi];
		if(siz[v[u][i].fi]>siz[son[u]])son[u]=v[u][i].fi;
	}
}
void dfs1(int u,int fa){
	top[u]=fa;dfn[u]=++tot;
	if(son[u])dfs1(son[u],fa);
	for(int i=0;i<v[u].size();i++){
		if(top[v[u][i].fi])continue;
		dfs1(v[u][i].fi,v[u][i].fi);
	}
}
struct SegmentTree{
	int tag[N*4];
	#define mid ((l+r)>>1)
	#define ls (u<<1)
	#define rs (u<<1|1)
	void build(int u,int l,int r){
		tag[u]=114514191981;
		if(l==r){
			return ;
		}
		build(ls,l,mid);
		build(rs,mid+1,r);
	}
	void pushdown(int u){
		if(tag[u]!=114514191981){
			tag[ls]=min(tag[ls],tag[u]);
			tag[rs]=min(tag[rs],tag[u]);
			tag[u]=114514191981;
		}
	}
	void add(int u,int l,int r,int L,int R,int x){
		if(L<=l and R>=r){
			tag[u]=min(tag[u],x);
			return ;
		}
		pushdown(u);
		if(L<=mid)add(ls,l,mid,L,R,x);
		if(R>mid)add(rs,mid+1,r,L,R,x);
	}
	int query(int u,int l,int r,int x){
		if(l==r){
			return tag[u];
		}
		pushdown(u);
		if(x<=mid)return query(ls,l,mid,x);
		else return query(rs,mid+1,r,x);
	}
}t;
void make(int x,int y,int w){
	while(top[x]!=top[y]){
		if(deep[top[x]]<deep[top[y]])swap(x,y);
		t.add(1,1,n,dfn[top[x]],dfn[x],w);
		x=fu[top[x]];
	}
	if(deep[x]<deep[y])swap(x,y);
	if(x!=y){
		t.add(1,1,n,dfn[y]+1,dfn[x],w);
	}
}
signed main(){
	n=read();m=read();s=read();
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++){
		x=read();y=read();
		v[x].pb(mp(y,1));
		v[y].pb(mp(x,1));
		f[find(x)]=find(y);
	}
	for(int i=1;i<=s;i++){
		x=read();y=read();z=read();
		g[i]={x,y,z};
	}
	sort(g+1,g+s+1);
	for(int i=1;i<=s;i++){
		if(find(g[i].x)!=find(g[i].y)){
			f[find(g[i].x)]=find(g[i].y);
			v[g[i].x].pb(mp(g[i].y,2));
			v[g[i].y].pb(mp(g[i].x,2));
		}
		else{
			q[++head]=g[i];
		}
	}
	t.build(1,1,n);
	dfs(1,0);
	dfs1(1,1);
	for(int i=1;i<=head;i++){
		make(q[i].x,q[i].y,q[i].w);
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		if(bj[i]){
			int tmp=t.query(1,1,n,dfn[i]);
			if(tmp==114514191981){
				cout<<"-1";
				return 0;
			}
			ans+=tmp;
		}
	}
	cout<<ans;
	return 0;
}