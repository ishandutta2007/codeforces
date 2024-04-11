#include <bits/stdc++.h>

using namespace std;

long long n;
bitset<200069> a;

int main()
{
	long long t,rr,i,j,z=0,sm,c;
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
		z=0;
		for(i=1;i<=18;i++)
		{
			sm=0;
			c=0;
			for(j=1;j<=n;j++)
			{
				sm=sm*2+a[j];
				if(j>i)
				{
					sm-=a[j-i]<<i;
					c++;
					if(a[j-i])
					{
						c=0;
					}
				}
				if(j>=i)
				{
					if(a[j-i+1]&&c+i>=sm)
					{
						z++;
					}
				}
			}
		}
		printf("%lld\n",z);
	}
}