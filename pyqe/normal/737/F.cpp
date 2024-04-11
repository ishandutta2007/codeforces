#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,d,d2,nm,nn=0,lb=0,tg,a[2069],as[2069],vl[2069],sk[2069],zs=0,inf=1e18;
pair<long long,long long> sq[4069];

void no(bool bad)
{
	if(bad)
	{
		printf("NO\n");
		exit(0);
	}
}

void op(long long x)
{
	long long i;
	
	no(x>d);
	for(i=lb+x;i>lb;i--)
	{
		nn++;
		sk[nn]=a[i];
	}
	lb+=x;
	zs++;
	sq[zs]={1,x};
}

void op2(long long x)
{
	long long i;
	
	no(x>d2);
	nn-=x;
	tg-=x;
	zs++;
	sq[zs]={2,x};
}

int main()
{
	long long i,j,k,rb,mn,mx,c;
	
	scanf("%lld%lld%lld",&n,&d,&d2);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		as[i]=a[i];
	}
	sort(as+1,as+n+1);
	for(i=1;i<=n;i++)
	{
		a[i]=lower_bound(as+1,as+n+1,a[i])-as;
	}
	tg=n;
	for(;tg;)
	{
		for(c=1;c;)
		{
			c=0;
			for(i=lb+1;i<=n;i++)
			{
				if(a[i]==tg)
				{
					k=i-lb;
					for(j=0;j<k;j++)
					{
						op(1);
					}
				}
				else if(a[i]+1<a[i+1])
				{
					break;
				}
			}
			for(i=nn;i;i--)
			{
				if(sk[i]==tg)
				{
					op2(nn-i+1);
					c++;
				}
			}
		}
		mn=inf;
		mx=-inf;
		nm=0;
		vl[0]=lb;
		for(i=lb+1;i<=n;i++)
		{
			mn=min(mn,a[i]);
			mx=max(mx,a[i]);
			if(a[i]+1!=a[i+1])
			{
				nm++;
				vl[nm]=i;
			}
			if(i==n||a[i]+1<a[i+1])
			{
				break;
			}
		}
		rb=i;
		if(mx-mn+1>rb-lb)
		{
			op(rb-lb);
		}
		else
		{
			mx=-inf;
			for(i=1;i<=nm;i++)
			{
				mx=max(mx,vl[i]-vl[i-1]);
			}
			if(mx<=d&&vl[nm]-lb<=d2)
			{
				for(i=1;i<=nm;i++)
				{
					op(vl[i]-lb);
				}
			}
			else if(nm==1)
			{
				for(;lb<vl[1];)
				{
					op(1);
				}
			}
			else if(nm>2)
			{
				op(vl[nm]-lb);
			}
			else
			{
				for(i=lb+1;i<=vl[nm];i++)
				{
					if(max(i-lb,vl[2]-i)<=d&&max(abs(vl[1]-i),vl[2]-lb-abs(vl[1]-i))<=d2)
					{
						op(i-lb);
						if(vl[nm]-i)
						{
							op(vl[nm]-i);
						}
						i=-1;
						break;
					}
				}
				no(i!=-1);
			}
		}
		for(i=nn;i>1;i--)
		{
			no(sk[i]+1<sk[i-1]);
		}
	}
	printf("YES\n%lld\n",zs);
	for(i=1;i<=zs;i++)
	{
		printf("%lld %lld\n",sq[i].fr,sq[i].sc);
	}
}