#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

struct node{
	int sp,fr,pl,all,now;
	node(int sp=0,int fr=0,int pl=0,int all=0,int now=0):sp(sp),fr(fr),pl(pl),all(all),now(now){}
	bool operator>(const node c)const{return sp==c.sp?fr>c.fr:sp>c.sp;}
};

int n,q,m,k,ntot,top,tot,ncnt;
int v[400005],nxt[400005],h[200005],f[200005][20],dep[200005],s[200005],dfn[200005],col[200005],p[400005],a[400005],b[400005],g[400005];
bool hm[200005];
vector<pii> adj[200005];
priority_queue<node,vector<node>,greater<node> > st;

void addedge(int x,int y){
	v[++tot]=y; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; nxt[tot]=h[y]; h[y]=tot;
}

void dfs1(int u){
	dfn[u]=++ncnt;
	for(int i=1;i<=19;i++) f[u][i]=f[f[u][i-1]][i-1];
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==f[u][0]) continue;
		f[v[p]][0]=u,dep[v[p]]=dep[u]+1;
		dfs1(v[p]);
	}
}

int lca(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=19;i>=0;i--) if(dep[f[x][i]]>=dep[y]) x=f[x][i];
	if(x==y) return x;
	for(int i=19;i>=0;i--) if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
	return f[x][0];
}

void insert(int x){
	if(!top) return (void)(s[++top]=x);
	if(lca(x,s[top])==s[top]) return (void)(s[++top]=x);
	int tmp=s[top];
	while(top>1&&dfn[tmp=lca(x,s[top])]<=dfn[s[top-1]]){
		adj[s[top-1]].push_back(mp(s[top],dep[s[top]]-dep[s[top-1]]));
		adj[s[top]].push_back(mp(s[top-1],dep[s[top]]-dep[s[top-1]]));
		top--;
	}
	if(s[top]!=tmp){
		adj[tmp].push_back(mp(s[top],dep[s[top]]-dep[tmp]));
		adj[s[top]].push_back(mp(tmp,dep[s[top]]-dep[tmp]));
		s[top]=tmp;
	}
	s[++top]=x;
}

void dfs2(int u,node tmp){
	col[u]=tmp.fr;
	for(auto v:adj[tmp.pl]){
		if(col[v.fi]||hm[v.fi]) continue;
		if(v.se+tmp.now<=tmp.all) dfs2(v.fi,node(tmp.sp,tmp.fr,v.fi,tmp.all,v.se+tmp.now));
		else st.push(node(tmp.sp+(v.se+tmp.now-1)/tmp.all,tmp.fr,v.fi,tmp.all,(v.se+tmp.now-1)%tmp.all+1));
	}
}

void reset(int u,int fa){
	col[u]=0;
	for(auto v:adj[u]){
		if(v.fi==fa) continue;
		reset(v.fi,u);
	}
	adj[u].clear();
}

int main(){
	n=readint();
	for(int i=1;i<n;i++) addedge(readint(),readint());
	dfs1(1);
	q=readint();
	while(q--){
		k=readint(); m=readint();
		for(int i=1;i<=k;i++) p[i]=a[i]=readint(),b[i]=readint(),hm[a[i]]=1;
		for(int i=1;i<=m;i++) g[i]=p[k+i]=readint();
		sort(p+1,p+m+k+1,[&](int x,int y){return dfn[x]<dfn[y];});
		ntot=unique(p+1,p+m+k+1)-p-1;
		top=0;
		if(p[1]!=1) insert(1);
		for(int i=1;i<=ntot;i++) insert(p[i]);
		while(top>1){
			adj[s[top-1]].push_back(mp(s[top],dep[s[top]]-dep[s[top-1]]));
			adj[s[top]].push_back(mp(s[top-1],dep[s[top]]-dep[s[top-1]]));
			top--;
		}
//		cout<<"edges "<<endl;
//		for(int i=1;i<=n;i++) for(auto v:adj[i]) cout<<"from "<<i<<' '<<"to "<<v.fi<<' '<<v.se<<endl;
		for(int i=1;i<=k;i++) st.push(node(0,i,a[i],b[i],0));
		while(!st.empty()){
			node tmp=st.top(); st.pop();
//			cout<<"test "<<tmp.pl<<' '<<tmp.fr<<endl;
			if(col[tmp.pl]) continue;
			dfs2(tmp.pl,tmp);
		}
//		cout<<"ans "<<endl;
		for(int i=1;i<=m;i++) printf("%d ",col[g[i]]);
		printf("\n");
		reset(1,-1);
		for(int i=1;i<=k;i++) hm[a[i]]=0;
	}
	return 0;
}