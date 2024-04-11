#include <bits/stdc++.h>

using namespace std;

long long n;
bitset<100069> a;

int main()
{
	long long t,rr,i,mn,mx;
	string s;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		cin>>s;
		n=s.length();
		mn=n+1;
		mx=0;
		for(i=1;i<=n;i++)
		{
			a[i]=s[i-1]-'0';
			if(i-1&&a[i]==a[i-1])
			{
				if(a[i])
				{
					mn=min(mn,i);
				}
				else
				{
					mx=max(mx,i);
				}
			}
		}
		if(mx<mn)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}