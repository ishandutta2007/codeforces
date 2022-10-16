#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

const long long mm[2]={100,1000};
long long n,m,zs;
pair<long long,long long> pst[2][1069];
pair<long long,pair<long long,long long>> pr[1069];
pair<pair<long long,long long>,long long> sq[1069];

int main()
{
	long long t,rr,i,j,ii,k,sm,p,e;
	char ch;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		for(ii=0;ii<2;ii++)
		{
			for(i=0;i<mm[ii];i++)
			{
				pst[ii][i].fr=0;
			}
		}
		for(i=1;i<=n;i++)
		{
			sm=0;
			for(j=1;j<=m;j++)
			{
				scanf(" %c",&ch);
				k=ch-'0';
				sm=(sm*10+k)%mm[1];
				for(ii=0;ii<2;ii++)
				{
					if(j>=ii+2)
					{
						pst[ii][sm%mm[ii]]={i,j};
					}
				}
			}
		}
		sm=0;
		for(i=1;i<=m;i++)
		{
			scanf(" %c",&ch);
			k=ch-'0';
			sm=(sm*10+k)%mm[1];
			pr[i].fr=-1;
			for(ii=0;ii<2;ii++)
			{
				if(i>=ii+2&&pr[i-2-ii].fr!=-1&&pst[ii][sm%mm[ii]].fr)
				{
					pr[i]={i-2-ii,pst[ii][sm%mm[ii]]};
				}
			}
		}
		if(pr[m].fr!=-1)
		{
			zs=0;
			for(p=m;p;p=pr[p].fr)
			{
				e=p-pr[p].fr-2;
				zs++;
				sq[zs]={{pr[p].sc.sc-1-e,pr[p].sc.sc},pr[p].sc.fr};
			}
			printf("%lld\n",zs);
			for(i=zs;i;i--)
			{
				printf("%lld %lld %lld\n",sq[i].fr.fr,sq[i].fr.sc,sq[i].sc);
			}
		}
		else
		{
			printf("-1\n");
		}
	}
}