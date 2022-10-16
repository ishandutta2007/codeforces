#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second
long long m,nn[2],a[2][50069],fq[2][50069];

int main()
{
	long long t,rr,i,ii,k,c,sz;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		for(ii=0;ii<2;ii++)
		{
			scanf("%lld",&sz);
			if(!ii)
			{
				scanf("%lld",&m);
			}
			nn[ii]=0;
			for(i=0;i<sz;i++)
			{
				scanf("%lld",&k);
				for(c=1;k%m==0;k/=m,c*=m);
				if(!nn[ii]||k!=a[ii][nn[ii]])
				{
					nn[ii]++;
					a[ii][nn[ii]]=k;
					fq[ii][nn[ii]]=0;
				}
				fq[ii][nn[ii]]+=c;
			}
		}
		for(i=1;i<=min(nn[0],nn[1]);i++)
		{
			if(mp(a[0][i],fq[0][i])!=mp(a[1][i],fq[1][i]))
			{
				break;
			}
		}
		if(i>min(nn[0],nn[1])&&nn[0]==nn[1])
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
}