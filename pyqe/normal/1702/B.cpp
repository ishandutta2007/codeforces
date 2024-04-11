#include <bits/stdc++.h>

using namespace std;

const long long ma=26;
long long n;
bitset<ma> vtd;

int main()
{
	long long t,rr,i,k,c,z;
	string s;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		cin>>s;
		n=s.length();
		for(i=0;i<ma;i++)
		{
			vtd[i]=0;
		}
		c=0;
		z=0;
		for(i=1;i<=n+1;i++)
		{
			if(i<=n)
			{
				k=s[i-1]-'a';
			}
			if(i>n||c+!vtd[k]>3)
			{
				z++;
				vtd.reset();
				c=0;
			}
			c+=!vtd[k];
			vtd[k]=1;
		}
		printf("%lld\n",z);
	}
}