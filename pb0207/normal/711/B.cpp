#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

typedef long long ll;

const int N=1e3+1e2+7;

int n;

ll a[N][N],x,y;

ll sum,ans;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			scanf("%lld",&a[i][j]);
			if(a[i][j]==0)
				x=i,y=j;
		}
	if(n==1)
	{
		puts("1");
	}
	else
	{
		for(int i=1;i<=n;i++)
			if(i!=x)
			{
				for(int j=1;j<=n;j++)
					sum+=a[i][j];
				break;
			}
		ll tot=0;
		for(int i=1;i<=n;i++)
			tot+=a[i][y];
		if(tot>=sum)
		{
			puts("-1");
			return 0;
		}	
		ans=sum-tot;
		a[x][y]=ans;
		for(int i=1;i<=n;i++)
		{
			tot=0;
			for(int j=1;j<=n;j++)
				tot+=a[i][j];
			if(tot!=sum)
			{
				puts("-1");
				return 0;
			}
		}
		for(int j=1;j<=n;j++)
		{
			tot=0;
			for(int i=1;i<=n;i++)
				tot+=a[i][j];
			if(tot!=sum)
			{
				puts("-1");
				return 0;
			}
		}
		tot=0;
		for(int i=1;i<=n;i++)
			tot+=a[i][i];
		if(tot!=sum)
		{
			puts("-1");
			return 0;
		}
		tot=0;
		for(int i=1;i<=n;i++)
			tot+=a[i][n-i+1];
		if(tot!=sum)
		{
			puts("-1");
			return 0;
		}
		printf("%lld",ans);
	}
}