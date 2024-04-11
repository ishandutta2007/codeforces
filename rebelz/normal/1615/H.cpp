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

ull readint(){
	ull x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const ll inf=1ll<<60;
int n,m,tot; ll ans=0;
ll a[1005];
ll b[1005],x[1005],y[1005],v[70000],nxt[70000],h[1005],vis[1005],lst[1005];
vector<int> tv;

void addedge(int x,int y){v[++tot]=y; nxt[tot]=h[x]; h[x]=tot;}

namespace network{
	int tot,src,sink;
	int h[1005],v[500005],nxt[500005],rev[500005],lev[1005],q[1005];
	ll c[500005];
	void addedge(int x,int y,ll z){
//		cout<<"edge "<<x<<' '<<y<<' '<<z<<endl;
		v[++tot]=y; c[tot]=z; nxt[tot]=h[x]; rev[tot]=tot+1; h[x]=tot;
		v[++tot]=x; c[tot]=0; nxt[tot]=h[y]; rev[tot]=tot-1; h[y]=tot;
		assert(tot<=500000);
	}
	bool bfs(){
		memset(lev,-1,sizeof(lev));
		int front=0,rear=0;
		q[rear++]=src,lev[src]=0;
		while(front<rear){
			int t=q[front++];
			for(int p=h[t];p;p=nxt[p]){
				if(c[p]&&lev[v[p]]<0){
					lev[v[p]]=lev[t]+1;
					q[rear++]=v[p];
				}
			}
			if(lev[sink]>=0) return true;
		}
		return false;
	}
	ll dfs(int u,ll low){
		if(u==sink) return low;
		ll res=0;
		for(int p=h[u];p;p=nxt[p]){
			if(c[p]&&lev[v[p]]==lev[u]+1){
				ll flow=dfs(v[p],min(low,c[p]));
				low-=flow,c[p]-=flow,c[rev[p]]+=flow,res+=flow;
				if(low<=0) break;
			}
		}
		if(!res) lev[u]=-1;
		return res;
	}
	ll dinic(){
		ll res=0;
		while(bfs()) res+=dfs(src,inf);
		return res;
	}
}

int tcnt,scnt;
int dfn[1005],low[1005],col[1005];
vector<int> bel[1005];
stack<int> stk;
map<int,int> bk[1005];
bool ins[1005];

void tarjan(int u){
	dfn[u]=low[u]=++tcnt;
	stk.push(u); ins[u]=1;
	for(int p=h[u];p;p=nxt[p]){
		if(!dfn[v[p]]) tarjan(v[p]),chkmin(low[u],low[v[p]]);
		else if(ins[v[p]]) chkmin(low[u],dfn[v[p]]);
	}
	if(dfn[u]==low[u]){
		int tmp;
		scnt++;
		do{
			tmp=stk.top(); stk.pop();
			col[tmp]=scnt,ins[tmp]=0;
			bel[scnt].pb(tmp);
		}while(tmp!=u);
	}
}

void init(){
	for(int i=1;i<=n;i++) if(!dfn[i]) tarjan(i);
	for(int i=1;i<=n;i++) h[i]=0; tot=0;
	for(int i=1;i<=m;i++)
		if(col[x[i]]!=col[y[i]]&&!bk[col[x[i]]].count(col[y[i]]))
			addedge(col[x[i]],col[y[i]]),bk[col[x[i]]][col[y[i]]]=1;
	n=scnt;
}

void dfs(int u){
	tv.pb(u);
	for(int p=network::h[u];p;p=network::nxt[p])
		if(network::c[p]&&!vis[network::v[p]])
			vis[network::v[p]]=1,dfs(network::v[p]);
}

ll getval(int x,ll t){
	ll ret=0;
	for(auto r:bel[x]) ret+=abs(a[r]-t);
	return ret;
}

void solve(vector<int> &x,ll l,ll r){
	if(!x.size()) return;
//	cout<<"solve "<<l<<' '<<r<<endl;
//	for(auto c:x) cout<<c<<' ';
//	cout<<endl;
	if(l==r){
		for(int i=0;i<x.size();i++) ans+=getval(x[i],l),lst[x[i]]=l;
		return;
	}
	ll mid=(l+r)/2;
	for(int i=0;i<x.size();i++) vis[x[i]]=i+1;
	for(int i=0;i<=x.size()+1;i++) network::h[i]=0; network::tot=0;
	network::src=0,network::sink=x.size()+1;
	for(int i=1;i<=x.size();i++){
		network::addedge(0,i,getval(x[i-1],mid));
		network::addedge(i,x.size()+1,getval(x[i-1],mid+1));
	}
	for(int i=1;i<=x.size();i++)
		for(int p=h[x[i-1]];p;p=nxt[p])
			if(vis[v[p]])
				network::addedge(i,vis[v[p]],inf);
	network::dinic();
	for(int i=0;i<x.size();i++) vis[x[i]]=0;
	vector<int> lson(0),rson(0);
	tv.clear();
	dfs(0);
	for(int i=1;i<=x.size();i++){
		if(vis[i]) rson.pb(x[i-1]);
		else lson.pb(x[i-1]);
	}
	for(int i=1;i<=x.size();i++) vis[i]=0;
	solve(lson,l,mid);
	solve(rson,mid+1,r);
}

int main(){
//	mt19937 mrand(12349034);
	n=readint(); m=readint();
//	n=1000,m=999;
	int nn=n;
	for(int i=1;i<=n;i++) a[i]=readint();
//	for(int i=1;i<=n;i++) a[i]=mrand()%1000000000+1;
	for(int i=1;i<=m;i++){
		x[i]=readint(); y[i]=readint();
//		x[i]=i,y[i]=i+1;
		addedge(x[i],y[i]);
	}
	init();
	vector<int> tmp(0);
	for(int i=1;i<=n;i++) tmp.pb(i);
	solve(tmp,-1e16,1e16);
//	printf("%lld\n",ans);
	for(int i=1;i<=nn;i++) printf("%lld ",lst[col[i]]);
	printf("\n");
	return 0;
}