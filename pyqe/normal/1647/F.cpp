#include <bits/stdc++.h>

using namespace std;

long long n,a[500069],sn[500069][2];

int main()
{
	long long rr,i,ii,mx=0,p[2],z=0;
	bool bad;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		mx=max(mx,a[i]);
	}
	for(rr=0;rr<2;rr++)
	{
		for(i=n;i;i--)
		{
			for(ii=0;ii<2;ii++)
			{
				sn[i][ii]=sn[i+1][ii];
			}
			if(sn[i][0]!=-1)
			{
				for(ii=0;ii<2;ii++)
				{
					if(a[i]>sn[i][ii])
					{
						sn[i][ii]=a[i];
						break;
					}
				}
				if(ii>=2)
				{
					sn[i][0]=-1;
				}
			}
		}
		for(ii=0;ii<2;ii++)
		{
			p[ii]=0;
		}
		bad=0;
		for(i=1;i<n;i++)
		{
			if(!bad)
			{
				for(ii=0;ii<2;ii++)
				{
					if(a[i]>p[ii])
					{
						p[ii]=a[i];
						break;
					}
				}
				if(ii>=2)
				{
					break;
				}
				if(a[i]==mx)
				{
					bad=1;
				}
			}
			else
			{
				if(a[i]>p[0]&&a[i]<p[1])
				{
					break;
				}
				else if(a[i]<p[1])
				{
					p[0]=a[i];
				}
				else if(a[i]>p[0])
				{
					p[1]=a[i];
				}
				else if(a[i+1]<a[i])
				{
					p[0]=a[i];
				}
				else
				{
					p[1]=a[i];
				}
			}
			if(bad)
			{
				z+=sn[i+1][0]!=-1&&p[0]>sn[i+1][sn[i+1][0]==a[i+1]]&&p[1]<a[i+1];
			}
		}
		for(i=1;i<n+1-i;i++)
		{
			swap(a[i],a[n+1-i]);
		}
	}
	printf("%lld\n",z);
}