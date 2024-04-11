#include <bits/stdc++.h>

using namespace std;

long long hs[100069];
vector<long long> cd[100069];

void ph(long long p)
{
	long long i,sz=cd[p].size();
	
	for(i=0;i<sz;i++)
	{
		ph(cd[p][i]);
		hs[p]+=hs[cd[p][i]];
	}
	if(sz==0)
	{
		hs[p]=1;
	}
}

int main()
{
	long long n,i,k;
	
	scanf("%lld",&n);
	for(i=2;i<=n;i++)
	{
		scanf("%lld",&k);
		cd[k].push_back(i);
	}
	ph(1);
	sort(hs+1,hs+1+n);
	for(i=1;i<=n;i++)
	{
		if(i>1)
		{
			printf(" ");
		}
		printf("%lld",hs[i]);
	}
	printf("\n");
}