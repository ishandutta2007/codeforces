#include<cstdio>
#include<iostream>
#include<cmath>
#include<cassert>
#include<cstdlib>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
#define pb push_back
#define x0 fuckcjb
#define x1 fuckshb
#define y0 fucksub
#define y1 fuckjtjl
const int MOD=1E9+7;
int f[1010][1010][2],a[1010],n,ans,k;
char s[1010];
void DP()
{
	f[0][0][1]=1;
	for(int i=1;i<=n;i++)
	{
		if(!a[i])
		{
			for(int j=0;j<=1000;j++)
			{
				f[i][j][0]=(f[i][j][0]+f[i-1][j][0])%MOD;
				f[i][j][1]=(f[i][j][1]+f[i-1][j][1])%MOD;
			}
			for(int j=1;j<=1000;j++)
			{
				f[i][j][0]=(f[i][j][0]+f[i-1][j-1][0])%MOD;
			}
		}
		else
		{
			for(int j=0;j<=1000;j++)
			{
				f[i][j][0]=((f[i][j][0]+f[i-1][j][0])%MOD+f[i-1][j][1])%MOD;
			}
			for(int j=1;j<=1000;j++)
			{
				f[i][j][0]=(f[i][j][0]+f[i-1][j-1][0])%MOD;
				f[i][j][1]=(f[i][j][1]+f[i-1][j-1][1])%MOD;
			}
		}
	}
}
int check(int x)
{
	int num=0;
	for(;x!=1;)
	{
		num++;
		int tx=0;
		for(;x;x>>=1)
		{
			tx+=x&1;
		}
		x=tx;
	}
	return num;
}
int main()
{
	scanf("%s",s);
	n=strlen(s);
	for(int i=1;i<=n;i++)
	{
		a[i]=s[i-1]-'0';
	}
	scanf("%d",&k);
	if(k==0)
	{
		puts("1");
		return 0;
	}
	DP();
	for(int i=1;i<=1000;i++)
	{
		if(check(i)==k-1)
		{
			ans=((ans+f[n][i][0])%MOD+f[n][i][1])%MOD;
		}
	}
	if(k==1)
	{
		ans=(ans+MOD-1)%MOD;
	}
	printf("%d\n",ans);
	return 0;
}