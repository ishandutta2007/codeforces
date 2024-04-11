#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long i,k,u,sm=0,z=0;
	string s;
	
	scanf("%lld",&n);
	cin>>s;
	for(i=1;i<=n;i++)
	{
		k=s[i-1]=='(';
		u=k*2-1;
		sm+=u;
		z+=(sm<0&&!k)*2;
	}
	if(sm)
	{
		printf("-1\n");
	}
	else
	{
		printf("%lld\n",z);
	}
}