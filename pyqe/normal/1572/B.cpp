#include <bits/stdc++.h>

using namespace std;

long long n,nn,a[200069],kd[200069],wg[200069],sq[200069],zs;

void op(long long x)
{
	long long i,sm=a[x]+a[x+1]+a[x+2];
	
	if(!sm)
	{
		return;
	}
	zs++;
	sq[zs]=x;
	for(i=x;i<=x+2;i++)
	{
		a[i]=sm%2;
	}
}

int main()
{
	long long t,rr,i,j,c,e;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		c=0;
		nn=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
			c+=a[i];
			if(i==1||a[i]!=a[i-1])
			{
				nn++;
				kd[nn]=a[i];
				wg[nn]=0;
			}
			wg[nn]++;
		}
		if(c%2||c==n)
		{
			printf("NO\n");
			continue;
		}
		zs=0;
		if(kd[1]&&kd[nn])
		{
			for(i=2;i<nn;i++)
			{
				if(!kd[i]&&wg[i]%2)
				{
					break;
				}
			}
			if(i>=nn)
			{
				if(wg[1]%2==0)
				{
					for(i=wg[1]-1;i>0;i-=2)
					{
						op(i);
					}
				}
				else if(wg[nn]%2==0)
				{
					for(i=n-wg[nn];i<=n-2;i+=2)
					{
						op(i);
					}
				}
				else
				{
					for(i=2;i<nn;i++)
					{
						if(kd[i]&&wg[i]%2)
						{
							break;
						}
					}
					if(i>=nn)
					{
						printf("NO\n");
						continue;
					}
					e=i;
					c=0;
					for(i=1;i<=e;i++)
					{
						c+=wg[i];
					}
					for(i=c-1;i>=c-wg[e];i-=2)
					{
						op(i);
					}
				}
			}
		}
		c=0;
		for(i=1;i<=n-2;i++)
		{
			c+=a[i];
			if(a[i]&&!a[i+1]&&!a[i+2]&&c%2)
			{
				op(i);
			}
		}
		c=0;
		for(i=1;i<=n-2;i++)
		{
			if((a[i]+a[i+1]+a[i+2])%2==0&&c%2==0)
			{
				op(i);
				for(j=i-1;j;j--)
				{
					if((a[j]+a[j+1]+a[j+2])%2==0)
					{
						op(j);
					}
				}
				for(j=i+1;j<=n-2;j++)
				{
					if((a[j]+a[j+1]+a[j+2])%2==0)
					{
						op(j);
					}
				}
				break;
			}
			c+=a[i];
		}
		printf("YES\n%lld\n",zs);
		for(i=1;i<=zs;i++)
		{
			printf("%lld%c",sq[i]," \n"[i==zs]);
		}
	}
}