#include <bits/stdc++.h>

using namespace std;

long long inf=(1ll<<32)-1;
stack<long long> sk;

int main()
{
	long long t,rr,k,z=0;
	string s;
	
	sk.push(1);
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		cin>>s;
		if(s[0]=='a')
		{
			z+=sk.top();
			if(z>inf)
			{
				printf("OVERFLOW!!!\n");
				return 0;
			}
		}
		else if(s[0]=='f')
		{
			scanf("%lld",&k);
			sk.push(min(sk.top()*k,inf+1));
		}
		else
		{
			sk.pop();
		}
	}
	printf("%lld\n",z);
}