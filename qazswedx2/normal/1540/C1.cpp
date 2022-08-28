#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=1e9+7;
inline int addmod(int x)
{
	return x>=mod?x-mod:x;
}
inline int submod(int x)
{
	return x<0?x+mod:x; 
}
int n,m,q,b[105],c[105],sum[105],f[105][10005],qans[1005],pn;
int solve(int x)
{
	memset(f,0,sizeof(f));
	f[0][0]=1;
	int nw=0,ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=nw;j++)
		{
			f[i][j]=addmod(f[i][j]+f[i-1][j]);
			f[i][j+c[i]+1]=submod(f[i][j+c[i]+1]-f[i-1][j]);
		}
		nw+=c[i];
		for(int j=1;j<=nw;j++)
			f[i][j]=addmod(f[i][j]+f[i][j-1]);
		for(int j=0;j<x*i+sum[i];j++)
			f[i][j]=0;
	}
	for(int i=0;i<=nw;i++)
		ans=addmod(ans+f[n][i]);
	return ans;
}
int main()
{
	scanf("%d",&n);
	int mul=1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&c[i]);
		m=max(m,c[i]);
		mul=1ll*mul*(c[i]+1)%mod;
	}
	for(int i=1;i<n;i++)
		scanf("%d",&b[i]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<i;j++)
			sum[i]+=(i-j)*b[j];
	pn=(-sum[n])/n;
	for(int i=0;i<=m;i++)
		qans[i]=solve(i+pn);
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		int x;
		scanf("%d",&x);
		if(x<pn) printf("%d\n",mul);
		else if(x>pn+m) printf("0\n");
		else printf("%d\n",qans[x-pn]);
	}
	return 0;
}