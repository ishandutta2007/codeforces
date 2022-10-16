#include <bits/stdc++.h>

using namespace std;

long long n,a[100069];

int main()
{
	long long t,rr,i,mk,sm;
	string s;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		cin>>s;
		n=s.length();
		for(i=1;i<=n;i++)
		{
			a[i]=s[i-1]-'A';
		}
		for(mk=0;mk<1ll<<3;mk++)
		{
			sm=0;
			for(i=1;i<=n;i++)
			{
				sm+=!(mk>>a[i]&1)*2-1;
				if(sm<0)
				{
					break;
				}
			}
			if(i>n&&!sm)
			{
				break;
			}
		}
		if(mk<1ll<<3)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}