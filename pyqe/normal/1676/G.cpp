#include <bits/stdc++.h>

using namespace std;

long long n,sbt[100069],z;
vector<long long> al[100069];
bitset<100069> a;

void dfs(long long x)
{
	long long i,sz=al[x].size(),l;
	
	sbt[x]=!a[x]*2-1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		dfs(l);
		sbt[x]+=sbt[l];
	}
	z+=!sbt[x];
}

int main()
{
	long long t,rr,i,k;
	char ch;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			al[i].clear();
		}
		for(i=2;i<=n;i++)
		{
			scanf("%lld",&k);
			al[k].push_back(i);
		}
		for(i=1;i<=n;i++)
		{
			scanf(" %c",&ch);
			a[i]=ch=='W';
		}
		z=0;
		dfs(1);
		printf("%lld\n",z);
	}
}