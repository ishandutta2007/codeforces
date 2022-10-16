#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n;
vector<pair<long long,long long>> a[2];
vector<long long> sq;
stack<long long> sk;

int main()
{
	long long i,ii,u,k,sz;
	
	scanf("%lld",&n);
	for(i=3;i<=n;i++)
	{
		printf("2 1 2 %lld\n",i);
		fflush(stdout);
		scanf("%lld",&u);
		u=(u+1)/2;
		printf("1 1 2 %lld\n",i);
		fflush(stdout);
		scanf("%lld",&k);
		a[u].push_back({k,i});
	}
	for(ii=0;ii<2;ii++)
	{
		sq.push_back(ii+1);
		sort(a[ii].begin(),a[ii].end());
		sz=a[ii].size();
		for(i=0;i<sz-1;i++)
		{
			printf("2 1 %lld %lld\n",a[ii][i].sc,a[ii][i+1].sc);
			fflush(stdout);
			scanf("%lld",&u);
			if(u==1)
			{
				sq.push_back(a[ii][i].sc);
			}
			else
			{
				sk.push(a[ii][i].sc);
			}
		}
		if(sz)
		{
			sq.push_back(a[ii][sz-1].sc);
		}
		for(;!sk.empty();sk.pop())
		{
			sq.push_back(sk.top());
		}
	}
	printf("0");
	for(i=0;i<n;i++)
	{
		printf(" %lld",sq[i]);
	}
	printf("\n");
}