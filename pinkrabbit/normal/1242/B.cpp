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
#define mp make_pair
#define fi first
#define se second
int n,m,k;
set<int>G[MN],V;
void dfs(int u){
	V.erase(u);
	int j=0;
	while(j!=-1){
		if(V.upper_bound(j)==V.end())j=-1;
		else{
			j=*V.upper_bound(j);
			if(G[u].count(j))continue;
			dfs(j);
		}
	}
}
int main(){int x,y;
	scanf("%d%d",&n,&m);
	F(i,1,m)scanf("%d%d",&x,&y),G[x].insert(y),G[y].insert(x);
	F(i,1,n)V.insert(i);
	F(i,1,n)if(V.count(i))++k,dfs(i);
	printf("%d\n",k-1);
	return 0;
}