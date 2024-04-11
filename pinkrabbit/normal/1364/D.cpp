#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 300005
#define MM 600005
#define ll long long
#define mod 998244353
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
int n,m,k,eu[MM],ev[MM],par[MN],dep[MN],vis[MN];
vector<int>G[MN];
void DFS(int u){
	dep[u]=dep[par[u]]+1,vis[u]=1;
	for(int v:G[u])if(!vis[v])par[v]=u,DFS(v);
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	F(i,1,m)scanf("%d%d",eu+i,ev+i),G[eu[i]].pb(ev[i]),G[ev[i]].pb(eu[i]);
	DFS(1);
	int u=0,v=0;
	F(i,1,m){
		int x=eu[i],y=ev[i];
		if(abs(dep[x]-dep[y])==1)continue;
		if(abs(dep[x]-dep[y])<k){
			printf("2\n%d\n",abs(dep[x]-dep[y])+1);
			if(dep[x]<dep[y])swap(x,y);
			while(x!=y)printf("%d ",x),x=par[x];
			printf("%d\n",y);
			return 0;
		}else u=eu[i],v=ev[i];
	}
	if(!u){
		k=(k+1)/2;
		puts("1");
		int b[2]={0,0};
		F(i,1,n)++b[dep[i]&1];
		int o=b[0]>b[1]?0:1;
		F(i,1,n)if((dep[i]&1)==o&&k)printf("%d ",i),--k;
		return 0;
	}
	if(dep[u]<dep[v])swap(u,v);
	puts("1");
	F(i,1,(k+1)/2)printf("%d ",u),u=par[par[u]];
	return 0;
}