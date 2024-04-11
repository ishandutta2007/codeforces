#include <bits/stdc++.h>

using namespace std;

long long n,a[200069];

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
			a[i]=(s[i-1]=='1')-(s[i-1]=='?');
			if(!a[i])
			{
				mn=min(mn,i);
			}
			else if(a[i]==1)
			{
				mx=i;
			}
		}
		printf("%lld\n",min(mn,n)-max(mx,1ll)+1);
	}
}