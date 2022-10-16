#include <bits/stdc++.h>

using namespace std;

long long n,m,d,dd,ma=5e5,a[500069],fq[500069],fqq[500069],ps[500069],vl[500069],ia[500069],sq[500069],zs=0;
multiset<long long> ms;

int main()
{
	long long i,j,k,c=0,w;
	
	scanf("%lld%lld%lld%lld",&n,&m,&d,&dd);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	for(i=0;i<dd;i++)
	{
		scanf("%lld",&k);
		fq[k]++;
	}
	for(i=1;i<=ma;i++)
	{
		fqq[i]=fq[i];
		ps[i]=ps[i-1]+fq[i];
	}
	for(i=1;i<=n;i++)
	{
		if(fq[a[i]])
		{
			fq[a[i]]--;
			c++;
			vl[ps[a[i]]-ia[a[i]]]=i;
			ia[a[i]]=(ia[a[i]]+1)%fqq[a[i]];
			ms.insert(i);
		}
		else if(fqq[a[i]])
		{
			ms.erase(vl[ps[a[i]]-ia[a[i]]]);
			vl[ps[a[i]]-ia[a[i]]]=i;
			ia[a[i]]=(ia[a[i]]+1)%fqq[a[i]];
			ms.insert(i);
		}
		if(c==dd)
		{
			k=min(*ms.begin(),i-m+1);
			if((k-1)/m+1+(n-i)/m>=d)
			{
				for(j=1;j<=(k-1)%m;j++)
				{
					zs++;
					sq[zs]=j;
				}
				w=dd;
				for(j=k;j<=i;j++)
				{
					if(ms.find(j)==ms.end())
					{
						w++;
						if(w>m)
						{
							zs++;
							sq[zs]=j;
						}
					}
				}
				printf("%lld\n",zs);
				for(j=1;j<=zs;j++)
				{
					printf("%lld%c",sq[j]," \n"[j==zs]);
				}
				return 0;
			}
		}
	}
	printf("-1\n");
}