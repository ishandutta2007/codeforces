#include <bits/stdc++.h>

using namespace std;

long long n,d,fc[69],dp[69],pr[69],sq[69];
bitset<69> vtd;

long long fd(long long x)
{
	if(pr[x]!=x)
	{
		pr[x]=fd(pr[x]);
	}
	return pr[x];
}

int main()
{
	long long t,rr,i,j,k,p,tg,cr,w,rm,c;
	
	fc[0]=1;
	for(i=1;i<=20;i++)
	{
		fc[i]=fc[i-1]*i;
	}
	dp[0]=1;
	for(i=1;i<=22;i++)
	{
		for(j=1;j<=i;j++)
		{
			dp[i]+=fc[max(j-2,0ll)]*dp[i-j];
		}
	}
	for(i=23;i<=50;i++)
	{
		dp[i]=dp[i-1];
	}
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		d--;
		if(d>=dp[n])
		{
			printf("-1\n");
			continue;
		}
		for(i=1;i<=n;i++)
		{
			vtd[i]=0;
			pr[i]=i;
		}
		for(p=n;p;p=p-tg)
		{
			for(tg=1;tg<=p;tg++)
			{
				k=fc[max(tg-2,0ll)]*dp[p-tg];
				if(d<k)
				{
					break;
				}
				d-=k;
			}
			w=d/dp[p-tg];
			d%=dp[p-tg];
			cr=n+1-p;
			sq[cr]=cr+tg-1;
			for(i=cr+1;i<cr+tg;i++)
			{
				k=fc[max(cr+tg-i-2,0ll)];
				rm=w/k;
				w%=k;
				for(c=0,j=cr;j<cr+tg-1;j++)
				{
					if(!vtd[j]&&fd(j)!=i)
					{
						if(c==rm)
						{
							sq[i]=j;
							vtd[j]=1;
							pr[fd(i)]=fd(j);
							break;
						}
						c++;
					}
				}
			}
		}
		for(i=1;i<=n;i++)
		{
			printf("%lld%c",sq[i]," \n"[i==n]);
		}
	}
}