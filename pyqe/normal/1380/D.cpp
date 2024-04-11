#include <bits/stdc++.h>

using namespace std;

long long n,m,d,d2,d3,a[200069],pst[200069],sq[200069];

long long val(long long x,long long y)
{
	return y*d+(x-y*d2)*d3;
}

int main()
{
	long long i,j,k,z=0;
	
	scanf("%lld%lld%lld%lld%lld",&n,&m,&d,&d2,&d3);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		pst[a[i]]=i;
	}
	for(i=1;i<=m;i++)
	{
		scanf("%lld",&k);
		sq[i]=pst[k];
	}
	sq[m+1]=n+1;
	for(i=1;i<=m+1;i++)
	{
		if(sq[i]<sq[i-1])
		{
			printf("-1\n");
			return 0;
		}
		for(j=sq[i-1]+1;j<sq[i];j++)
		{
			if(a[j]>max(a[sq[i-1]],a[sq[i]]))
			{
				j=-1;
				break;
			}
		}
		k=sq[i]-1-sq[i-1];
		if(j==-1&&d2>k)
		{
			printf("-1\n");
			return 0;
		}
		z+=min(val(k,j==-1),val(k,k/d2));
	}
	printf("%lld\n",z);
}