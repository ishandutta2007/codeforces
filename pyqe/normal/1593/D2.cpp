#include <bits/stdc++.h>

using namespace std;

const int ma=1e6;
int n,d,nn,a[69],ca[1000069],as[69];

int main()
{
	int t,rr,i,j,r,k,c,mx,z;
	
	scanf("%d",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d",a+i);
		}
		d=n/2;
		nn=0;
		for(i=1;i<=n;i++)
		{
			for(j=i+1;j<=n;j++)
			{
				if(a[i]!=a[j])
				{
					k=abs(a[i]-a[j]);
					for(r=1;r*r<=k;r++)
					{
						if(k%r==0)
						{
							nn++;
							ca[nn]=r;
							if(k/r!=r)
							{
								nn++;
								ca[nn]=k/r;
							}
						}
					}
				}
			}
		}
		nn++;
		ca[nn]=ma*2+1;
		z=0;
		for(i=1;i<=nn;i++)
		{
			for(j=1;j<=n;j++)
			{
				as[j]=(a[j]%ca[i]+ca[i])%ca[i];
			}
			sort(as+1,as+n+1);
			c=0;
			mx=0;
			for(j=1;j<=n;j++)
			{
				c=c*(as[j]==as[j-1])+1;
				mx=max(mx,c);
			}
			if(mx>=d)
			{
				z=max(z,ca[i]);
			}
		}
		if(z==ma*2+1)
		{
			z=-1;
		}
		printf("%d\n",z);
	}
}