#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long t,rr,i,sm,mn;
	string s;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		cin>>s;
		sm=0;
		mn=0;
		for(i=0;i<n;i++)
		{
			sm+=(s[i]=='(')*2-1;
			mn=min(mn,sm);
		}
		printf("%lld\n",-mn);
	}
}