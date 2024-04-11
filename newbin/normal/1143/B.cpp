#include <iostream>
#include <cmath>
#define LL long long
using namespace std;
LL solve(LL n)
{
	LL sum=1;
	while(n)
	{
		sum*=(n%10);
		n/=10;
	}
	return sum;
}
LL cal(int x)
{
	LL sum=0;
	for(int i=0;i<x;i++)
	{
		sum=sum*10+9;;
	}
	return sum;
}
LL poww(int x)
{
	LL sum=1;
	for(int i=0;i<x;i++)
	sum=sum*10;
	return sum;
}
int main()
{
	LL n;cin>>n;
	if(n>0&&n<10){cout<<n;return 0;}
	
	int tot=0,mid=n;
	while(mid)
	{
		mid/=10;
		tot++;
	}
	
	LL ans=solve(n);
	
	for(int i=1;i<tot;i++)
	{
		
		LL po=poww(i);
		
		n=(n/po-1)*po+cal(i);
		ans=max(ans,solve(n));
	}
	cout<<ans;
}