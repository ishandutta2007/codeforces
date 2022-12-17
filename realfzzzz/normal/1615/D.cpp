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
int n,m,x[maxn],y[maxn],v[maxn];
struct edge{
	int v;
	bool w;
};
vector<edge> g[maxn];
bool calc(int x){
	int cnt=0;
	for(int i=0;i<30;i++) cnt+=x>>i&1;
	return cnt&1;
}
bool c[maxn];
int vis[maxn];
bool dfs(int u){
	vis[u]=1;
	for(edge e:g[u])
		if(vis[e.v]&&(c[e.v]^c[u]^e.w)) return 0;
		else if(!vis[e.v]){
			c[e.v]=c[u]^e.w;
			if(!dfs(e.v)) return 0;
		}
	return 1;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int T=readint();
	while(T--){
		n=readint();
		m=readint();
		for(int i=1;i<=n;i++) vector<edge>().swap(g[i]);
		for(int i=1;i<n;i++){
			x[i]=readint();
			y[i]=readint();
			v[i]=readint();
			if(v[i]>=0){
				g[x[i]].push_back({y[i],calc(v[i])});
				g[y[i]].push_back({x[i],calc(v[i])});
			}
		}
		for(int i=1;i<=m;i++){
			int a,b;
			a=readint();
			b=readint();
			bool p=readint();
			g[a].push_back({b,p});
			g[b].push_back({a,p});
		}
		for(int i=1;i<=n;i++) vis[i]=c[i]=0;
		bool flag=1;
		for(int i=1;i<=n;i++) if(!vis[i]){
			if(!dfs(i)){
				flag=0;
				break;
			}
		}
		if(!flag){
			printf("NO\n");
			continue;
		}
		printf("YES\n");
		for(int i=1;i<n;i++)
			printf("%d %d %d\n",x[i],y[i],v[i]>=0?v[i]:(c[x[i]]^c[y[i]]));
	}
	#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
	#endif
	return 0;
}