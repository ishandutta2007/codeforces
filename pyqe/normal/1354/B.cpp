#include <bits/stdc++.h>

using namespace std;

long long n,ls[3],inf=1e18;

int main()
{
	long long t,rr,i,j,k,mn,z;
	string s;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		cin>>s;
		n=s.length();
		for(i=0;i<3;i++)
		{
			ls[i]=0;
		}
		z=inf;
		for(i=1;i<=n;i++)
		{
			k=s[i-1]-'1';
			ls[k]=i;
			mn=inf;
			for(j=0;j<3;j++)
			{
				mn=min(mn,ls[j]);
			}
			if(mn)
			{
				z=min(z,i-mn+1);
			}
		}
		z*=z!=inf;
		printf("%lld\n",z);
	}
}