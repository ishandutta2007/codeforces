#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,dsu[200069],cd[200069];
pair<long long,long long> a[200069];
bitset<200069> vtd;

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
	long long i,j,ii,k,w,mx=-1e18;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&a[i].fr);
		a[i].sc=i;
	}
	sort(a+1,a+n+1,greater<pair<long long,long long>>());
	for(j=1,i=1;i<=n;i++)
	{
		w=a[i].fr;
		k=a[i].sc;
		vtd[k]=1;
		dsu[k]=k;
		cd[k]=1;
		for(ii=k-1;ii<=k+1;ii+=2)
		{
			if(vtd[ii])
			{
				cd[fd(k)]+=cd[fd(ii)];
				dsu[fd(ii)]=fd(k);
			}
		}
		mx=max(mx,cd[fd(k)]);
		for(;j<=mx;j++)
		{
			printf("%lld%c",w," \n"[j==n]);
		}
	}
}