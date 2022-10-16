#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

const long long inf=1e18;
long long n,m;

int main()
{
	long long t,rr,i,j,mn,mx,mn2,mx2;
	pair<long long,pair<long long,long long>> z;
	char ch;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		mn=inf;
		mx=-inf;
		mn2=inf;
		mx2=-inf;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				scanf(" %c",&ch);
				if(ch=='B')
				{
					mn=min(mn,i+j);
					mx=max(mx,i+j);
					mn2=min(mn2,i-j);
					mx2=max(mx2,i-j);
				}
			}
		}
		z.fr=inf;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				z=min(z,{max({abs(i+j-mn),abs(i+j-mx),abs(i-j-mn2),abs(i-j-mx2)}),{i,j}});
			}
		}
		printf("%lld %lld\n",z.sc.fr,z.sc.sc);
	}
}