#include<bits/stdc++.h>
using namespace std;
typedef __int128 ll;
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
inline void write(ll x){
	if(x>=10) write(x/10);
	putchar(x%10+'0');
}
const int maxn=2e5+5,maxk=26+5;
int n,k,T,q,p[maxk],f[maxk];
struct edge{
	int v,w;
};
vector<edge> g[maxn];
char z[maxn];
int fa[maxn],top[maxn];
ll d[maxn],c[maxn][maxk];
struct seg{
	int x,z,f;
	bool operator <(seg b){
		return x<b.x;
	}
};
vector<seg> vec[maxn];
void dfs1(int u){
	int v=top[u]=z[fa[u]]==z[u]?top[fa[u]]:fa[u];
	while(v){
		ll l=d[top[u]]-d[v],r=d[top[u]]-d[top[v]];
		c[u][z[v]-'A']=(r?(r-1)/T:-1)-(l?(l-1)/T:-1);
		vec[u].push_back({T-(int)(r?(r-1)%T:T-1),z[v]-'A',1});
		vec[u].push_back({T-(int)(l?(l-1)%T:T-1),z[v]-'A',-1});
		v=top[v];
	}
	vec[u].push_back({0,0,0});
	vec[u].push_back({T,0,0});
	sort(vec[u].begin(),vec[u].end());
	for(edge e:g[u]) if(e.v!=fa[u]){
		fa[e.v]=u;
		d[e.v]=d[u]+e.w;
		dfs1(e.v);
	}
}
bool vis[maxn][maxk*2];
void dfs2(int u){
	int t=(d[u]-d[top[u]])%T;
	for(int i=0;i<(int)vec[u].size()-1;i++)
		vis[u][i]=vec[u][i].x<=t&&t<vec[u][i+1].x;
	for(edge e:g[u]) if(e.v!=fa[u]){
		dfs2(e.v);
		if(z[u]==z[e.v])
			for(int i=0;i<(int)vec[u].size()-1;i++) vis[u][i]|=vis[e.v][i];
	}
}
ll c2[maxk];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	for(int i=1;i<n;i++){
		int u,v,t;
		u=readint();
		v=readint();
		t=readint();
		g[u].push_back({v,t});
		g[v].push_back({u,t});
	}
	k=readint();
	scanf("%s",z+1);
	for(int i=0;i<k;i++) p[i]=readint();
	for(int i=0;i<k;i++) f[i]=readint();
	T=readint();
	dfs1(1);
	dfs2(1);
	q=readint();
	while(q--){
		int opt=readint();
		if(opt==1){
			char z[5];
			scanf("%s",z);
			p[z[0]-'A']=readint();
		}
		else if(opt==2){
			char z[5];
			scanf("%s",z);
			f[z[0]-'A']=readint();
		}
		else{
			int u=readint();
			for(int i=0;i<z[u]-'A';i++) c2[i]=c[u][i];
			ll res=0;
			for(int i=0;i<z[u]-'A';i++) res+=min((ll)p[i],f[i]*c2[i]);
			ll ans=9e18;
			for(int i=0;i<(int)vec[u].size()-1;i++){
				seg x=vec[u][i];
				res-=min((ll)p[x.z],f[x.z]*c2[x.z]);
				c2[x.z]+=x.f;
				res+=min((ll)p[x.z],f[x.z]*c2[x.z]);
				if(vis[u][i]) ans=min(ans,res);
			}
			write(ans);
			putchar('\n');
		}
	}
	#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
	#endif
	return 0;
}