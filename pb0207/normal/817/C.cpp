#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

long long n,s,nn,cnt;

long long check(long long m)
{
	long long ret=0;
	cnt=0;
	nn=m;
	while(nn)
	{
		ret+=nn%10;
		nn/=10;
	}
	return ret;
}

int main()
{
	cin>>n>>s;
	long long l=0,r=n+1;
	while(r-l>1)
	{
		long long mid=(l+r)>>1;
		if(mid-check(mid)<s)
			l=mid;
		else
			r=mid;
	}
	cout<<(n-l)?(n-l):0;
}