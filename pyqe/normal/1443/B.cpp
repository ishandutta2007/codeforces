#include <bits/stdc++.h>

using namespace std;

long long n,d,dd,nn,a[100069];

int main()
{
	long long t,rr,i,k,c,z;
	string s;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&d,&dd);
		cin>>s;
		n=s.length();
		nn=0;
		c=1e15;
		for(i=1;i<=n;i++)
		{
			k=s[i-1]-'0';
			c+=!k;
			if(k&&c)
			{
				nn++;
				a[nn]=c;
				c=0;
			}
		}
		z=0;
		for(i=1;i<=nn;i++)
		{
			z+=min(d,dd*a[i]);
		}
		printf("%lld\n",z);
	}
}