#include <bits/stdc++.h>

using namespace std;

long long n[2];
bitset<100069> a[2];

int main()
{
	long long t,rr,i,ii,z;
	string s;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		for(ii=0;ii<2;ii++)
		{
			cin>>s;
			n[ii]=s.length();
			for(i=1;i<=n[ii];i++)
			{
				a[ii][i]=s[i-1]-'0';
			}
		}
		for(z=0,ii=1,i=0;1;i++,z+=!ii)
		{
			for(;ii>=0&&a[ii][n[ii]-i];ii--);
			if(ii<0)
			{
				break;
			}
		}
		printf("%lld\n",z);
	}
}