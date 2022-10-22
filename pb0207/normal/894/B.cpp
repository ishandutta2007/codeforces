#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

long long n,m,P=1e9+7;

int k;

long long qpow(long long a,long long b)
{
	long long ret=1;
	while(b)
	{
		if(b&1)
			ret=ret*a%P;
		b>>=1;
		a=a*a%P;
	}
	return ret;
}

int main()
{
	cin>>n>>m>>k;
	long long an=n&1,am=m&1;
	if(k==-1&&an!=am)
		puts("0");
	else
		cout<<qpow(qpow(2,n-1),m-1);
}