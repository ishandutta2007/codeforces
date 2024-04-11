#include<iostream>
using namespace std;
long long n,s;
bool check(long long x)
{
	long long p=x,tsum=0;
	for(;p;p/=10)tsum+=p%10;
	return x-tsum>=s;
}
int main()
{
	cin>>n>>s;
	long long l=0,r=n+1;
	for(;l<r-1;)
	{
		long long mid=(l+r)>>1;
		if(check(mid))r=mid;
		else l=mid;
	}
	cout<<n-l;
	return 0;
}