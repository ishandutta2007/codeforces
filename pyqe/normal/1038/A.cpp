#include <bits/stdc++.h>

using namespace std;

long long n,m,fq[26],inf=1e18;

int main()
{
	long long i,mn=inf;
	char ch;
	
	scanf("%lld%lld",&n,&m);
	for(i=0;i<n;i++)
	{
		scanf(" %c",&ch);
		fq[ch-'A']++;
	}
	for(i=0;i<m;i++)
	{
		mn=min(mn,fq[i]);
	}
	printf("%lld\n",mn*m);
}