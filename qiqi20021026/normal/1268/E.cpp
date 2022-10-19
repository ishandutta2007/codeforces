#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
#define N 600000
#define P(x,y) make_pair(x,y)

int n,m,a[N],b[N],ans[N],f[N],cnt,fa[N],edge[N],flag[N],d[N];
vector<pii> g[N];
vector<int> c[N];
bool vis[N];

void dfs(int u){
	vis[u]=1;
	d[u]=d[fa[u]]+1;
	for (auto e:g[u]){
		int v=e.first,i=e.second;
		if (!vis[v]){
			fa[v]=u;
			edge[v]=i;
			dfs(v);
		}
		else{
			if (i==edge[u]||d[v]>d[u]) continue;
			c[++cnt].push_back(i);;
			for (int w=u;w!=v;w=fa[w]){
				c[cnt].push_back(edge[w]);
			}
			vector<int> &C=c[cnt];
			int len=C.size(),mx=0,mn=0;
			for (int j=0;j<len;++j){
				if (C[j]>C[mx]) mx=j;
				if (C[j]<C[mn]) mn=j;
			}
			bool fl=1;
			for (int j=mn;j!=mx;(j+=1)%=len) fl&=C[j]<C[(j+1)%len];
			for (int j=mn;j!=mx;(j+=len-1)%=len) fl&=C[j]<C[(j+len-1)%len];
			if (fl) flag[C[mn]]=C[mx];
		}
	}
}

int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;++i){
		scanf("%d%d",a+i,b+i);
		g[a[i]].push_back(P(b[i],i));
		g[b[i]].push_back(P(a[i],i));
	}
	dfs(1);
	for (int i=1;i<=n;++i) ans[i]=1;
	for (int i=m;i;--i){
		ans[a[i]]=ans[b[i]]=f[i]=ans[a[i]]+ans[b[i]]-f[flag[i]];
	}
	for (int i=1;i<=n;++i) printf(i==n?"%d\n":"%d ",ans[i]-1);
	
	return 0;
}