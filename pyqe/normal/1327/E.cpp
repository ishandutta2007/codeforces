#include <bits/stdc++.h>

using namespace std;

long long n,pwk,dv=998244353;

long long pw(long long x,long long y)
{
	if(!y)
	{
		return 1;
	}
	pwk=pw(x,y/2);
	pwk=pwk*pwk%dv;
	if(y%2)
	{
		pwk=pwk*x%dv;
	}
	return pwk;
}

int main()
{
	long long i,z;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		z=(810ll*pw(10,n-i-2)*max(n-1-i,0ll)+90ll*pw(10,n-i-1)*2*(i<n)+10ll*(i==n))%dv;
		printf("%lld%c",z," \n"[i==n]);
	}
}