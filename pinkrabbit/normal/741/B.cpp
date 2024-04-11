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
int n,m,k;
int w[MN],b[MN];
int pa[MN];
int fp(int x){return pa[x]?pa[x]=fp(pa[x]):x;}
vector<int>v[MN];
int f[MN];
int main(){
	scanf("%d%d%d",&n,&m,&k);
	F(i,1,n)scanf("%d",w+i);
	F(i,1,n)scanf("%d",b+i);
	F(i,1,m){
		int x,y;
		scanf("%d%d",&x,&y);
		x=fp(x),y=fp(y);
		if(x!=y)pa[x]=y;
	}
	F(i,1,n)v[fp(i)].pb(i);
	F(i,1,n)if(!v[i].empty()){
		static int g[MN];
		F(j,0,k)g[j]=f[j];
		int sw=0,sb=0;
		for(int x:v[i]){
			sw+=w[x],sb+=b[x];
			dF(j,k,w[x])
				g[j]=max(g[j],f[j-w[x]]+b[x]);
		}
		dF(j,k,sw)
			g[j]=max(g[j],f[j-sw]+sb);
		F(j,0,k)f[j]=g[j];
	}
	printf("%d\n",f[k]);
	return 0;
}