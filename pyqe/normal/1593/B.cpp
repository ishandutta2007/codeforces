#include <bits/stdc++.h>

using namespace std;

long long n,a[100069];

int main()
{
	long long t,rr,i,j,z;
	bool bad;
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
		z=n+1;
		for(i=0;i<100;i+=25)
		{
			bad=0;
			for(j=n;j;j--)
			{
				if(!bad)
				{
					if(a[j]==i%10)
					{
						bad=1;
					}
				}
				else if(a[j]==i/10)
				{
					break;
				}
			}
			if(j)
			{
				z=min(z,n-j-1);
			}
		}
		printf("%lld\n",z);
	}
}