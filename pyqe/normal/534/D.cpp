#include <bits/stdc++.h>

using namespace std;

long long n,fq[200069],p[200069],sq[200069];
vector<long long> vl[200069];

int main()
{
	long long i,k,c=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		vl[k].push_back(i);
		fq[k]++;
	}
	for(i=1;i<=n;i++,c++)
	{
		for(;c>=0&&p[c]==fq[c];c-=3);
		if(c<0)
		{
			printf("Impossible\n");
			return 0;
		}
		sq[i]=vl[c][p[c]];
		p[c]++;
	}
	printf("Possible\n");
	for(i=1;i<=n;i++)
	{
		printf("%lld%c",sq[i]," \n"[i==n]);
	}
}