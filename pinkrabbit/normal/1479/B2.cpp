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
int n,m,q,k;
int a[MN],b[MN],c[MN];
int f[MN],g[MN];
int main(){
	scanf("%d",&n);
	F(i,1,n)scanf("%d",a+i);
	F(i,1,n){
		if(a[i]==b[m])++c[m];
		else b[++m]=a[i],c[m]=1;
	}
//	F(i,1,m)printf("%d,",b[i]);puts("");
	F(i,1,n)g[i]=-999;
	g[b[1]]=0;
	int mxf=0;
	F(i,3,m){
		f[i]=max(g[b[i]]+1,mxf);
		g[b[i-1]]=max(g[b[i-1]],f[i]);
		mxf=max(mxf,f[i]);
	}
	int ans=0;
	F(i,1,m)ans=max(ans,f[i]);
	printf("%d\n",m-ans);
	return 0;
}