#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=998244353;
inline int addmod(int x)
{
	return x>=mod?x-mod:x;
}
int n,m,b[100005],f[2][2005][2005],c[2005][2005],pn=2e3;
inline void upd(int &x,int y)
{
	x=addmod(x+y);
}
int main()
{
	for(int i=0;i<=pn;i++)
		c[i][0]=1;
	for(int i=1;i<=pn;i++)
		for(int j=1;j<=pn;j++)
			c[i][j]=addmod(c[i-1][j-1]+c[i-1][j]);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	f[0][0][0]=1;
	int L=0;
	for(int i=0;i<n;i++)
	{
		int nw=i%2;
		for(int j=0;j<=n;j++)
			if(min(min(L-1,b[i]-m),b[i+1]-m)<=j&&j<=b[i+1]+m)
				for(int k=0;k<=i+1;k++)
					f[nw^1][j][k]=0;
		for(int j=0;j<=n;j++)
			if(b[i]-m<=j&&j<=b[i]+m)
				for(int k=0;k<=i+1;k++)
					upd(f[nw^1][j+1][k],f[nw][j][k]);
		for(int j=0;j<=n;j++)
			if(L<=j+1&&j+1<=b[i+1]+m)
				for(int k=1;k<=i+1;k++)
					upd(f[nw^1][j+1][k-1],f[nw^1][j][k]);
		for(int j=0;j<=n;j++)
			if(b[i]-m<=j&&j<=b[i]+m)
				for(int k=0;k<=i+1;k++)
				{
					upd(f[nw^1][j][k],1ll*(k+j)*f[nw][j][k]%mod);
					upd(f[nw^1][j][k+1],1ll*(k+1)*f[nw][j][k]%mod);
				}
		L=max(L,b[i]-m);
	}
	int ans=0;
	for(int i=0;i<=n;i++)
		if(b[n]-m<=i&&i<=b[n]+m)
			for(int j=0;j<=n;j++)
				upd(ans,1ll*f[n%2][i][j]*c[n-i][j]%mod);
	printf("%d\n",ans);
	return 0;
}