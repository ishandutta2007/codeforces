#include <bits/stdc++.h>

using namespace std;

long long n,a[200069],inf=1e18;

int main()
{
	long long t,rr,i,j,r,c,z;
	string s;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		cin>>s;
		n=s.length();
		for(i=1;i<=n;i++)
		{
			a[i]=s[i-1]-'0';
		}
		z=-inf;
		for(i=0;i<10;i++)
		{
			for(j=0;j<10;j++)
			{
				c=0;
				for(r=1;r<=n;r++)
				{
					c+=(c%2==0&&a[r]==i)||(c%2&&a[r]==j);
				}
				c-=c%2*(i!=j);
				z=max(z,c);
			}
		}
		printf("%lld\n",n-z);
	}
}