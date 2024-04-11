#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<map>
#define int long long
#define pb push_back
using namespace std;
const int N=6e5+55;
int n,m,x,y;
vector<int>v[N],g[N];
struct Q{
	int x,y,L,l,r;
}q[N];
struct Tree{
	const int B=19;
	int fu[N][21],deep[N];
	void dfs(int u,int fa){
		deep[u]=deep[fa]+1;
		fu[u][0]=fa;
		for(int i=1;i<=B;i++)fu[u][i]=fu[fu[u][i-1]][i-1];
		for(int i=0;i<v[u].size();i++){
			if(v[u][i]==fa)continue;
			dfs(v[u][i],u);
		}
	}
	int lca(int x,int y){
		int xx=x,yy=y;
		if(deep[x]<deep[y])swap(x,y);
		for(int i=B;i>=0;i--){
			if(deep[x]-(1<<i)>=deep[y])
			{
				x=fu[x][i];
			}
		}
		if(x==y){return x;}
		for(int i=B;i>=0;i--){
			if(fu[x][i]!=fu[y][i]){
				x=fu[x][i];
				y=fu[y][i];
			}
		}
		
		return fu[y][0];
	}
	int tiao(int u,int fa){
		for(int i=B;i>=0;i--){
			if(deep[u]-(1<<i)>deep[fa]){
				u=fu[u][i];
			}
		}
		return u;
	}
	void prework(){
		dfs(1,0);
	}
}t;
int tong[N],ans;
map<int,int>ma[N];
void dfs(int u,int fa){
	
	if(u==8){
		new char;
	}
	ans=(ans+(g[u].size()*(g[u].size()-1ll))/2ll);
//	if(m==300000){
//		cout<<g[u].size()<<"!\n";
//	}
	for(int i=0;i<g[u].size();i++){
		int h=g[u][i];
		if(q[h].l!=-1)ans-=tong[q[h].l];
		if(q[h].r!=-1)ans-=tong[q[h].r];
		if(q[h].l!=-1 && q[h].r!=-1)ans+=ma[q[h].l][q[h].r];
		if(q[h].l!=-1)tong[q[h].l]++;
		if(q[h].r!=-1)tong[q[h].r]++;
		if(q[h].l!=-1 && q[h].r!=-1)ma[q[h].l][q[h].r]++;
	}
	for(int i=0;i<g[u].size();i++){
		int h=g[u][i];
		if(q[h].l!=-1)tong[q[h].l]--;
		if(q[h].r!=-1)tong[q[h].r]--;
		if(q[h].l!=-1 and q[h].r!=-1)ma[q[h].l][q[h].r]--;
	}
	for(int i=0;i<v[u].size();i++){
		if(v[u][i]==fa)continue;
		dfs(v[u][i],u);
	}
}
struct BIT{
	int bit[N+5];
	int lowbit(int x){
		return ((x&(-x)));
	}
	void add(int x,int k){
		for(;x<=n;x+=lowbit(x))bit[x]+=k;
	}
	int query(int x){
		int summ=0;
		for(;x;x-=lowbit(x))summ+=bit[x];
		return summ;
	}
	int query(int l,int r){
		return query(r)-query(l-1);
	}
}bit;
int dfn[N],tot;
int siz[N];
void dfs1(int u,int fa){
	dfn[u]=++tot;siz[u]=1;
	for(int i=0;i<v[u].size();i++){
		if(v[u][i]==fa)continue;
		dfs1(v[u][i],u);
		siz[u]+=siz[v[u][i]];
	}
}
void dfs2(int u,int fa){
	for(int i=0;i<g[u].size();i++){
		int h=g[u][i];
		ans+=bit.query(dfn[u],dfn[u]+siz[u]-1);
		if(q[h].l!=-1){
			int ll=q[h].l;
			ans-=bit.query(dfn[ll],dfn[ll]+siz[ll]-1);
		}
		if(q[h].r!=-1){
			int rr=q[h].r;
			ans-=bit.query(dfn[rr],dfn[rr]+siz[rr]-1);
		}
	}
	for(int i=0;i<g[u].size();i++){
		int h=g[u][i];
		bit.add(dfn[q[h].x],1);
		bit.add(dfn[q[h].y],1);
	}
	for(int i=0;i<v[u].size();i++){
		if(v[u][i]==fa)continue;
		dfs2(v[u][i],u);
	}
}
signed main(){
//	freopen("s.in","r",stdin);
	scanf("%lld",&n);
	for(int i=1;i<n;i++){
		scanf("%lld%lld",&x,&y);
		v[x].pb(y);
		v[y].pb(x);
	}
	t.prework();
	scanf("%lld",&m);
	//bool flag=0;
	for(int i=1;i<=m;i++){
		scanf("%lld%lld",&q[i].x,&q[i].y);
		q[i].L=t.lca(q[i].x,q[i].y);
	//	if(q[i].L!=1){
	//		flag=1;
	//	}
		g[q[i].L].push_back(i);
		q[i].l=(q[i].x==q[i].L)?-1:t.tiao(q[i].x,q[i].L);
		q[i].r=(q[i].y==q[i].L)?-1:t.tiao(q[i].y,q[i].L);
		if(q[i].l>q[i].r and q[i].l!=-1 and q[i].r!=-1){
			swap(q[i].x,q[i].y);
			swap(q[i].l,q[i].r);
		}
	}
	dfs(1,0);
//	if(m==300000){
//		cout<<flag<<" "<<ans<<"?\n";
//	}
	dfs1(1,0);
	dfs2(1,0);
	printf("%lld",ans);
	return 0;
}