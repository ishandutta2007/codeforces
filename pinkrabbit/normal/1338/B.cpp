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
int n,d[MN],ovo[MN],leaf,sum,c[MN];
vector<int>G[MN];
void DFS(int u,int p){
	for(int v:G[u])if(v!=p)c[v]=c[u]^1,DFS(v,u);
}
int main(){
	int x,y;
	scanf("%d",&n);
	F(i,2,n)scanf("%d%d",&x,&y),G[x].pb(y),G[y].pb(x),++d[x],++d[y];
	F(i,1,n)if(d[i]==1)++leaf,ovo[G[i][0]]=1;
	F(i,1,n)sum+=ovo[i];
	F(i,1,n)if(d[i]==1){DFS(i,0);break;}
	int ok=1;
	F(i,1,n)if(d[i]==1&&c[i])ok=0;
	printf("%d %d\n",ok?1:3,n-1-leaf+sum);
	return 0;
}