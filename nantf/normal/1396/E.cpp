#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=100010,mod=998244353;
#define MP make_pair
#define PB push_back
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline ll read(){
	char ch=getchar();ll x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int n,el,head[maxn],to[maxn*2],nxt[maxn*2],sz[maxn],son[maxn],rt,dep[maxn],tmp[maxn],tl,ans[maxn][2],al,fa[maxn];
ll k,lwr,upr;
vector<int> v[maxn],sss[maxn];
bool del[maxn];
struct cmp1{
	bool operator()(int x,int y){return sz[x]<sz[y];}
};
priority_queue<int,vector<int>,cmp1> pq;
inline void add(int u,int v){
	to[++el]=v;nxt[el]=head[u];head[u]=el;
}
inline bool cmp(int x,int y){return dep[x]<dep[y];}
void dfs(int u,int f){
	sz[u]=1;
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(v==f) continue;
		dfs(v,u); 
		sz[u]+=sz[v];
		son[u]=max(son[u],sz[v]);
	}
	son[u]=max(son[u],n-sz[u]);
	if(son[u]<=n/2) rt=u;
}
void dfs1(int u,int f,int hhh){
	if(hhh && !del[u]) v[hhh].PB(u);
	if(!del[u]) sz[u]=1;
	else sz[u]=0;
	dep[u]=f?dep[f]+1:0;
	sss[u].clear();
	fa[u]=f;
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(v==f) continue;
		if(!f) ::v[v].clear();
		dfs1(v,u,f?hhh:v);
		sz[u]+=sz[v];
		sss[u].PB(v);
		if(!f){
			if(sz[v]) pq.push(v);
			sort(::v[v].begin(),::v[v].end(),cmp);
		}
	}
}
int main(){
	n=read();k=read();
	FOR(i,1,n-1){
		int u=read(),v=read();
		add(u,v);add(v,u);
	}
	dfs(1,0);
	dfs1(rt,0,0);
	FOR(i,1,n) lwr+=sz[i]%2,upr+=dep[i];
	if(k<lwr || k>upr || k%2!=upr%2) return puts("NO"),0;
	puts("YES");
	k=(upr-k)/2;
	while(k){
		int u=pq.top();pq.pop();
		sz[u]-=2;
		pq.push(u);
		while(sss[v[u].back()].empty() || dep[v[u].back()]>k) v[u].pop_back();
		int x=v[u].back();
		del[ans[++al][0]=sss[x].back()]=true;
		while(!sss[x].empty() && del[sss[x].back()]) sss[x].pop_back();
		if(sss[x].empty()){
			del[ans[al][1]=x]=true;
			while(!sss[fa[x]].empty() && del[sss[fa[x]].back()]) sss[fa[x]].pop_back();
		}
		else{
			del[ans[al][1]=sss[x].back()]=true,sss[x].pop_back();
			while(!sss[x].empty() && del[sss[x].back()]) sss[x].pop_back();
		}
		k-=dep[x];
	}
	while(!pq.empty()) pq.pop();
	dfs1(rt,0,0);
	sz[rt]=1;
	v[rt].PB(rt);
	pq.push(rt);
	while(!pq.empty()){
		int u=pq.top();pq.pop();
		int v=pq.top();pq.pop();
		ans[++al][0]=::v[u].back();
		::v[u].pop_back();
		sz[u]--;
		if(!::v[u].empty()) pq.push(u);
		ans[al][1]=::v[v].back();
		::v[v].pop_back();
		sz[v]--;
		if(!::v[v].empty()) pq.push(v);
	}
	FOR(i,1,al) printf("%d %d\n",ans[i][0],ans[i][1]);
}