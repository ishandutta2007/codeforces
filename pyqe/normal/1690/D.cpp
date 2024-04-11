#include <bits/stdc++.h>

using namespace std;

const long long inf=1e18;
long long n,m,ps[200069];

int main()
{
	long long t,rr,i,z;
	char ch;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		z=inf;
		for(i=1;i<=n;i++)
		{
			scanf(" %c",&ch);
			ps[i]=ps[i-1]+(ch=='W');
			if(i>=m)
			{
				z=min(z,ps[i]-ps[i-m]);
			}
		}
		printf("%lld\n",z);
	}
}