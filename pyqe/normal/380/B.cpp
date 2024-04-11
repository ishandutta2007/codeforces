#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,ls[1000069];
vector<pair<pair<long long,long long>,long long>> qq[7069];

long long nx(long long x)
{
	long long k;
	
	for(k=x;k;k/=2,x++);
	return x;
}

int main()
{
	long long t,rr,i,j,ky,k,lb,rb,w,sz,lh,rh,z;
	
	scanf("%lld%lld",&n,&t);
	for(rr=1;rr<=t;rr++)
	{
		scanf("%lld%lld%lld",&ky,&k,&lb);
		if(ky==1)
		{
			scanf("%lld%lld",&rb,&w);
			qq[k].push_back({{lb,rb},w});
		}
		else if(ky==2)
		{
			z=0;
			rb=lb;
			for(i=k;i<=n;i++)
			{
				sz=qq[i].size();
				for(j=0;j<sz;j++)
				{
					lh=qq[i][j].fr.fr;
					rh=qq[i][j].fr.sc;
					w=qq[i][j].sc;
					if(!(lh>rb||rh<lb))
					{
						z+=ls[w]<rr;
						ls[w]=rr;
					}
				}
				lb=nx(lb-1)+1;
				rb=nx(rb);
			}
			printf("%lld\n",z);
		}
	}
}