#include <bits/stdc++.h>

using namespace std;

long long n,sq[200069],inf=1e18;

int main()
{
	long long t,rr,i,u,k,sm,mn,mx;
	string s;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		cin>>s;
		sm=0;
		mn=inf;
		mx=-inf;
		for(i=1;i<=n;i++)
		{
			k=s[i-1]-'0';
			u=!k*2-1;
			sm+=u;
			sq[i]=sm+k;
			mn=min(mn,sq[i]);
			mx=max(mx,sq[i]);
		}
		printf("%lld\n",mx-mn+1);
		for(i=1;i<=n;i++)
		{
			sq[i]-=mn-1;
			printf("%lld%c",sq[i]," \n"[i==n]);
		}
	}
}