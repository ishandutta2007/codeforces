#include <bits/stdc++.h>

using namespace std;

long long n,ps[100069];

int main()
{
	long long t,rr,i,k,l;
	char ch;
	
	scanf("%lld%lld",&n,&t);
	for(i=1;i<=n;i++)
	{
		scanf(" %c",&ch);
		ps[i]=ps[i-1]+(ch-'a'+1);
	}
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&k,&l);
		printf("%lld\n",ps[l]-ps[k-1]);
	}
}