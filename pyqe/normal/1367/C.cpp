#include <bits/stdc++.h>

using namespace std;

long long n,d;

int main()
{
	long long t,rr,i,k,c,z;
	string s;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		cin>>s;
		c=d;
		z=0;
		for(i=1;i<=n+1;i++)
		{
			if(i<=n)
			{
				k=s[i-1]-'0';
			}
			if(i==n+1||k)
			{
				c+=d*(i==n+1);
				z+=max((c+1)/(d+1)-1,0ll);
				c=0;
			}
			else
			{
				c++;
			}
		}
		printf("%lld\n",z);
	}
}