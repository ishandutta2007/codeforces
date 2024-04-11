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
		scanf("%lld",&n);
		cin>>s;
		for(i=1;i<=n&&s[i-1]!='8';i++);
		if(n-i+1>=11)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}