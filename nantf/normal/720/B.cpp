#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=888888,mod=998244353;
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
inline int qmo(int x){return x+(x>>31?mod:0);}
int n,m,el,head[maxn],to[maxn],nxt[maxn],w[maxn],dfn[maxn],low[maxn],cnt,stk[maxn],tp,c,vc,fa[maxn];
map<PII,int> col;
map<int,int> mp;
vector<int> vv[maxn];
bool in[maxn],in2[maxn];
inline void add(int u,int v,int ww){
	to[++el]=v;nxt[el]=head[u];head[u]=el;w[el]=ww;
}
void dfs(int u,int f){
	dfn[u]=low[u]=++cnt;
	stk[++tp]=u;
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(v==f) continue;
		if(!dfn[v]){
			dfs(v,u);
			low[u]=min(low[u],low[v]);
			if(low[v]>=dfn[u]){
				vector<int> v1,v2;
				do v1.PB(stk[tp]); while(stk[tp--]!=v);
				v1.PB(u);
				if((int)v1.size()<3) continue;
				FOR(j,0,(int)v1.size()-1){
					int x=v1[j],y=v1[(j+1)%v1.size()];
					v2.PB(col[MP(x,y)]);
					col.erase(MP(x,y));
					col.erase(MP(y,x));
				}
				sort(v2.begin(),v2.end());v2.resize(unique(v2.begin(),v2.end())-v2.begin());
				if(v1.size()!=v2.size()) FOR(j,0,(int)v2.size()-1) in[v2[j]]=true;
				else vv[++vc]=v2;
			}
		}
		else low[u]=min(low[u],dfn[v]);
	}
}
inline int getfa(int x){
	return x==fa[x]?x:fa[x]=getfa(fa[x]);
}
inline bool unite(int x,int y){
	x=getfa(x);y=getfa(y);
	if(x==y) return true;
	return fa[x]=y,false;
}
int main(){
	n=read();m=read();
	FOR(i,1,m){
		int u=read(),v=read(),w=read();
		if(!mp.count(w)) mp[w]=++c;
		w=mp[w];
		add(u,v,w);add(v,u,w);
		col[MP(u,v)]=col[MP(v,u)]=w;
	}
	FOR(i,1,n) if(!dfn[i]) dfs(i,0);
	for(auto it=col.begin();it!=col.end();it++) in[it->second]=true;
	FOR(i,1,c+vc) fa[i]=i;
	FOR(i,1,vc) FOR(j,0,(int)vv[i].size()-1) if(unite(vv[i][j],i+c)) in[vv[i][j]]=true;
	FOR(i,1,c) if(in[i]) in2[getfa(i)]=true;
	int ans=c;
	FOR(i,1,c+vc) if(i==getfa(i) && !in2[i]) ans--;
	printf("%d\n",ans);
}