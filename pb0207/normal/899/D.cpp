#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

long long a[14]={0,9,99,999,9999,99999,999999,9999999,99999999,999999999,9999999999};

long long n,d[11],ans=0,c[11];

inline long long calc(long long x)
{
	if(x>2*n)
		return 0;
	if(x<=n)
		return x/2;
	long long d=x-n;
	return (n-d+1)>>1;
}

int main()
{
	cin>>n;
	c[0]=1;
	for(int i=1;i<=10;i++)
		c[i]=c[i-1]*10;
	int t=lower_bound(a,a+10+1,n*2)-a-1;
	if(t==0)
	{
		if(n==4)
			cout<<6;
		if(n==3)
			cout<<3;
		if(n==2)
			cout<<1;
		if(n==1)
			cout<<0;
		return 0;
	}
	for(int i=0;i<=9;i++)
	{
		long long delt=c[t]*i;
		delt+=a[t];
		ans+=calc(delt);
	}
	cout<<ans;
}