#include <bits/stdc++.h>

using namespace std;

long long n,d,a[200069];

int main()
{
	long long t,rr,i,k,l,c,c2,e;
	bool bad;
	char ch;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		n+=d;
		for(i=1;i<=n;i++)
		{
			scanf(" %c",&ch);
			a[i]=(ch=='1')-(ch=='?');
		}
		for(i=1;i<n+1-i;i++)
		{
			k=i;
			l=n+1-i;
			if(a[k]==-1)
			{
				swap(k,l);
			}
			if(a[k]!=-1&&a[l]==-1)
			{
				a[l]=a[k];
			}
		}
		c2=0;
		for(i=1;i<n+1-i;i++)
		{
			if(a[i]!=a[n+1-i])
			{
				break;
			}
			c2+=a[i]==-1;
		}
		if(i<n+1-i)
		{
			printf("-1\n");
			continue;
		}
		c=0;
		for(i=1;i<=n;i++)
		{
			c+=a[i]==1;
		}
		bad=n%2&&a[n/2+1]==-1;
		if(d>=c&&d<=c+c2*2+bad&&(d%2==c%2||bad))
		{
			for(i=1;i<n+1-i;i++)
			{
				if(a[i]==-1)
				{
					e=c+2<=d;
					a[i]=e;
					a[n+1-i]=e;
					c+=2*e;
				}
			}
			if(bad)
			{
				a[n/2+1]=c<d;
			}
			for(i=1;i<=n;i++)
			{
				printf("%lld",a[i]);
			}
			printf("\n");
		}
		else
		{
			printf("-1\n");
		}
	}
}