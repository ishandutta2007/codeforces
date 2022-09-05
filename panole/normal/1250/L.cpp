#include<bits/stdc++.h>
using namespace std;

long long k;
int mod,s[50010],n,m,ans[2],Ans[2];
pair<long long,int> a[50010];

struct mat
{
	int a[2][2];
	mat operator *(mat A)
	{
		mat B;
		B.a[0][0]=(1ll*a[0][1]*A.a[1][0]+1ll*a[0][0]*A.a[0][0])%mod;
		B.a[1][0]=(1ll*a[1][1]*A.a[1][0]+1ll*a[1][0]*A.a[0][0])%mod;
		B.a[0][1]=(1ll*a[0][1]*A.a[1][1]+1ll*a[0][0]*A.a[0][1])%mod;
		B.a[1][1]=(1ll*a[1][1]*A.a[1][1]+1ll*a[1][0]*A.a[0][1])%mod;
		return B;
	}
}f[61][50010];

int main()
{
	scanf("%I64d%d%d",&k,&mod,&n);
	if (k==0) return puts("0"),0;
	if (mod==1) return puts("0"),0; 
	for (int i=0; i<n; i++) scanf("%d",&s[i]);
	scanf("%d",&m),s[n]=s[0];
	for (int i=1; i<=m; i++) scanf("%I64d%d",&a[i].first,&a[i].second);
	sort(a+1,a+1+m);
	while (m>0&&a[m].first>=k) m--;
	a[++m].first=k;
	for (int i=1; i<=n; i++) f[0][i].a[0][1]=1,f[0][i].a[0][0]=s[i],f[0][i].a[1][0]=s[i-1],f[0][i].a[1][1]=0;
	f[0][0]=f[0][n];
	for (int j=1; j<=60; j++)
	{
		for (int i=1; i<=n; i++) f[j][i]=(f[j-1][i]*f[j-1][(i+(1ll<<j-1))%n]);
		f[j][0]=f[j][n];
	}
	long long nw=1;
	ans[0]=1,ans[1]=0,a[0].first=-2;
	for (int i=1; i<=m; i++)
	{
		int nww=nw%n;
		for (int j=60; j>=0; j--)
			if (nw+(1ll<<j)<=a[i].first)
			{
				Ans[0]=(1ll*ans[0]*f[j][nww].a[0][0]+1ll*ans[1]*f[j][nww].a[1][0])%mod;
				Ans[1]=(1ll*ans[0]*f[j][nww].a[0][1]+1ll*ans[1]*f[j][nww].a[1][1])%mod;
				ans[0]=Ans[0],ans[1]=Ans[1],nw+=(1ll<<j),nww=nw%n;
			}
		if (i==m) return printf("%d\n",ans[0]),0;
		if (a[i-1].first==a[i].first-1) 
		{
			Ans[0]=(1ll*ans[0]*a[i].second+1ll*ans[1]*a[i-1].second)%mod;
			Ans[1]=ans[0],ans[0]=Ans[0],ans[1]=Ans[1],nw++;
		} else
		{
			Ans[0]=(1ll*ans[0]*a[i].second+1ll*ans[1]*s[(nw-1)%n])%mod;
			Ans[1]=ans[0],ans[0]=Ans[0],ans[1]=Ans[1],nw++;
		}
		if (a[i+1].first!=a[i].first+1) 
		{
			Ans[0]=(1ll*ans[0]*s[nw%n]+1ll*ans[1]*a[i].second)%mod;
			Ans[1]=ans[0],ans[0]=Ans[0],ans[1]=Ans[1],nw++;
		}
	}
	return 0;
}