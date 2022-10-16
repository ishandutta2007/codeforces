#include <bits/stdc++.h>

using namespace std;

long long n,nn=0,ln,a[100069],dp[100069],inf=1e18;

int main()
{
	long long i,j,k,sm,ml,mx,zz;
	string s;
	
	scanf("%lld",&n);
	for(k=n;k;k/=10,nn++);
	cin>>s;
	ln=s.length();
	for(i=1;i<=ln;i++)
	{
		a[i]=s[i-1]-'0';
	}
	for(i=1;i<=ln;i++)
	{
		sm=0;
		ml=1;
		for(j=0;j<min(nn,i);j++)
		{
			sm+=ml*a[i-j];
			ml*=10;
			if(sm<n&&(!j||a[i-j]))
			{
				mx=j;
				zz=sm;
			}
		}
		dp[i]=dp[i-mx-1]*n+zz;
	}
	printf("%lld\n",dp[ln]);
}