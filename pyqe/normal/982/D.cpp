#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,nn=0,dsu[100069],cc[100069];
pair<long long,long long> a[100069];
multiset<long long> ms;

long long fd(long long x)
{
	if(dsu[x]!=x)
	{
		dsu[x]=fd(dsu[x]);
	}
	return dsu[x];
}

int main()
{
	long long i,u,k,l,w;
	pair<long long,long long> z={0,0};
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		a[i]={k,i};
	}
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++)
	{
		w=a[i].fr;
		k=a[i].sc;
		dsu[k]=k;
		cc[k]=1;
		for(u=-1;u<=1;u+=2)
		{
			l=fd(k+u);
			if(l)
			{
				ms.erase(ms.find(cc[l]));
				nn--;
				cc[k]+=cc[l];
				dsu[l]=k;
			}
		}
		ms.insert(cc[k]);
		nn++;
		if(w!=a[i+1].fr&&*ms.begin()==*prev(ms.end()))
		{
			z=max(z,{nn,-w-1});
		}
	}
	printf("%lld\n",-z.sc);
}