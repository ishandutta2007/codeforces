#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m[2],pst[300069],zs=0;
pair<long long,long long> a[300069];
stack<pair<long long,long long>> sk;
vector<pair<pair<long long,long long>,long long>> sq;

int main()
{
	long long i,k,l,df,w,pz;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&a[i].fr);
		a[i].sc=i;
	}
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",pst+i);
	}
	sort(pst+1,pst+n+1);
	for(i=1;i<=n;i++)
	{
		df=pst[i]-a[i].fr;
		pz=a[i].sc;
		if(df>0)
		{
			sk.push({df,pz});
		}
		else
		{
			for(df=-df;df;)
			{
				if(sk.empty())
				{
					printf("NO\n");
					return 0;
				}
				k=sk.top().fr;
				l=sk.top().sc;
				w=min(k,df);
				sq.push_back({{l,pz},w});
				zs++;
				sk.top().fr-=w;
				df-=w;
				if(!sk.top().fr)
				{
					sk.pop();
				}
			}
		}
	}
	if(!sk.empty())
	{
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	printf("%lld\n",zs);
	for(i=0;i<zs;i++)
	{
		printf("%lld %lld %lld\n",sq[i].fr.fr,sq[i].fr.sc,sq[i].sc);
	}
}