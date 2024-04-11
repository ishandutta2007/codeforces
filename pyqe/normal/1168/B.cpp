#include <bits/stdc++.h>

using namespace std;

long long n;
bitset<300069> a;

int main()
{
	long long i,ln,z,j,r;
	string s;
	bool bad,bad2;
	
	cin>>s;
	n=s.length();
	z=n*(n+1)/2;
	for(i=1;i<=n;i++)
	{
		a[i]=s[i-1]-'0';
	}
	for(ln=1;ln<=n;ln++)
	{
		bad=1;
		for(i=ln;i<=n;i++)
		{
			bad2=0;
			for(j=i-ln+3;j<=i;j++)
			{
				for(r=1;j-r-r>i-ln;r++)
				{
					if(a[j]==a[j-r]&&a[j]==a[j-r-r])
					{
						bad2=1;
						break;
					}
				}
				if(bad2)
				{
					break;
				}
			}
			if(!bad2)
			{
				bad=0;
				z--;
			}
		}
		if(bad)
		{
			break;
		}
	}
	printf("%lld\n",z);
}