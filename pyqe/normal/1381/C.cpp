#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,d,d2,nn,a[100069],fq[100069],sq[100069];
pair<long long,long long> fa[100069],as[100069];

int main()
{
	long long t,rr,i,k,w,mx,nh;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld",&n,&d,&d2);
		for(i=1;i<=n+1;i++)
		{
			fq[i]=0;
		}
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
			fq[a[i]]++;
			fa[i]={fq[a[i]],i};
			sq[i]=0;
		}
		sort(fa+1,fa+n+1);
		nn=0;
		mx=0;
		for(i=1;i<=max(d2-d,mx*2);i++)
		{
			if(i>n)
			{
				nn++;
				break;
			}
			k=fa[i].sc;
			w=fa[i].fr;
			as[i]={a[k],k};
			nn++;
			mx=w;
		}
		if(n-nn<d)
		{
			printf("NO\n");
			continue;
		}
		sort(as+1,as+nn+1);
		for(i=1;i<=n+1;i++)
		{
			if(!fq[i])
			{
				nh=i;
			}
		}
		for(i=1;i<=nn;i++)
		{
			if(i<=d2-d)
			{
				w=as[i].fr;
			}
			else
			{
				w=nh;
			}
			sq[as[(i+mx-1)%nn+1].sc]=w;
		}
		for(i=1;i<=n;i++)
		{
			if(!sq[i])
			{
				if(d)
				{
					sq[i]=a[i];
					d--;
				}
				else
				{
					sq[i]=nh;
				}
			}
		}
		printf("YES\n");
		for(i=1;i<=n;i++)
		{
			printf("%lld%c",sq[i]," \n"[i==n]);
		}
	}
}