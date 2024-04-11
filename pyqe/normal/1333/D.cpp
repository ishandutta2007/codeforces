#include <bits/stdc++.h>

using namespace std;

long long n,d,sq[9000069],gp[9000069],pr[9000069],zs=0;
bitset<3069> a;

int main()
{
	long long i,j,c;
	string s;
	bool bad=1;
	
	scanf("%lld%lld",&n,&d);
	cin>>s;
	for(i=1;i<=n;i++)
	{
		a[i]=s[i-1]=='R';
	}
	for(c=1;bad;c++)
	{
		bad=0;
		for(i=1;i<n;i++)
		{
			if(a[i]&&!a[i+1])
			{
				bad=1;
				zs++;
				sq[zs]=i;
				gp[zs]=c;
				a[i]=0;
				a[i+1]=1;
				i++;
			}
		}
	}
	if(zs<d)
	{
		printf("-1\n");
		return 0;
	}
	for(i=1;i<=zs;i++)
	{
		pr[i]=i;
	}
	c=zs;
	for(i=zs-1;i;i--)
	{
		if(c>d&&gp[i]==gp[i+1])
		{
			pr[i]=pr[i+1];
			c--;
		}
	}
	if(c>d)
	{
		printf("-1\n");
		return 0;
	}
	for(i=1;i<=zs;i=pr[i]+1)
	{
		printf("%lld",pr[i]-i+1);
		for(j=i;j<=pr[i];j++)
		{
			printf(" %lld",sq[j]);
		}
		printf("\n");
	}
}