#include<iostream>
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

int n,a,b;

int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}

int main()
{
	cin>>n;
	for(int i=1;n-i>i;i++)
	{
		if(gcd(i,n-i)!=1)
			continue;
		a=i,b=n-i;
	}
	cout<<a<<" "<<b;
}