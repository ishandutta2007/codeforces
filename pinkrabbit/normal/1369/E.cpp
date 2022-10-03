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
int n,m;
int a[MN],b[MN];
vector<pii>G[MN];
int q[MN],l,r,p[MN];
int main(){int x,y;
	scanf("%d%d",&n,&m);
	F(i,1,n)scanf("%d",a+i);
	F(i,1,m)scanf("%d%d",&x,&y),G[x].push_back({y,i}),G[y].push_back({x,i}),++b[x],++b[y];
	l=1,r=0;
	F(i,1,n)if(a[i]>=b[i])q[p[i]=++r]=i;
	while(l<=r){
		int u=q[l++];
		for(pii e:G[u]){
			int v=e.fi;
			if(a[v]>=b[v])continue;
			if(--b[v]==a[v])q[p[v]=++r]=v;
		}
	}
	if(r!=n)return puts("DEAD"),0;
	puts("ALIVE");
	dF(i,n,1){
		int u=q[i];
		for(pii e:G[u])if(p[e.fi]>i)printf("%d ",e.se);
	}
	return 0;
}