#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,nn=0,pn[100069],pst[100069];
pair<long long,long long> a[100069];
bitset<100069> vtd;

void sw(long long x,long long y)
{
	swap(a[pst[x]],a[pst[y]]);
	swap(pst[x],pst[y]);
}

int main()
{
	long long i,ii,k,l,c=0,z;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n*2;i++)
	{
		scanf("%lld",&a[i].fr);
		a[i].sc=i;
		pst[i]=i;
	}
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld",&k,&l);
		pn[k]=l;
		pn[l]=k;
		sw(k,a[i*2-1].sc);
		sw(l,a[i*2].sc);
	}
	sort(a+1,a+m*2+1,greater<pair<long long,long long>>());
	sort(a+m*2+1,a+n*2+1,greater<pair<long long,long long>>());
	scanf("%lld",&ii);
	ii--;
	k=0;
	for(i=1,c=0;c<n*2;ii^=1,c++)
	{
		if(ii)
		{
			scanf("%lld",&k);
			vtd[k]=1;
		}
		else
		{
			if(pn[k]&&!vtd[pn[k]])
			{
				z=pn[k];
			}
			else
			{
				for(;vtd[a[i].sc];i++);
				z=a[i].sc;
			}
			printf("%lld\n",z);
			fflush(stdout);
			vtd[z]=1;
		}
	}
}