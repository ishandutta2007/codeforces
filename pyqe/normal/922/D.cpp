#include <bits/stdc++.h>

using namespace std;

long long n;
array<long long,2> a[100069];

bool cmp(array<long long,2> x,array<long long,2> y)
{
	return x[1]*y[0]<y[1]*x[0];
}

int main()
{
	long long ln,i,j,k,sm=0,z=0;
	string s;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		cin>>s;
		ln=s.length();
		for(j=0;j<ln;j++)
		{
			k=s[j]=='h';
			z+=a[i][!k]*k;
			a[i][k]++;
		}
	}
	sort(a+1,a+n+1,cmp);
	for(i=1;i<=n;i++)
	{
		z+=a[i][1]*sm;
		sm+=a[i][0];
	}
	printf("%lld\n",z);
}