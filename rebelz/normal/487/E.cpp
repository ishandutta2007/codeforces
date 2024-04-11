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

struct heap{
	priority_queue<int,vector<int>,greater<int> > q1,q2;
	void update(){while(!q1.empty()&&!q2.empty()&&q1.top()==q2.top()) q1.pop(),q2.pop();}
	void insert(int x){q1.push(x);}
	void erase(int x){q2.push(x); update();}
	int top(){return q1.top();}
}hp[200005];

int n,m,q,ncnt,tot,scnt;
int dfn[200005],low[200005],mina[600000],son[200005],f[200005],dep[200005],v[200005],nxt[200005],h[100005],siz[200005],a[100005],top[200005];
vector<int> adj[200005];
stack<int> stk;

void addedge(int x,int y){
	v[++tot]=y; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; nxt[tot]=h[y]; h[y]=tot;
}

void tarjan(int u){
	dfn[u]=low[u]=++ncnt;
	stk.push(u);
	for(int p=h[u];p;p=nxt[p]){
		if(!dfn[v[p]]){
			tarjan(v[p]);
			chkmin(low[u],low[v[p]]);
			if(low[v[p]]==dfn[u]){
				scnt++;
				int tmp;
				do{
					tmp=stk.top(); stk.pop();
					adj[scnt+n].pb(tmp);
					adj[tmp].pb(scnt+n);
				}while(tmp!=v[p]);
				adj[scnt+n].pb(u);
				adj[u].pb(scnt+n);
			}
		}
		else chkmin(low[u],dfn[v[p]]);
	}
}

void change(int id,int l,int r,int x,int c){
	if(l==r) return (void)(mina[id]=c);
	int mid=(l+r)/2;
	if(x<=mid) change(id<<1,l,mid,x,c);
	else change(id<<1|1,mid+1,r,x,c);
	mina[id]=min(mina[id<<1],mina[id<<1|1]);
}

int query(int id,int l,int r,int ql,int qr){
	if(l==ql&&r==qr) return mina[id];
	int mid=(l+r)/2;
	if(qr<=mid) return query(id<<1,l,mid,ql,qr);
	else if(ql>mid) return query(id<<1|1,mid+1,r,ql,qr);
	else return min(query(id<<1,l,mid,ql,mid),query(id<<1|1,mid+1,r,mid+1,qr));
}

void dfs1(int u,int fa){
	siz[u]=1;
	for(auto v:adj[u]){
		if(v==fa) continue;
		if(u>n) hp[u].insert(a[v]);
		dep[v]=dep[u]+1,f[v]=u;
		dfs1(v,u);
		siz[u]+=siz[v];
		if(siz[v]>siz[son[u]]) son[u]=v;
	}
}

void dfs2(int u,int fa){
	dfn[u]=++ncnt;
	if(u>n) change(1,1,n+scnt,dfn[u],hp[u].top());
	else change(1,1,n+scnt,dfn[u],1<<30);
	if(son[u]) top[son[u]]=top[u],dfs2(son[u],u);
	for(auto v:adj[u]){
		if(v==fa||v==son[u]) continue;
		top[v]=v;
		dfs2(v,u);
	}
}

int getans(int x,int y){
	int ret=1<<30;
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		chkmin(ret,query(1,1,n+scnt,dfn[top[x]],dfn[x]));
		x=f[top[x]];
	}
	if(dfn[x]>dfn[y]) swap(x,y);
	chkmin(ret,query(1,1,n+scnt,dfn[x],dfn[y]));
	if(x>n) chkmin(ret,a[f[x]]);
	else chkmin(ret,a[x]);
	return ret;
}

int main(){
	n=readint(); m=readint(); q=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	for(int i=1;i<=m;i++) addedge(readint(),readint());
	tarjan(1);
	ncnt=0;
	dep[1]=1; dfs1(1,-1);
	top[1]=1; dfs2(1,-1);
	char opt[2]; int x,y;
	while(q--){
		scanf("%s",opt);
		x=readint(); y=readint();
		if(opt[0]=='C'){
			if(f[x]>n){
				hp[f[x]].erase(a[x]),hp[f[x]].insert(y);
				change(1,1,n+scnt,dfn[f[x]],hp[f[x]].top());
			}
			a[x]=y;
		}
		else printf("%d\n",getans(x,y));
	}
	return 0;
}