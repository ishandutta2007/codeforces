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

int n,m,ss,tot,scnt,ncnt,mcnt;
int v[400005],nxt[400005],h[200005],du[200005],dfn[200005],low[200005],siz[200005],bel[200005],q[200005],d[200005];
vector<int> ans,adj[200005];
stack<int> s;
bool ins[200005],vis[200005];
pii e[200005];

void addedge(int x,int y){v[++tot]=y; nxt[tot]=h[x]; h[x]=tot;}

void tarjan(int u){
	dfn[u]=low[u]=++ncnt;
	s.push(u); ins[u]=1;
	for(int p=h[u];p;p=nxt[p]){
		if(!dfn[v[p]]) tarjan(v[p]),chkmin(low[u],low[v[p]]);
		else if(ins[v[p]]) chkmin(low[u],dfn[v[p]]);
	}
	if(dfn[u]==low[u]){
		scnt++;
		do{
			bel[u]=scnt,siz[scnt]++;
			u=s.top(); s.pop(); ins[u]=0;
		}while(dfn[u]!=low[u]);
	}
}

bool dfs(int u){
	if(!h[u]&&u>n){
		ans.push_back(u-n);
		return true;
	}
	for(int p=h[u];p;p=nxt[p]){
		if(vis[v[p]]) continue;
		vis[v[p]]=1;
		if(dfs(v[p])){
			ans.push_back((u-1)%n+1);
			return true;
		}
	}
	return false;
}

int main(){
	n=readint(); m=readint();
	int x,y;
	for(int i=1;i<=n;i++){
		x=readint();
		while(x--){
			y=readint();
			e[++mcnt]=mp(i,y);
		}
	}
	ss=readint();
	for(int i=1;i<=m;i++){
		addedge(e[i].fi,e[i].se+n);
		addedge(e[i].fi+n,e[i].se);
	}
	vis[ss]=1;
	if(dfs(ss)){
		reverse(ans.begin(),ans.end());
		printf("Win\n");
		for(auto x:ans) printf("%d ",x);
		printf("\n");
		return 0;
	}
	memset(h,0,sizeof(h)); tot=0;
	for(int i=1;i<=m;i++) addedge(e[i].fi,e[i].se);
	for(int i=1;i<=n;i++) if(!dfn[i]) tarjan(i);
	for(int i=1;i<=m;i++) if(bel[e[i].fi]!=bel[e[i].se]) adj[bel[e[i].fi]].push_back(bel[e[i].se]),du[bel[e[i].se]]++;
	int front=0,rear=0;
	for(int i=1;i<=scnt;i++) if(!du[i]) q[rear++]=i;
	while(front<rear){
		int t=q[front++];
		for(auto v:adj[t]) if(!(--du[v])) q[rear++]=v;
	}
	for(int i=rear-1;i>=0;i--){
		int u=q[i];
		if(!adj[u].size()&&siz[u]>1) d[u]=-1;
		for(auto v:adj[u]) if(d[v]||siz[u]>1) d[u]=-1;
	}
	if(d[bel[ss]]) printf("Draw\n");
	else printf("Lose\n");
	return 0;
}