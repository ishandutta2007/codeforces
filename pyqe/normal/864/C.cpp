#include <bits/stdc++.h>

using namespace std;

long long n,m,d,ln;

int main()
{
	long long i,k,w,z=0;
	
	scanf("%lld%lld%lld%lld",&ln,&m,&d,&n);
	if(m<d)
	{
		printf("-1\n");
		return 0;
	}
	w=m;
	for(i=1;i<=n+1;i++)
	{
		k=i%2?d:ln-d;
		if(i-1&&i<=n)
		{
			k*=2;
		}
		if(w<k)
		{
			w=m;
			z++;
		}
		if(w<k)
		{
			printf("-1\n");
			return 0;
		}
		w-=k;
	}
	printf("%lld\n",z);
}