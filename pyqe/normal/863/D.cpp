#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,a[200069];
pair<long long,pair<long long,long long>> qq[200069];

int main()
{
	long long t,rr,i,ky,k,l,p;
	
	scanf("%lld%lld%lld",&n,&m,&t);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&ky,&k,&l);
		qq[i]={ky,{k,l}};
	}
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&p);
		for(i=m;i;i--)
		{
			ky=qq[i].fr;
			k=qq[i].sc.fr;
			l=qq[i].sc.sc;
			if(p>=k&&p<=l)
			{
				if(ky==1)
				{
					p--;
					if(p<k)
					{
						p=l;
					}
				}
				else
				{
					p=l+1-p+k-1;
				}
			}
		}
		printf("%lld%c",a[p]," \n"[rr==t-1]);
	}
}