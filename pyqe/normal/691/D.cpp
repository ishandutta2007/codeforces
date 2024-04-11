#include <bits/stdc++.h>

using namespace std;

long long n,m,a[1000069],dsu[1000069],p[1000069];
vector<long long> vl[1000069];

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
	long long i,k,l;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		dsu[i]=i;
	}
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld",&k,&l);
		dsu[fd(l)]=fd(k);
	}
	for(i=1;i<=n;i++)
	{
		vl[fd(i)].push_back(a[i]);
	}
	for(i=1;i<=n;i++)
	{
		if(fd(i)==i)
		{
			sort(vl[i].begin(),vl[i].end(),greater<long long>());
		}
	}
	for(i=1;i<=n;i++)
	{
		printf("%lld%c",vl[fd(i)][p[fd(i)]]," \n"[i==n]);
		p[fd(i)]++;
	}
}