#include <bits/stdc++.h>

using namespace std;

const long long d=1e9;
long long n,m,ky[10]={0,1,5,d,d,2,d,d,8,d};

int main()
{
	long long t,rr,p,p2,z,z2;
	char ch;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld %c%lld",&n,&m,&p,&ch,&p2);
		for(;1;p2++,p+=p2/m,p2%=m,p%=n)
		{
			z=ky[p2%10]*10+ky[p2/10];
			z2=ky[p%10]*10+ky[p/10];
			if(z<n&&z2<m)
			{
				break;
			}
		}
		printf("%lld%lld:%lld%lld\n",p/10,p%10,p2/10,p2%10);
	}
}