#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 6000005
#define MM 6000005
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
int n,m,k;
int a[MN],b[MN],p[MN],z[MN],f[MN],q[MN],l,r;
vector<int>G[MN],GG[MN];
int main(){int tests=1;//scanf("%d",&tests);
while(tests--){
	scanf("%d%d",&n,&m);
	F(i,1,m)scanf("%d%d",a+i,b+i),G[b[i]].pb(a[i]),GG[a[i]].pb(b[i]);
	scanf("%d",&k);
	F(i,1,k)scanf("%d",p+i);
	memset(f,-1,sizeof f);
	q[l=r=1]=p[k];f[p[k]]=0;
	while(l<=r){
		int u=q[l++];
		for(auto v:G[u])if(f[v]==-1)f[v]=f[u]+1,q[++r]=v;
	}
	F(i,1,n)debug("%d,",f[i]);debug("\n");
	F(i,1,k)z[i]=k-i-f[p[i]];
	F(i,1,k)debug("%d,",z[i]);debug("\n");
	int ans1=0,ans2=0;
	F(i,1,k-1)if(z[i]!=z[i+1])++ans1;
	F(i,1,k-1){
		if(z[i]!=z[i+1])++ans2;
		else{
			int c=0;
			for(auto v:GG[p[i]])if(f[v]==f[p[i+1]])++c;
			debug("(i,c)^%d,%d\n",i,c);
			if(c>=2)++ans2;
		}
	}
	printf("%d %d\n",ans1,ans2);
}	return 0;
}