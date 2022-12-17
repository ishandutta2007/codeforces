#include<bits/stdc++.h>
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
const int maxn=2e5+5;
int n,w[maxn];
struct edge{
	int v,w;
};
vector<edge> g[maxn];
bool vis[maxn];
int size[maxn];
void dfs1(int u,int fa){
	size[u]=1;
	for(edge e:g[u]) if(e.v!=fa&&!vis[e.v]){
		dfs1(e.v,u);
		size[u]+=size[e.v];
	}
}
int mx[maxn];
int dfs2(int u,int fa,int s){
	mx[u]=0;
	int r=0;
	for(edge e:g[u]) if(e.v!=fa&&!vis[e.v]){
		int r2=dfs2(e.v,u,s);
		mx[u]=max(mx[u],size[e.v]);
		if(!r||mx[r2]<mx[r]) r=r2;
	}
	mx[u]=max(mx[u],s-size[u]);
	if(!r||mx[u]<mx[r]) r=u;
	return r;
}
double s[maxn],s2[maxn];
void dfs3(int u,int fa,int d){
	s[u]=w[u]*sqrt(d)*d;
	s2[u]=w[u]*sqrt(d);
	for(edge e:g[u]) if(e.v!=fa){
		dfs3(e.v,u,d+e.w);
		s[u]+=s[e.v];
		s2[u]+=s2[e.v];
	}
}
int ans1=0;
double ans2;
void solve(int u){
	dfs1(u,0);
	vis[u]=1;
	dfs3(u,0,0);
	if(!ans1||s[u]<ans2){
		ans1=u;
		ans2=s[u];
	}
	for(edge e:g[u]) if(!vis[e.v])
		if(s2[u]-s2[e.v]*2<0){
			solve(dfs2(e.v,0,size[e.v]));
			break;
		}
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	for(int i=1;i<=n;i++) w[i]=readint();
	for(int i=1;i<n;i++){
		int a,b,l;
		a=readint();
		b=readint();
		l=readint();
		g[a].push_back({b,l});
		g[b].push_back({a,l});
	}
	dfs1(1,0);
	solve(dfs2(1,0,n));
	printf("%d %.18f\n",ans1,ans2);
	#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
	#endif
	return 0;
}