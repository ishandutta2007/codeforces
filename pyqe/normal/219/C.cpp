#include <bits/stdc++.h>

using namespace std;

long long n,d,a[500069];

int main()
{
	long long i,ii,mn=1e18,ee=-1,c;
	string s;
	
	scanf("%lld%lld",&n,&d);
	cin>>s;
	for(i=1;i<=n;i++)
	{
		a[i]=s[i-1]-'A';
	}
	a[0]=69;
	a[n+1]=69;
	if(d==2)
	{
		for(ii=0;ii<2;ii++)
		{
			c=0;
			for(i=1;i<=n;i++)
			{
				if(a[i]!=(i+ii)%2)
				{
					c++;
				}
			}
			if(c<mn)
			{
				mn=c;
				ee=ii;
			}
		}
		printf("%lld\n",mn);
		for(i=1;i<=n;i++)
		{
			printf("%c",(i+ee)%2+'A');
		}
		printf("\n");
	}
	else
	{
		mn=0;
		for(i=1;i<=n;i++)
		{
			if(a[i]==a[i-1])
			{
				mn++;
				if(a[i-1]==0||a[i+1]==0)
				{
					if(a[i-1]==1||a[i+1]==1)
					{
						a[i]=2;
					}
					else
					{
						a[i]=1;
					}
				}
				else
				{
					a[i]=0;
				}
			}
		}
		printf("%lld\n",mn);
		for(i=1;i<=n;i++)
		{
			printf("%c",a[i]+'A');
		}
		printf("\n");
	}
}