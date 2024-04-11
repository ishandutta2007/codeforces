#include <bits/stdc++.h>

using namespace std;

long long n,d,fq[26];

int main()
{
	long long i,k,w;
	char ch;
	
	scanf("%lld%lld",&n,&d);
	for(i=1;i<=n;i++)
	{
		scanf(" %c",&ch);
		k=ch-'a';
		d-=(1ll<<k)*((i==n)*2-1);
		fq[k]+=i<n-1;
	}
	if(d<0)
	{
		printf("No\n");
		return 0;
	}
	for(i=25;i+1;i--)
	{
		w=min(d>>i+1,fq[i]);
		d-=w<<i+1;
	}
	if(!d)
	{
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}
}