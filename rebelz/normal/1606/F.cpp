#include<bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template<typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}
template<typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

struct node{
	int x,y;
	node(int x=0,int y=0):x(x),y(y){}
	bool operator<(const node c)const{return 1ll*y*c.x<1ll*x*c.y;}
	bool operator>(const node c)const{return c<*this;}
	node operator+(const node c)const{return node(x+c.x,y+c.y);}
}val[200005],sum[200005];

mt19937 mrand(1);
int n,q,tot,ncnt;
int ch[200005][2],siz[200005],v[400005],nxt[400005],h[200005],son[200005],sz[200005],rt[200005],ans[200005];
vector<pii> qry[200005];

void addedge(int x,int y){
	v[++tot]=y; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; nxt[tot]=h[y]; h[y]=tot;
}

void dfs1(int u,int fa){
	sz[u]=1;
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==fa) continue;
		dfs1(v[p],u);
		sz[u]+=sz[v[p]];
		if(sz[v[p]]>sz[son[u]]) son[u]=v[p];
	}
}

void update(int u){
	siz[u]=1+siz[ch[u][0]]+siz[ch[u][1]];
	sum[u]=val[u]+sum[ch[u][0]]+sum[ch[u][1]];
}

void split(int u,node k,int &x,int &y){
	if(!u) return (void)(x=y=0);
	if(!(val[u]<k)) x=u,split(ch[u][1],k,ch[x][1],y);
	else y=u,split(ch[u][0],k,x,ch[y][0]);
	update(u);
}

int merge(int x,int y){
	if(!x||!y) return x+y;
	if(mrand()%(siz[x]+siz[y])<siz[x]){
		ch[x][1]=merge(ch[x][1],y); update(x);
		return x;
	}
	else{
		ch[y][0]=merge(x,ch[y][0]); update(y);
		return y;
	}
}

void dfs3(int u,int &t){
	if(!u) return;
	int ta,tb;
	split(t,val[u],ta,tb);
	dfs3(ch[u][0],ta);
	dfs3(ch[u][1],tb);
	ch[u][0]=ch[u][1]=0;
	update(u);
	t=merge(merge(ta,u),tb);
}

int getlf(int u){
	while(ch[u][0]) u=ch[u][0];
	return u;
}

void dfs2(int u,int fa){
	for(int p=h[u];p;p=nxt[p]) if(v[p]!=fa&&v[p]!=son[u]) dfs2(v[p],u);
	int num=-1;
	if(son[u]) dfs2(son[u],u),rt[u]=rt[son[u]],num++;
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==fa||v[p]==son[u]) continue;
		dfs3(rt[v[p]],rt[u]);
		num++;
	}
	int a,b;
	for(auto r:qry[u]){
		node tmp(1,r.fi);
		split(rt[u],tmp,a,b);
		ans[r.se]=sum[a].y-1ll*r.fi*sum[a].x+num+1;
		rt[u]=merge(a,b);
	}
	node th(1,num);
	while(siz[rt[u]]>=1){
		int tmp=getlf(rt[u]);
		if(th>val[tmp]) break;
		split(rt[u],val[tmp],a,b);
		th=th+val[a];
		rt[u]=merge(merge(ch[a][0],ch[a][1]),b);
	}
	ncnt++;
	val[ncnt]=sum[ncnt]=th,siz[ncnt]=1;
	rt[u]=merge(ncnt,rt[u]);
}

int main(){
	n=readint();
	for(int i=1;i<n;i++) addedge(readint(),readint());
	q=readint();
	for(int i=1;i<=q;i++){
		int x=readint(),y=readint();
		qry[x].pb(mp(y,i));
	}
	dfs1(1,-1);
	dfs2(1,-1);
	for(int i=1;i<=q;i++) printf("%d\n",ans[i]);
	return 0;
}