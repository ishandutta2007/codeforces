#include <bits/stdc++.h>

using namespace std;

long long n,d,a[1000069],dv=1e9+7;

int main()
{
	long long t,rr,i,ii,j,k,z;
	string s;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&d);
		cin>>s;
		n=s.length();
		for(i=1;i<=n;i++)
		{
			a[i]=s[i-1]-'0';
		}
		z=n;
		for(i=1;i<=d;i++)
		{
			k=n;
			for(ii=1;ii<a[i];ii++)
			{
				for(j=1;i+j<=k&&n+j<=d;j++)
				{
					a[n+j]=a[i+j];
				}
				n=min(n+k-i,d);
			}
			z=(z+(z+dv-i)*(a[i]-1))%dv;
		}
		printf("%lld\n",z);
	}
}