#include<algorithm>
#include<vector>
#include<cctype>
#include<cstdio>
using namespace std;
typedef long long ll;
inline ll readint(){
	ll x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)&&c!='-') c=getchar();
	if(c=='-'){
		f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
const int maxn=1e5+5;
int n,q;
struct edge{
	int v,w;
	edge(int v,int w):v(v),w(w){}
};
vector<edge> g[maxn];
int fa[maxn];
ll dp1[maxn],dp2[maxn],f[maxn];
void dfs1(int u){
	for(int i=0;i<(int)g[u].size();i++){
		int v=g[u][i].v;
		if(v==fa[u]) continue;
		fa[v]=u;
		dfs1(v);
		dp1[u]=max(dp1[u],dp1[v]+g[u][i].w);
	}
}
void dfs2(int u){
	f[u]=max(dp1[u],dp2[u]);
	vector<ll> res1(g[u].size()),res2(g[u].size());
	for(int i=0;i<(int)g[u].size();i++){
		int v=g[u][i].v;
		if(v==fa[u]){
			if(i>0) res1[i]=res1[i-1];
			continue;
		}
		res1[i]=dp1[v]+g[u][i].w;
		if(i>0) res1[i]=max(res1[i],res1[i-1]);
	}
	for(int i=(int)g[u].size()-1;i>=0;i--){
		int v=g[u][i].v;
		if(v==fa[u]){
			if(i<(int)g[u].size()-1) res2[i]=res2[i+1];
			continue;
		}
		res2[i]=dp1[v]+g[u][i].w;
		if(i<(int)g[u].size()-1) res2[i]=max(res2[i],res2[i+1]);
	}
	for(int i=0;i<(int)g[u].size();i++){
		int v=g[u][i].v;
		if(v==fa[u]) continue;
		dp2[v]=dp2[u];
		if(i>0) dp2[v]=max(dp2[v],res1[i-1]);
		if(i<(int)g[u].size()-1) dp2[v]=max(dp2[v],res2[i+1]);
		dp2[v]+=g[u][i].w;
		dfs2(v);
	}
}
int ord[maxn];
bool cmp(int a,int b){
	return f[a]>f[b];
}
int p[maxn],s[maxn];
int findrt(int x){
	return p[x]==x?x:p[x]=findrt(p[x]);
}
void merge(int x,int y){
	x=findrt(x);
	y=findrt(y);
	if(x==y) return;
	if(s[x]>s[y]) swap(x,y);
	p[x]=y;
	s[y]+=s[x];
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	for(int i=1;i<n;i++){
		int x,y,v;
		x=readint();
		y=readint();
		v=readint();
		g[x].push_back(edge(y,v));
		g[y].push_back(edge(x,v));
	}
	dfs1(1);
	dfs2(1);
	for(int i=1;i<=n;i++) ord[i]=i;
	sort(ord+1,ord+n+1,cmp);
	q=readint();
	while(q--){
		ll l=readint();
		for(int i=1;i<=n;i++){
			p[i]=i;
			s[i]=1;
		}
		int cur=1,ans=0;
		for(int i=1;i<=n;i++){
			while(cur<i&&f[ord[cur]]-f[ord[i]]>l)
				s[findrt(ord[cur++])]--;
			for(int j=0;j<(int)g[ord[i]].size();j++){
				int v=g[ord[i]][j].v;
				if(f[ord[i]]<=f[v]&&f[v]-f[ord[i]]<=l) merge(ord[i],v);
			}
			ans=max(ans,s[findrt(ord[i])]);
		}
		printf("%d\n",ans);
	}
	return 0;
}