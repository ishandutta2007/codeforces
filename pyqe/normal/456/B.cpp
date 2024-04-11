#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long i,j,d,z=0,k;
	string s;
	
	cin>>s;
	n=s.length();
	d=s[n-1]-'0';
	if(n>1)
	{
		d+=(s[n-2]-'0')*10;
	}
	d%=4;
	for(i=1;i<=4;i++)
	{
		for(k=1,j=0;j<d;j++,k*=i);
		z+=k;
	}
	z%=5;
	printf("%lld\n",z);
}