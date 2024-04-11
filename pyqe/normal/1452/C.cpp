#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long t,rr,i,ii,k,c[2],z;
	string s;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		cin>>s;
		n=s.length();
		for(ii=0;ii<2;ii++)
		{
			c[ii]=0;
		}
		z=0;
		for(i=0;i<n;i++)
		{
			k=(long long)(s[i]=='[')+2*(s[i]==')')+3*(s[i]==']');
			if(k<2)
			{
				c[k]++;
			}
			else
			{
				z+=!!c[k-2];
				c[k-2]-=!!c[k-2];
			}
		}
		printf("%lld\n",z);
	}
}