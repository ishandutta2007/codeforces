#include<bits/stdc++.h>
using namespace std;
using ll=long long;
inline ll read(){
	ll x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-') f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
const int maxn=2e5+5;
int n;
vector<int> g[maxn];
int fa[maxn],h[maxn];
vector<int> c[maxn];
int w[maxn],d[maxn];
bool vis[maxn];
void dfs1(int u,int fa){
	vis[u]=1;
	for(int v:g[u]) if(v!=fa&&h[v]==h[u]){
		dfs1(v,u);
		d[u]=min(d[u],d[v]+1);
	}
}
void dfs2(int u,int fa){
	for(int v:g[u]) if(v!=fa&&h[v]==h[u]){
		d[v]=min(d[v],d[u]+1);
		dfs2(v,u);
	}
}
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	n=read();
	queue<int> q;
	for(int i=1;i<=n;i++) h[i]=n;
	for(int i=1;i<=n;i++) if(read()){
		h[i]=0;
		q.push(i);
	}
	for(int i=1;i<n;i++){
		int u,v;
		u=read();
		v=read();
		g[u].push_back(v);
		g[v].push_back(u);
	}
	while(q.size()){
		int u=q.front();
		q.pop();
		for(int v:g[u]) if(h[v]>h[u]+1){
			h[v]=h[u]+1;
			q.push(v);
		}
	}
	for(int i=1;i<=n;i++) c[h[i]].push_back(i);
	for(int i=1;i<=n;i++) w[i]=h[i];
	for(int i=n;i>=0;i--){
		bool flag=0;
		for(int u:c[i])
			for(int v:g[u]) flag|=h[v]==i;
		if(!flag) continue;
		for(int u:c[i]){
			d[u]=n;
			for(int v:g[u]) if(h[v]==i) d[u]=0;
		}
		for(int j=i+1;j<=n;j++){
			for(int u:c[j]){
				vis[u]=0;
				d[u]=n;
				for(int v:g[u]) if(h[v]<j)
					d[u]=min(d[u],max(d[v]-1,0));
			}
			for(int u:c[j]) if(!vis[u]){
				dfs1(u,0);
				dfs2(u,0);
			}
			for(int u:c[j]) if(!d[u]) w[u]=i;
		}
	}
	for(int i=1;i<=n;i++) printf("%d ",h[i]*2-w[i]);
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}