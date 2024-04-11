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
inline int qpow(int b,int e,int m=mod){int a=1;for(;e;e>>=1,b=(ll)b*b%m)if(e&1)a=(ll)a*b%m;return a;}
int n,k;
int v[MN],d[MN];
vector<int>G[MN];
int ask(int x,int y){
	printf("? %d %d\n",x,y);
	fflush(stdout);
	int z;scanf("%d",&z);
	return z;
}
int dfs(int u,int f,int x,int y){
	if(u==x||u==y)return 1;
	for(int w:G[u])if(w!=f&&!v[w])if(dfs(w,u,x,y))return 1;
	return 0;
}
void del(int u,int f){
	for(int w:G[u])if(w!=f&&!v[w])del(w,u);
	v[u]=1,--k;
}
int main(){int tests=1;//scanf("%d",&tests);
while(tests--){
	scanf("%d",&n),k=n;
	{int x,y;F(i,2,n)scanf("%d%d",&x,&y),G[x].pb(y),G[y].pb(x);}
	while(k>1){
		F(i,1,n)if(!v[i]){d[i]=0;for(int u:G[i])if(!v[u])++d[i];}
		int o=0,q=0;
		F(i,1,n)if(!v[i]&&d[i]==1)o=i;
		F(i,1,n)if(!v[i]&&i!=o){int ok=1;for(int u:G[i])if(u==o)ok=0;if(ok)q=i;}
		if(!q){for(int u:G[o])if(!v[u])q=u;}
		int w=ask(o,q);
		for(int u:G[w]){
			if(dfs(u,w,o,q))del(u,w);
		}
	}
	int o=0;
	F(i,1,n)if(!v[i])o=i;
	printf("! %d\n",o);
	fflush(stdout);
}	return 0;
}