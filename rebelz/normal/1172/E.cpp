// xtqqwq
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

int n,m,tot,ncnt,timer;
int a[400005],siz[400005],dfn[400005],rnk[400005],top[400005],son[400005],f[400005],dep[400005],v[800005],nxt[800005],h[400005],mark1[400005];
ll sum[400005],now[400005],ans[400005];
vector<pii> vec[400005];
set<int> st;

void addedge(int x,int y){
	v[++tot]=y; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; nxt[tot]=h[y]; h[y]=tot;
}

void dfs1(int u,int fa){
	siz[u]=1;
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==fa) continue;
		dep[v[p]]=dep[u]+1,f[v[p]]=u;
		dfs1(v[p],u);
		siz[u]+=siz[v[p]];
		if(siz[v[p]]>siz[son[u]]) son[u]=v[p];
	}
}

void dfs2(int u,int fa){
	dfn[u]=++ncnt,rnk[ncnt]=u;
	if(son[u]) top[son[u]]=top[u],dfs2(son[u],u);
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==fa||v[p]==son[u]) continue;
		top[v[p]]=v[p];
		sum[u]+=1ll*siz[v[p]]*siz[v[p]];
		dfs2(v[p],u);
	}
}

namespace bit{
	int mark[400005];
	ll val[400005],pre[400005];
	void add(int x,ll c){
		for(;x<=n+1;x+=(x&(-x))){
			if(mark[x]!=timer) mark[x]=timer,val[x]=pre[x];
			val[x]+=c;
		}
	}
	ll ask(int x){
		ll ret=0;
		for(;x;x-=(x&(-x))) ret+=mark[x]==timer?val[x]:pre[x];
		return ret;
	}
}

void clear(int x){
	if(mark1[x]!=timer) mark1[x]=timer,now[x]=sum[x];
}

ll getans(int x){
	ll tmp=0;
	if(son[x]&&st.find(dfn[x]+1)==st.end()) tmp=bit::ask(dfn[x]+1);
	clear(x);
	return now[x]+tmp*tmp;
}

void add(int x){
	if(top[x]==x&&x<=n){
		ll tmp=bit::ask(dfn[x]);
		clear(f[x]);
		now[f[x]]-=tmp*tmp;
	}
	st.insert(dfn[x]);
}

void del(int x){
	if(top[x]==x&&x<=n){
		ll tmp=bit::ask(dfn[x]);
		clear(f[x]);
		now[f[x]]+=tmp*tmp;
	}
	st.erase(dfn[x]);
}

int find(int x){
	while(x){
		auto it=st.upper_bound(dfn[x]);
		int tmp=it==st.begin()?0:*(--it);
		if(tmp<dfn[top[x]]) x=f[top[x]];
		else return rnk[tmp];
	}
	assert(0);
}

void change(int x,int y,ll v){
	while(top[x]!=top[y]){
		clear(f[top[x]]);
		ll tmp=bit::ask(dfn[top[x]]);
		now[f[top[x]]]-=tmp*tmp;
		bit::add(dfn[top[x]],v);
		bit::add(dfn[x]+1,-v);
		now[f[top[x]]]+=(tmp+v)*(tmp+v);
		x=f[top[x]];
	}
	bit::add(dfn[y],v);
	bit::add(dfn[x]+1,-v);
}

int main(){
	n=readint(); m=readint();
	for(int i=1;i<=n;i++) a[i]=readint(),vec[a[i]].pb(mp(0,i));
	for(int i=1;i<n;i++) addedge(readint(),readint());
	addedge(n+1,1);
	int x,y;
	for(int i=1;i<=m;i++){
		x=readint(); y=readint();
		vec[a[x]].pb(mp(i,-x));
		vec[y].pb(mp(i,x));
		a[x]=y;
	}
	dep[n+1]=1; dfs1(n+1,-1);
	top[n+1]=n+1; dfs2(n+1,-1);
	for(int i=1;i<=n+1;i++) bit::add(dfn[i],siz[i]),bit::add(dfn[i]+1,-siz[i]);
	for(int i=1;i<=n+1;i++) bit::pre[i]=bit::val[i];
	for(int i=1;i<=n;i++){
		ans[0]+=1ll*n*n;
		timer++,st.clear();
		add(n+1);
		for(auto r:vec[i]){
			if(r.se<0){
				ans[r.fi]-=getans(-r.se);
				int pl=find(f[-r.se]);
				ans[r.fi]-=getans(pl);
				del(-r.se);
				change(f[-r.se],pl,bit::ask(dfn[-r.se]));
				ans[r.fi]+=getans(pl);
			}
			else{
				int pl=find(r.se);
				ans[r.fi]-=getans(pl);
				change(f[r.se],pl,-bit::ask(dfn[r.se]));
				add(r.se);
				ans[r.fi]+=getans(pl);
				ans[r.fi]+=getans(r.se);
			}
		}
	}
	for(int i=1;i<=m;i++) ans[i]+=ans[i-1];
	for(int i=0;i<=m;i++) printf("%lld\n",1ll*n*n*n-ans[i]);
	return 0;
}