#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long t,rr,i,k,c,mx;
	string s;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		cin>>s;
		n=s.length();
		mx=0;
		c=0;
		for(i=1;i<=n;i++)
		{
			k=s[i-1]=='L';
			c=(c+1)*k;
			mx=max(mx,c);
		}
		printf("%lld\n",mx+1);
	}
}