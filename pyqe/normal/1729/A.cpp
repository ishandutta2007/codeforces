#include <bits/stdc++.h>

using namespace std;

long long n,m,d;

int main()
{
	long long t,rr,w,w2;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld",&n,&m,&d);
		w=n-1;
		w2=abs(m-d)+d-1;
		printf("%lld\n",(long long)(w<=w2)+2*(w2<=w));
	}
}