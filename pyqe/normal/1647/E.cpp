#include <bits/stdc++.h>

using namespace std;

const long long mm=30;
long long n,d,pr[100069][mm],dg[100069],a[100069];
bitset<100069> vtd;
multiset<long long> ms;

int main()
{
	long long i,j,mx=0,c=0,p,z;
	multiset<long long>::iterator it;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&pr[i][0]);
		dg[pr[i][0]]++;
		ms.insert(i);
	}
	for(i=1;i<mm;i++)
	{
		for(j=1;j<=n;j++)
		{
			pr[j][i]=pr[pr[j][i-1]][i-1];
		}
	}
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		mx=max(mx,a[i]);
		c+=!dg[i];
		if(a[i]<=n)
		{
			ms.erase(a[i]);
		}
	}
	d=(mx-n)/c;
	for(i=1;i<=n;i++)
	{
		p=i;
		for(j=mm-1;j>=0;j--)
		{
			if(d>>j&1)
			{
				p=pr[p][j];
			}
		}
		if(!vtd[a[p]])
		{
			vtd[a[p]]=1;
			z=a[p];
		}
		else
		{
			it=ms.lower_bound(a[p]);
			z=*it;
			ms.erase(it);
		}
		printf("%lld%c",z," \n"[i==n]);
	}
}