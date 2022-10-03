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
int n;
int a[MN],b[MN],c[MN];
vector<int>G[MN];
void DFS(int u,int k){
	c[u]=k;
	for(int v:G[u])if(!c[v])DFS(v,3-k);
}
int main(){
	scanf("%d",&n);
	F(i,1,n)scanf("%d%d",a+i,b+i),G[a[i]].pb(b[i]),G[b[i]].pb(a[i]);
	F(i,1,n)G[2*i].pb(2*i-1),G[2*i-1].pb(2*i);
	F(i,1,2*n)if(!c[i])DFS(i,1);
	F(i,1,n)printf("%d %d\n",c[a[i]],c[b[i]]);
	return 0;
}