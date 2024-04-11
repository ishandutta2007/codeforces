#include <bits/stdc++.h>

using namespace std;

long long n,a[2][100069],fq[100069],pst[100069],sq[100069];
vector<long long> vl[100069];

int main()
{
	long long tt,rrr,t,rr,i,ii,k;
	
	scanf("%lld",&tt);
	for(rrr=0;rrr<tt;rrr++)
	{
		scanf("%lld%lld",&n,&t);
		for(i=1;i<=n;i++)
		{
			vl[i].clear();
			fq[i]=0;
			pst[i]=0;
		}
		for(ii=0;ii<2;ii++)
		{
			for(i=1;i<=n;i++)
			{
				scanf("%lld",&a[ii][i]);
			}
		}
		for(i=1;i<=n;i++)
		{
			if(a[0][i]!=a[1][i])
			{
				vl[a[1][i]].push_back(i);
				fq[a[1][i]]++;
			}
			pst[a[1][i]]=i;
		}
		for(rr=1;rr<=t;rr++)
		{
			scanf("%lld",&k);
			sq[rr]=0;
			if(fq[k])
			{
				sq[rr]=vl[k][fq[k]-1];
				vl[k].pop_back();
				fq[k]--;
			}
		}
		for(i=1;i<=n;i++)
		{
			if(fq[i])
			{
				break;
			}
		}
		if(!sq[t])
		{
			if(pst[k])
			{
				sq[t]=pst[k];
			}
			else
			{
				i=0;
			}
		}
		if(i>n)
		{
			printf("YES\n");
			for(rr=1;rr<=t;rr++)
			{
				if(!sq[rr])
				{
					sq[rr]=sq[t];
				}
				printf("%lld%c",sq[rr]," \n"[rr==t]);
			}
		}
		else
		{
			printf("NO\n");
		}
	}
}