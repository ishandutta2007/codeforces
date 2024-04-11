#include <bits/stdc++.h>

using namespace std;

long long n,m,a[100069],z[100069][2],sq[200069];
vector<long long> pst[200069];
multiset<pair<long long,long long>> ms;

int main()
{
	long long i,j,ii,rh,zz=0,k,l;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%lld",a+i);
	}
	if(n==1)
	{
		printf("0\n");
		return 0;
	}
	for(ii=0;ii<2;ii++)
	{
		for(i=1;i<=n+m;i++)
		{
			pst[i].clear();
			sq[i]=m+1;
		}
		for(i=1;i<=m;i++)
		{
			pst[a[i]+i].push_back(i);
		}
		for(i=1;i<=n+m;i++)
		{
			pst[i].push_back(m+1);
		}
		rh=1;
		for(i=1;i<=n;i++)
		{
			l=0;
			for(j=i;1;j++)
			{
				k=*upper_bound(pst[j].begin(),pst[j].end(),l);
				rh=max(rh,j);
				if(sq[j]==k)
				{
					break;
				}
				sq[j]=k;
				l=k;
			}
			if(!ii)
			{
				z[i][ii]=max((long long)1,rh-m-1);
			}
			else
			{
				z[n+1-i][ii]=n+1-max((long long)1,rh-m-1);
			}
		}
		for(i=1;i<=m;i++)
		{
			a[i]=n+1-a[i];
		}
	}
	for(i=1;i<=n;i++)
	{
		zz+=z[i][1]-z[i][0]+1;
	}
	printf("%lld\n",zz);
}