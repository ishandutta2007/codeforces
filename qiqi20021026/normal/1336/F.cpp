#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
#define N 300000

int n,m,k,a[N][2],fa[N],sz[N],top[N],d[N],prf[N],f1[N],q1[N],q2[N];
vector<int> g[N],b[N];
map<int,map<int,int> > f2[N];
LL ans;

void dfs1(int u){
	d[u]=d[fa[u]]+1;
	sz[u]=1;
	for (int v:g[u])
		if (v!=fa[u]){
			fa[v]=u;
			dfs1(v);
			sz[u]+=sz[v];
		}
}

void dfs2(int u){
	if (!top[u]) top[u]=u;
	b[top[u]].push_back(u);
	int t=0;
	for (int v:g[u])
		if (v!=fa[u]&&sz[v]>sz[t]) t=v;
	if (!t) return;
	prf[u]=t; top[t]=top[u]; dfs2(t);
	for (int v:g[u])
		if (v!=fa[u]&&v!=t) dfs2(v);
}

int lca(int x,int y){
	for (;top[x]!=top[y];x=fa[top[x]])
		if (d[top[x]]<d[top[y]]) swap(x,y);
	return d[x]<d[y]?x:y;
}

int go(int x,int k){
	int len=d[x]-d[top[x]];
	if (len<k) return go(fa[top[x]],k-len-1);
	return b[top[x]][len-k];
}

int add1(int x,int y){
	int len=d[x]-d[y];
	if (len<k) return x;
	int z=go(x,len-k+1);
	++f1[x]; --f1[z];
	return z;
}

void add2(int u1,int u2,int v1,int v2){
	if (top[u1]>top[v1]){
		swap(u1,v1); swap(u2,v2);
	}
	if (d[u1]>d[u2]) swap(u1,u2);
	++f2[top[u1]][top[v1]][d[u1]];
	--f2[top[u1]][top[v1]][d[u2]+1];
}

void add(int x,int y){
	int z=lca(x,y);
	x=add1(x,z); y=add1(y,z);
	int u=x,v=y;
	int n1=0,n2=0;
	for (;top[u]!=top[z];u=fa[top[u]]) q1[++n1]=u;
	for (;top[v]!=top[z];v=fa[top[v]]) q2[++n2]=v;
	if (u!=z) q1[++n1]=u; if (v!=z) q2[++n2]=v;
	for (int i1=1,i2=n2;i1<=n1;++i1){
		int u1=q1[i1],u2=top[u1];
		if (d[u2]<=d[z]) u2=prf[z];
		for (;i2;--i2){
			int v1=q2[i2],v2=top[v1];
			if (d[v2]<=d[z]) v2=prf[z];
			if (d[u1]+d[v1]-d[z]*2<k) continue;
			int len=d[u1]+d[v1]-d[z]*2;
			int w1=go(v1,len-k),w2=0;
			len=d[u2]+d[v1]-d[z]*2;
			if (len>=k){
				w2=go(v1,len-k);
				add2(u1,u2,w1,w2);
				break;
			}
			len=d[u1]+d[v1]-d[z]*2;
			w2=go(u1,len-k);
			add2(u1,w2,w1,v1);
			u1=fa[w2];
		}
	}
}

LL C(LL x){return x*(x-1)/2;}

void dfs3(int u,int t){
	for (int v:g[u])
		if (v!=fa[u]){
			dfs3(v,t);
			f1[u]+=f1[v];
		}
	ans+=C(f1[u])*t;
}

void calc(int t){
	for (int i=1;i<=n;++i){
		for (auto j:f2[i]){
			LL sum=0,lst=0;
			for (auto k:j.second){
				ans+=(k.first-lst)*C(sum)*t;
				lst=k.first;
				sum+=k.second;
			}
		}
		f2[i].clear();
	}
}

int main(){
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<n;++i){
		int x,y; scanf("%d%d",&x,&y);
		g[x].push_back(y); g[y].push_back(x);
	}
	dfs1(1); dfs2(1);
	for (int i=1;i<=m;++i){
		scanf("%d%d",a[i]+0,a[i]+1);
		add(a[i][0],a[i][1]);
	}
	dfs3(1,1); calc(1);
	memset(f1,0,sizeof f1);
	++k;
	for (int i=1;i<=m;++i)
		add(a[i][0],a[i][1]);
	dfs3(1,-1); calc(-1);
	printf("%lld\n",ans);
	
	return 0;
}