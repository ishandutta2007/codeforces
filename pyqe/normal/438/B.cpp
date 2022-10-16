#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,dsu[100069],cd[100069];
pair<long long,long long> a[100069];
vector<long long> al[100069];
bitset<100069> vtd;

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
	long long i,j,k,l,w,sz,z=0;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&a[i].fr);
		a[i].sc=i;
		dsu[i]=i;
		cd[i]=1;
	}
	sort(a+1,a+n+1,greater<pair<long long,long long>>());
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[k].push_back(l);
		al[l].push_back(k);
	}
	for(i=1;i<=n;i++)
	{
		k=a[i].sc;
		w=a[i].fr;
		sz=al[k].size();
		for(j=0;j<sz;j++)
		{
			l=al[k][j];
			if(vtd[l]&&fd(l)!=fd(k))
			{
				z+=w*cd[fd(k)]*cd[fd(l)];
				cd[fd(k)]+=cd[fd(l)];
				dsu[fd(l)]=fd(k);
			}
		}
		vtd[k]=1;
	}
	printf("%.6lf\n",(double)z/(n*(n-1)/2));
}