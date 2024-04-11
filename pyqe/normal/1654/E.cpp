#include <bits/stdc++.h>

using namespace std;

const int ma=1e5,sqn=316;
int n,d,nn=0,a[100069],ca[100069];
pair<int,long long> as[40000069];

inline int tri(int x)
{
	return x*(x-1)/2;
}

int main()
{
	int i,j,ii,k,sm,c,mx,z=1;
	
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",a+i);
	}
	for(ii=0;ii<2;ii++)
	{
		for(i=0;i<=sqn;i++)
		{
			sm=0;
			for(j=1;j<=n;j++)
			{
				sm+=i;
				ca[j]=a[j]-sm;
			}
			sort(ca+1,ca+n+1);
			c=0;
			for(j=1;j<=n;j++)
			{
				if(ca[j]!=ca[j-1])
				{
					c=0;
				}
				c++;
				z=max(z,c);
			}
		}
		for(i=1;i<=n;i++)
		{
			a[i]=ma+1-a[i];
		}
	}
	d=(ma-1)/(sqn+1)+1;
	for(i=1;i<=n;i++)
	{
		for(j=i+1;j<=n&&j<i+d;j++)
		{
			if((a[j]-a[i])%(j-i)==0)
			{
				nn++;
				k=(a[j]-a[i])/(j-i);
				as[nn]={k,(long long)a[i]-k*i};
			}
		}
	}
	sort(as+1,as+nn+1);
	mx=0;
	c=0;
	for(i=1;i<=nn;i++)
	{
		if(as[i]!=as[i-1])
		{
			c=0;
		}
		c++;
		mx=max(mx,c);
	}
	for(i=0;tri(i+1)<=mx;i++);
	z=max(z,i);
	printf("%d\n",n-z);
}