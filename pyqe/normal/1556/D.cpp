#include <bits/stdc++.h>

using namespace std;

const long long d=30;
long long n,m,aa[3][d],a[10069];

long long qr(long long ky,long long x,long long y)
{
	if(ky<2)
	{
		long long k;
		
		if(!ky)
		{
			printf("and");
		}
		else
		{
			printf("or");
		}
		printf(" %lld %lld\n",x,y);
		fflush(stdout);
		scanf("%lld",&k);
		return k;
	}
	else
	{
		return qr(0,x,y)^qr(1,x,y);
	}
}

int main()
{
	long long i,j,ii,k;
	
	scanf("%lld%lld",&n,&m);
	for(i=0;i<3;i++)
	{
		for(j=0;j<d;j++)
		{
			aa[i][j]=-1;
		}
	}
	for(i=0;i<3;i++)
	{
		for(ii=0;ii<2;ii++)
		{
			k=qr(ii,i+1,(i+1)%3+1);
			for(j=0;j<d;j++)
			{
				if((k>>j&1)!=ii)
				{
					aa[i][j]=!ii;
					aa[(i+1)%3][j]=!ii;
				}
			}
		}
	}
	for(i=0;i<d;i++)
	{
		for(j=0;j<3&&aa[j][i]==-1;j++);
		k=aa[j][i];
		for(j=0;j<3;j++)
		{
			if(aa[j][i]==-1)
			{
				aa[j][i]=!k;
			}
			a[j+1]|=aa[j][i]<<i;
		}
	}
	for(i=4;i<=n;i++)
	{
		a[i]=a[1]^qr(2,1,i);
	}
	sort(a+1,a+n+1);
	printf("finish %lld\n",a[m]);
	fflush(stdout);
}