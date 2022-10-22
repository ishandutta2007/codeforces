#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

typedef long long ll;

ll n;

bool isprime(int x)
{
	for(int i=2;i*i<=x;i++)
		if(x%i==0)
			return false;
	return true;
}

int main()
{
	cin>>n;
	if(n==4)
	{
		cout<<2;
		exit(0);
	}
	if(isprime(n))
	{
		cout<<1;
		exit(0);
	}
	if(n&1)
	{
		if(isprime(n-2))
			cout<<2;
		else
			cout<<3;
		exit(0);
	}
	else
	{
		cout<<2;
		exit(0);
	}
}