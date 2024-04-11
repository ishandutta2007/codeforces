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
	int opt,pt,val;
	bool operator<(const node c)const{return val>c.val;}
	node(int opt=0,int pt=0,int val=0):opt(opt),pt(pt),val(val){}
};

const int cys=1000000007;
int n,m,tot,ncnt,pcnt;
int v[200005],nxt[200005],h[100005],dfn[100005],siz[100005],f[100005][20],x[100005],y[100005],z[100005],now[100005];
int prm[1000005],p0[10000005],dep[100005];
ll ans[100005];
bool fl[10000005];
vector<pii> vec[1000005],qry[1000005];

struct bit{
	int timer;
	int c[100005],mark[100005];
	void add(int x,int v){
		for(;x<=n;x+=(x&(-x))){
			if(mark[x]!=timer) mark[x]=timer,c[x]=0;
			c[x]+=v;
		}
	}
	int ask(int x){int ret=0; for(;x;x-=(x&(-x))) ret+=(mark[x]==timer?c[x]:0); return ret;}
}T[2];

ll qpow(ll x,ll p){
	ll ret=1;
	for(;p;p>>=1,x=x*x%cys) if(p&1) ret=ret*x%cys;
	return ret;
}

void getprime(int m){
	fl[1]=1;
	for(int i=2;i<=m;i++){
		if(!fl[i]) prm[++pcnt]=i,p0[i]=pcnt;
		for(int j=1;j<=pcnt&&i*prm[j]<=m;j++){
			fl[i*prm[j]]=1,p0[i*prm[j]]=j;
			if(i%prm[j]==0) break;
		}
	}
}

int getnum(int x,int y,int l){return T[0].ask(dfn[x])+T[0].ask(dfn[y])-T[0].ask(dfn[l])-T[0].ask(dfn[f[l][0]]);}
int getsum(int x,int y,int l){return T[1].ask(dfn[x])+T[1].ask(dfn[y])-T[1].ask(dfn[l])-T[1].ask(dfn[f[l][0]]);}

void change(int x,int y){
	T[0].add(dfn[x],1),T[1].add(dfn[x],y);
	if(dfn[x]+siz[x]<=n) T[0].add(dfn[x]+siz[x],-1),T[1].add(dfn[x]+siz[x],-y);
}

void addedge(int x,int y){
	v[++tot]=y; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; nxt[tot]=h[y]; h[y]=tot;
}

void dfs(int u,int fa){
	dfn[u]=++ncnt,siz[u]=1;
	for(int i=1;i<=19;i++) f[u][i]=f[f[u][i-1]][i-1];
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==fa) continue;
		f[v[p]][0]=u,dep[v[p]]=dep[u]+1;
		dfs(v[p],u);
		siz[u]+=siz[v[p]];
	}
}

int lca(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=19;i>=0;i--) if(dep[f[x][i]]>=dep[y]) x=f[x][i];
	if(x==y) return x;
	for(int i=19;i>=0;i--) if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
	return f[x][0];
}

int main(){
	getprime(10000000);
	n=readint();
	for(int i=1;i<n;i++) addedge(readint(),readint());
	dep[1]=1; dfs(1,-1);
	for(int i=1;i<=n;i++){
		int tmp=readint();
		while(tmp>1){
			int t=p0[tmp],num=0;
			while(tmp%prm[t]==0) tmp/=prm[t],num++;
			vec[t].pb(mp(i,num));
		}
	}
	m=readint();
	for(int i=1;i<=m;i++){
		x[i]=readint(); y[i]=readint(); z[i]=lca(x[i],y[i]);
		int tmp=readint();
		while(tmp>1){
			int t=p0[tmp],num=0;
			while(tmp%prm[t]==0) tmp/=prm[t],num++;
			qry[t].pb(mp(i,num));
		}
	}
	for(int i=1;i<=m;i++) ans[i]=1;
	for(int i=1;i<=pcnt;i++){
		if(!vec[i].size()&&!qry[i].size()) continue;
		vector<node> cur(0);
		for(auto r:vec[i]) cur.pb(node(0,r.fi,r.se));
		for(auto r:qry[i]) cur.pb(node(1,r.fi,r.se));
		sort(cur.begin(),cur.end());
		T[0].timer++,T[1].timer++;
		for(auto r:cur){
			if(r.opt==1) now[r.pt]+=r.val*getnum(x[r.pt],y[r.pt],z[r.pt])-getsum(x[r.pt],y[r.pt],z[r.pt]);
			else change(r.pt,r.val);
		}
		for(auto r:qry[i]) ans[r.fi]=ans[r.fi]*qpow(prm[i],now[r.fi]+getsum(x[r.fi],y[r.fi],z[r.fi]))%cys,now[r.fi]=0;
	}
	for(int i=1;i<=m;i++) printf("%lld\n",ans[i]);
	return 0;
}