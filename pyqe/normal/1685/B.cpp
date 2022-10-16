#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,nn,ttl,a[4],fq[2];
pair<long long,long long> as[200069];

int main()
{
	long long t,rr,i,j,ii,ky,k,l,c;
	bool bad;
	char ch;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		for(i=0;i<4;i++)
		{
			scanf("%lld",a+i);
		}
		n=a[0]+a[1]+a[2]*2+a[3]*2;
		ttl=0;
		c=0;
		for(ii=0;ii<2;ii++)
		{
			fq[ii]=0;
		}
		nn=0;
		for(i=1;i<=n+1;i++)
		{
			if(i<=n)
			{
				scanf(" %c",&ch);
				k=ch-'A';
				ttl+=k;
			}
			if(i>n||k==l)
			{
				if(c)
				{
					if(c%2)
					{
						fq[0]+=c/2;
						nn++;
						as[nn]={0,c/2};
					}
					else if(l)
					{
						fq[0]+=c/2;
						nn++;
						as[nn]={1,-c/2};
					}
					else
					{
						fq[0]+=c/2-1;
						nn++;
						as[nn]={-1,c/2-1};
					}
				}
				c=0;
			}
			c++;
			l=k;
		}
		sort(as+1,as+nn+1);
		if(ttl!=a[1]+a[2]+a[3])
		{
			printf("NO\n");
			continue;
		}
		bad=0;
		for(i=1;i<=nn;i++)
		{
			ky=as[i].fr;
			k=abs(as[i].sc);
			for(j=0;j<=k;j++)
			{
				fq[0]-=!!j;
				fq[1]+=!!j+(ky==-1&&j==k)-(ky==1&&j==1);
				bad|=fq[0]>=a[2]&&fq[1]>=a[3];
			}
		}
		if(bad)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}