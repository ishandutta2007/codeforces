#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
using namespace std;
inline int read(){
	int v=0,f=1;
	char c=getchar();
	while (c<'0' || c>'9'){
		if (c=='-') f=-1;
		c=getchar();
	}
	while (c>='0' && c<='9'){
		v=v*10+c-'0';
		c=getchar();
	}
	return v*f;
}
const int Maxn=400005;
int n,k,r;
vector<int> G[Maxn];
int A[Maxn],dist[Maxn],col[Maxn];
int par[Maxn],q[Maxn],sq,eq;
int pr[Maxn][20],st[Maxn],ed[Maxn],kc,dep[Maxn];
int findset(int x){
	return par[x]=(par[x]==x)?x:findset(par[x]);
}
void Union(int x,int y){
	x=findset(x);y=findset(y);
	par[x]=y;
}
void dfs(int x,int p){
	pr[x][0]=p;st[x]=++kc;
	for (int i=0;i<G[x].size();i++){
		int v=G[x][i];
		if (v!=p) dep[v]=dep[x]+1,dfs(v,x);
	}
	ed[x]=kc;
}
bool ispar(int u,int v){
	return u==-1 || (st[u]<=st[v] && ed[v]<=ed[u]);
}
int lca(int u,int v){
	if (ispar(u,v)) return u;
	for (int i=19;i>=0;i--){
		if (!ispar(pr[u][i],v)) u=pr[u][i];
	}
	return pr[u][0];
}

int main(){
	scanf("%d %d %d",&n,&k,&r);
	int _=n;
	for (int i=0;i<_-1;i++){
		int u,v;
		scanf("%d %d",&u,&v);
		int E=++n;
		G[u].pb(E);G[E].pb(u);
		G[v].pb(E);G[E].pb(v);
	}
	for (int i=1;i<=r;i++){
		scanf("%d",&A[i]);
		par[A[i]]=A[i];
		q[eq++]=A[i];
	}
	for (int i=1;i<=n;i++) dist[i]=-1;
	for (int i=1;i<=r;i++) dist[A[i]]=0,col[A[i]]=A[i];
	while (sq<eq){
		int x=q[sq++];
		if (dist[x]==k) continue;
		for (int i=0;i<G[x].size();i++){
			int v=G[x][i];
			if (dist[v]==-1){
				dist[v]=dist[x]+1;
				col[v]=col[x];
				q[eq++]=v;
			}
			else{
				Union(col[v],col[x]);
			}
		}
	}
	dfs(1,-1);
	for (int i=1;i<20;i++){
		for (int j=1;j<=n;j++){
			if (pr[j][i-1]==-1) pr[j][i]=-1;
			else pr[j][i]=pr[pr[j][i-1]][i-1];
		}
	}
	int q;
	scanf("%d",&q);
	while (q--){
		int u,v;
		scanf("%d %d",&u,&v);
		int l=lca(u,v);
		int dst=dep[u]+dep[v]-dep[l]-dep[l];
	//	cout<<"FF"<<" "<<dst<<endl;
		if (dst<=2*k){
			printf("YES\n");
			continue;
		}
		int U=u,V=v; 
		if (dep[u]-dep[l]>=k){
			for (int i=0;i<20;i++){
				if (k>>i&1) u=pr[u][i];
			}
		}
		else{
			u=V;
			for (int i=0;i<20;i++){
				if ((dst-k)>>i&1) u=pr[u][i];
			}
		}
		if (dep[v]-dep[l]>=k){
			for (int i=0;i<20;i++){
				if (k>>i&1) v=pr[v][i];
			}
		}
		else{
			v=U;
			for (int i=0;i<20;i++){
				if ((dst-k)>>i&1) v=pr[v][i];
			}
		}
		//cout<<"OO"<<" "<<u<<" "<<v<<endl;
		if (col[u]!=0 && col[v]!=0 && findset(col[u])==findset(col[v])){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
	}
	return 0;
} 
/*
13 3 3
13 12
12 11
11 7
7 2
2 4
4 5
5 1
1 6
6 3
3 8
8 9
9 10
4 6 3
1
2 13
*/