#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,c[15],pn=1002,dp[1055][1005],p[1005],tmp[1005],f[15];
char a[1055],b[1005][1055];
inline int F(int x)
{
	if(x>='0'&&x<='9') return x-'0';
	return 0;
}
int main()
{
//	freopen("digits.in","r",stdin);
//	freopen("digits.out","w",stdout);
	memset(dp,0xc0,sizeof(dp));
	scanf("%s%d",a+1,&n);
	m=strlen(a+1);
	reverse(a+1,a+m+1);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",b[i]+1);
		int len=strlen(b[i]+1);
		reverse(b[i]+1,b[i]+len+1);
	}
	for(int i=0;i<10;i++)
		scanf("%d",&c[i]);
	for(int i=1;i<=n;i++)
		p[i]=i;
	dp[0][0]=0;
	for(int i=1;i<=pn;i++)
	{
		int mn,mx;
		if(a[i]=='?')
		{
			if(i==m) mn=1,mx=9;
			else mn=0,mx=9;
		}
		else if(a[i]>='0'&&a[i]<='9')
			mn=mx=a[i]-'0';
		else mn=mx=0;
		for(int k=mn;k<=mx;k++)
		{
			int ct=0,nw=0;
			for(int j=1;j<=n;j++)
			{
				int u=F(b[j][i])+k;
				if(u>=10)
					ct++;
				if(u==0&&b[j][i]==0&&i>m)
					continue;
				nw+=c[u%10];
			}
			for(int j=0;j<=n;j++)
			{
				if(j)
				{
					int x=p[n-j+1];
					int u=F(b[x][i])+k;
					if(u==9) ct++;
					if(!(u==0&&b[x][i]==0&&i>m))
						nw-=c[u%10];
					nw+=c[(u+1)%10];
				}
				dp[i][ct]=max(dp[i][ct],dp[i-1][j]+nw);
			}
		}
		for(int j=1;j<=n;j++)
			tmp[j]=p[j];
		for(int j=0;j<10;j++)
			f[j]=0;
		for(int j=1;j<=n;j++)
			f[F(b[j][i])]++;
		for(int j=1;j<10;j++)
			f[j]+=f[j-1];
		for(int j=n;j;j--)
			p[f[F(b[tmp[j]][i])]--]=tmp[j];
	}
	printf("%d\n",dp[pn][0]);
	return 0;
}