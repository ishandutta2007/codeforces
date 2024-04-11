#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long t,rr,i;
	string s;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		cin>>s;
		n=s.length();
		if(n%2)
		{
			printf("NO\n");
			continue;
		}
		for(i=0;i<n/2;i++)
		{
			if(s[i]!=s[i+n/2])
			{
				break;
			}
		}
		if(i>=n/2)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}