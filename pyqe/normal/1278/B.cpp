#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long t,rr,i,k,l,df,sm;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&k,&l);
		df=abs(k-l);
		for(sm=0,i=0;sm<df||sm%2!=df%2;i++,sm+=i);
		printf("%lld\n",i);
	}
}