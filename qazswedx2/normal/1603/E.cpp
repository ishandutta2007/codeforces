#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int mod;
inline int addmod(int x)
{
	return x>=mod?x-mod:x;
}
inline int submod(int x)
{
	return x<0?x+mod:x;
}
int fpow(int x,int y)
{
	int ans=1;
	while(y)
	{
		if(y&1) ans=1ll*ans*x%mod;
		x=1ll*x*x%mod;
		y/=2;
	}
	return ans;
}
int n,fr[100005],infr[100005],pn=1e5;
int f[205][205][405],vis[205][205][405],ct,tans;
inline void upd(int i,int j,int k,int v)
{
	if(vis[i][j][k]!=ct)
	{
		vis[i][j][k]=ct;
		f[i][j][k]=0;
	}
	f[i][j][k]=addmod(f[i][j][k]+v);
}
void solve(int mn)
{
	//printf("solve:mn=%d\n",mn);
	ct++;
	for(int i=1;i<=mn;i++)
	{
		f[i][0][0]=infr[i];
		vis[i][0][0]=ct;
	}
	int mx=2*mn;
	for(int i=1;i<=n;i++)
		for(int j=0;j+mn<=n+1;j++)
			for(int k=0;k+(n-i)*(j+1)<=mx;k++)
				if(vis[i][j][k]==ct)
				{
				//	printf("i=%d,j=%d,k=%d,f=%d\n",i,j,k,f[i][j][k]);
				//	upd(i,j+1,k,f[i][j][k]);
					for(int l=i;l<=n;l++)
					{
						int q=k+(l-i)*(j+1);
				//		printf("l=%d,q=%d,%d,%d\n",l,q,q+l*mn,(j+1+mn)*mn);
						if(q+l*mn>(j+1+mn)*mn) break;
						upd(l,j+1,q,1ll*f[i][j][k]*infr[l-i]%mod);
					}
				}
//	int ans=0;
	for(int k=0;k<=mx;k++)
	{
		if(vis[n][n+1-mn][k])
			tans=addmod(tans+f[n][n+1-mn][k]);
		if(mn<=n&&vis[n][n-mn][k])
			tans=submod(tans-f[n][n-mn][k]);
	}
}
int main()
{
	scanf("%d%d",&n,&mod);
	fr[0]=infr[0]=1;
	for(int i=1;i<=pn;i++)
	{
		fr[i]=1ll*fr[i-1]*i%mod;
		infr[i]=fpow(fr[i],mod-2);
	}
	for(int i=1;i<=n+1;i++)
		solve(i);
	tans=1ll*tans*fr[n]%mod;
	tans=addmod(tans+1);
	printf("%d\n",tans);
	return 0;
}