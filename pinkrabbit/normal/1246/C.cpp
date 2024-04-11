#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 2005
#define ll long long
#define mod 1000000007
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
int n,m;
char a[MN][MN];
int b[MN][MN],c[MN][MN];
int f[MN][MN],g[MN][MN];
int main(){
	scanf("%d%d",&n,&m);
	if(n==1&&m==1)return puts("1"),0;
	F(i,1,n)scanf("%s",a[i]+1);
	f[n][m]=g[n][m]=1;
	dF(i,n,1)dF(j,m,1){
		if(i==n&&j==m)continue;
//		if(i==n&&j==m-1)continue;
//		if(i==m-1&&j==n)continue;
		if(j!=m)b[i][j]=b[i][j+1]+(a[i][j+1]=='R');
		if(i!=n)c[i][j]=c[i+1][j]+(a[i+1][j]=='R');
		f[i][j]=g[i][j+1]-g[i][m-b[i][j]+1];
		g[i][j]=f[i+1][j]-f[n-c[i][j]+1][j];
		f[i][j]=(((ll)f[i][j]+f[i+1][j])%mod+mod)%mod;
		g[i][j]=(((ll)g[i][j]+g[i][j+1])%mod+mod)%mod;
	}
	printf("%lld\n",(((ll)f[1][1]-f[2][1]+g[1][1]-g[1][2])%mod+mod)%mod);
	return 0;
}