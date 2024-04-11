#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long t,rr,k,l,df;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&k,&l);
		if(k>l)
		{
			swap(k,l);
		}
		df=l-k;
		if(k<df||l<df*2||(k-df)%3!=0||(l-df*2)%3!=0)
		{
			printf("NO\n");
		}
		else
		{
			printf("YES\n");
		}
	}
}