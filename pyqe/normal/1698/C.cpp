#include <bits/stdc++.h>

using namespace std;

long long n,a[200069];

bool cabs(long long x,long long y)
{
	return abs(x)>abs(y);
}

int main()
{
	long long t,rr,i,j,r,c,c2,w,p;
	bool bad;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		c=0;
		c2=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
			c+=a[i]>0;
			c2+=a[i]<0;
		}
		if(c>=3||c2>=3)
		{
			printf("NO\n");
			continue;
		}
		sort(a+1,a+n+1,cabs);
		n=min(n,9ll);
		sort(a+1,a+n+1);
		bad=0;
		for(i=1;i<=n;i++)
		{
			for(j=i+1;j<=n;j++)
			{
				for(r=j+1;r<=n;r++)
				{
					w=a[i]+a[j]+a[r];
					p=lower_bound(a+1,a+n+1,w)-a;
					if(p>n||a[p]!=w)
					{
						bad=1;
					}
				}
			}
		}
		if(!bad)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}