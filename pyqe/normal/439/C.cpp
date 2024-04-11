#include <bits/stdc++.h>

using namespace std;

long long n,m,d,nn[2];
queue<long long> vl[2];
vector<long long> sq[100069];

int main()
{
	long long i,j,ii,k,sz;
	
	scanf("%lld%lld%lld",&n,&m,&d);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		nn[k%2]++;
		vl[k%2].push(k);
	}
	if(nn[1]%2!=(m-d)%2||nn[1]<m-d||m-d+max(d-nn[0],0ll)*2>nn[1])
	{
		printf("NO\n");
		return 0;
	}
	for(i=1;!vl[0].empty();i=i%m+1)
	{
		k=vl[0].front();
		vl[0].pop();
		sq[i].push_back(k);
	}
	for(i=d+1;i<=m;i++)
	{
		k=vl[1].front();
		vl[1].pop();
		sq[i].push_back(k);
	}
	for(i=1;i<=d;i++)
	{
		sz=sq[i].size();
		if(!sz)
		{
			for(ii=0;ii<2;ii++)
			{
				k=vl[1].front();
				vl[1].pop();
				sq[i].push_back(k);
			}
		}
	}
	for(;!vl[1].empty();)
	{
		k=vl[1].front();
		vl[1].pop();
		sq[1].push_back(k);
	}
	printf("YES\n");
	for(i=1;i<=m;i++)
	{
		sz=sq[i].size();
		printf("%lld",sz);
		for(j=0;j<sz;j++)
		{
			printf(" %lld",sq[i][j]);
		}
		printf("\n");
	}
}