#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long t,rr,i,k,ls,z;
	string s;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		cin>>s;
		n=s.length();
		z=0;
		ls=0;
		for(i=1;i<=n;i++)
		{
			k=s[i-1]-'0';
			if(k)
			{
				if(ls)
				{
					z+=i-ls-1;
				}
				ls=i;
			}
		}
		printf("%lld\n",z);
	}
}