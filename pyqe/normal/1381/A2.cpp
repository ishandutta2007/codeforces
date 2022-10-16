#include <bits/stdc++.h>

using namespace std;

long long n,a[2][100069],sq[200069],zs;

int main()
{
	long long t,rr,i,ii,tg;
	string s;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(ii=0;ii<2;ii++)
		{
			cin>>s;
			for(i=1;i<=n;i++)
			{
				a[ii][i]=s[i-1]-'0';
			}
		}
		zs=0;
		for(i=1;i<=n;i++)
		{
			if(i%2==1)
			{
				tg=(i+1)/2;
			}
			else
			{
				tg=n+1-i/2;
			}
			if((a[0][tg]^i%2)!=a[1][n+1-i])
			{
				zs++;
				sq[zs]=1;
			}
			zs++;
			sq[zs]=n+1-i;
		}
		printf("%lld",zs);
		for(i=1;i<=zs;i++)
		{
			printf(" %lld",sq[i]);
		}
		printf("\n");
	}
}