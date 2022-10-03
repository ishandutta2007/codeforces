#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 1000005
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
vector<int>a[MN],s[MN],f[MN],sf[MN],an[MN];
inline bool check(int x){
//	debug("x=%d\n",x);
	x=x*2+1;
	F(i,0,n+1)F(j,0,m+1)sf[i][j]=f[i][j]=0;
	F(i,1,n)F(j,1,m){
		if(i<=n-x+1&&j<=m-x+1){
			int su=s[i+x-1][j+x-1]-s[i-1][j+x-1]-s[i+x-1][j-1]+s[i-1][j-1];
			if(su==x*x)f[i][j]=1;
		}
	}
//	F(i,1,n){F(j,1,m)debug("%d",f[i][j]);debug("\n");}
	F(i,1,n)F(j,1,m)sf[i][j]=f[i][j]+sf[i][j-1]+sf[i-1][j]-sf[i-1][j-1];
//	F(i,1,n){F(j,1,m)debug(" %2d ",sf[i][j]);debug("\n");}
	int ok=1;
	F(i,1,n)F(j,1,m)if(a[i][j]){
		int su=sf[i][j];
		if(i>x)su-=sf[i-x][j];
		if(j>x)su-=sf[i][j-x];
		if(i>x&&j>x)su+=sf[i-x][j-x];
		if(!su)ok=0;//,printf("(%d,%d):%d\n",i,j,su);
	}
	return ok;
}
int main(){int tests=1;//scanf("%d",&tests);
while(tests--){
	scanf("%d%d",&n,&m);
	F(i,0,n+1)a[i].resize(m+2),s[i].resize(m+2),f[i].resize(m+2),sf[i].resize(m+2),an[i].resize(m+2);
	F(i,1,n){
		static char s[MN];
		scanf("%s",s+1);
		F(j,1,m)a[i][j]=s[j]=='X';
	}
	F(i,1,n)F(j,1,m)s[i][j]=s[i-1][j]+s[i][j-1]+a[i][j]-s[i-1][j-1];
//	F(i,1,n){F(j,1,m)printf(" %2d ",s[i][j]);puts("");}
	int l=0,r=(min(n,m)-1)/2,mid,ans=-1;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid))ans=mid,l=mid+1;
		else r=mid-1;
	}
	check(ans);
	printf("%d\n",ans);
	F(i,1,n)F(j,1,m)if(f[i][j])an[i+ans][j+ans]=1;
	F(i,1,n){F(j,1,m)printf("%c",an[i][j]?'X':'.');puts("");}
}	return 0;
}