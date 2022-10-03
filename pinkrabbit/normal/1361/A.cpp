#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define MN 1000005
#define pb push_back
int n,m,t[MN],b[MN];
vector<int>G[MN],v[MN];
int buk[MN];
void sol(int u){
	for(int v:G[u])buk[b[v]]=1;
	int x=1;
	while(buk[x])++x;
	b[u]=x;
	for(int v:G[u])buk[b[v]]=0;
}
int main(){int x,y;
	scanf("%d%d",&n,&m);
	F(i,1,m)scanf("%d%d",&x,&y),G[x].pb(y),G[y].pb(x);
	F(i,1,n)scanf("%d",&t[i]),v[t[i]].pb(i);
	F(i,2,n)if(v[i-1].empty()&&!v[i].empty())return puts("-1"),0;
	F(i,1,n)for(int x:v[i])sol(x);
	F(i,1,n)if(t[i]!=b[i])return puts("-1"),0;
	F(i,1,n)for(int x:v[i])printf("%d ",x);puts("");
	return 0;
}