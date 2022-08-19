// xtqqwq
#include<bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;

template <typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m,q;
pii e[300005];

namespace work1{
	int tot,scnt,ccnt,ncnt;
	int dfn[300005],low[300005],v[600005],nxt[600005],h[300005],knd[300005],bel[300005],rt[300005],f[300005][20],dep[300005];
	vector<int> adj[300005];
	map<pii,int> bk;
	stack<int> stk;
	void addedge(int x,int y){
		v[++tot]=y; nxt[tot]=h[x]; h[x]=tot;
		v[++tot]=x; nxt[tot]=h[y]; h[y]=tot;
	}
	void tarjan(int u,int fa){
		dfn[u]=low[u]=++ncnt;
		stk.push(u);
		for(int p=h[u];p;p=nxt[p]){
			if(v[p]==fa){
				fa=0;
				continue;
			}
			if(!dfn[v[p]]){
				tarjan(v[p],u);
				chkmin(low[u],low[v[p]]);
			}
			else chkmin(low[u],dfn[v[p]]);
		}
		if(dfn[u]==low[u]){
			scnt++;
			knd[scnt]=ccnt;
			int tmp;
			do{
				tmp=stk.top(); stk.pop();
				bel[tmp]=scnt;
			}while(tmp!=u);
		}
	}
	void dfs(int u,int fa){
		dfn[u]=++ncnt;
		for(int i=1;i<=18;i++) f[u][i]=f[f[u][i-1]][i-1];
		for(auto v:adj[u]){
			if(v==fa) continue;
			f[v][0]=u,dep[v]=dep[u]+1;
			dfs(v,u);
		}
	}
	int lca(int x,int y){
		if(dep[x]<dep[y]) swap(x,y);
		for(int i=18;i>=0;i--) if(dep[f[x][i]]>=dep[y]) x=f[x][i];
		if(x==y) return x;
		for(int i=18;i>=0;i--) if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
		return f[x][0];
	}
	void work(){
		for(int i=1;i<=n;i++) if(!dfn[i]) ccnt++,rt[ccnt]=i,tarjan(i,-1);
		for(int i=1;i<=m;i++){
			if(bel[e[i].fi]!=bel[e[i].se]){
				int x=bel[e[i].fi],y=bel[e[i].se];
				if(!bk.count(mp(x,y))) bk[mp(x,y)]=1,adj[x].pb(y),adj[y].pb(x);
			}
		}
		ncnt=0;
		for(int i=1;i<=ccnt;i++) dep[bel[rt[i]]]=1,dfs(bel[rt[i]],-1);
	}
}

namespace work2{
	int k,ncnt,top,tot,scnt;
	int v[1200005],nxt[1200005],h[300005],s[300005],dfn[300005],low[300005],bel[300005],a[1800005];
	bool hv[300005];
	vector<int> gar;
	stack<int> stk;
	void addedge(int x,int y){
		if(!hv[x]) hv[x]=1,gar.pb(x);
		if(!hv[y]) hv[y]=1,gar.pb(y);
		v[++tot]=y; nxt[tot]=h[x]; h[x]=tot;
		v[++tot]=x; nxt[tot]=h[y]; h[y]=tot;
	}
	void insert(int x){
		if(!top) return (void)(s[++top]=x);
		while(top>1&&work1::dep[work1::lca(s[top],x)]<=work1::dep[s[top-1]]) addedge(s[top-1],s[top]),top--;
		int tmp=work1::lca(s[top],x);
		if(tmp!=s[top]) addedge(tmp,s[top]),s[top]=tmp;
		s[++top]=x;
	}
	void tarjan(int u,int fa){
		dfn[u]=low[u]=++ncnt;
		stk.push(u);
		for(int p=h[u];p;p=nxt[p]){
			if(v[p]==fa){
				fa=0;
				continue;
			}
			if(!dfn[v[p]]){
				tarjan(v[p],u);
				chkmin(low[u],low[v[p]]);
			}
			else chkmin(low[u],dfn[v[p]]);
		}
		if(dfn[u]==low[u]){
			scnt++;
			int tmp;
			do{
				tmp=stk.top(); stk.pop();
				bel[tmp]=scnt;
			}while(tmp!=u);
		}
	}
	bool work(vector<int> pt,vector<pii> eg){
		k=pt.size();
		for(int i=1;i<=k;i++) a[i]=pt[i-1];
		for(auto r:eg) a[++k]=r.fi,a[++k]=r.se,a[++k]=work1::bel[work1::rt[work1::knd[r.fi]]],a[++k]=work1::bel[work1::rt[work1::knd[r.se]]];
		for(auto r:pt) a[++k]=work1::bel[work1::rt[work1::knd[r]]];
		sort(a+1,a+k+1,[&](int x,int y){return work1::dfn[x]<work1::dfn[y];});
		k=unique(a+1,a+k+1)-a-1;
		top=0;
		for(int i=1;i<=k;i++){
			if(a[i]==work1::bel[work1::rt[work1::knd[a[i]]]]){
				while(top>1) addedge(s[top-1],s[top]),top--;
				top=0;
			}
			insert(a[i]);
		}
		while(top>1) addedge(s[top-1],s[top]),top--;
		for(auto r:eg) if(r.fi!=r.se) addedge(r.fi,r.se);
		for(int i=1;i<=k;i++) if(!hv[a[i]]) hv[a[i]]=1,gar.pb(a[i]);
		scnt=ncnt=0;
		for(auto r:gar) if(!dfn[r]) tarjan(r,-1);
		int now=-1,fl=1;
		for(auto r:pt){
			if(now<0) now=bel[r];
			else if(now!=bel[r]) fl=0;
		}
		for(auto r:gar) h[r]=hv[r]=dfn[r]=0; tot=0;
		gar.clear();
		return fl;
	}
}

int main(){
	n=readint(); m=readint(); q=readint();
	for(int i=1;i<=m;i++){
		e[i].fi=readint(); e[i].se=readint();
		if(e[i].fi!=e[i].se) work1::addedge(e[i].fi,e[i].se);
	}
	work1::work();
	int R=0;
	for(int j=1;j<=q;j++){
		vector<int> pt(0);
		vector<pii> eg(0);
		pt.resize(readint());
		eg.resize(readint());
		for(int i=0;i<pt.size();i++) pt[i]=work1::bel[(readint()+R-1)%n+1];
		for(int i=0;i<eg.size();i++) eg[i].fi=work1::bel[(readint()+R-1)%n+1],eg[i].se=work1::bel[(readint()+R-1)%n+1];
		if(work2::work(pt,eg)) printf("YES\n"),R=(R+j)%n;
		else printf("NO\n");
	}
	return 0;
}