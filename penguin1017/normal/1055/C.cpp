#include "bits/stdc++.h"
using namespace std;
long long gcd(long long a,long long b)
{
	if(b==0)return a;
	return gcd(b,a%b);
}
int main()
{
	long long l1,r1,t1,l2,r2,t2,d,a,b,day,ans=0;
	cin>>l1>>r1>>t1>>l2>>r2>>t2;
	d=gcd(t1,t2);
	a=r1-l1+1;
	b=r2-l2+1;
	if(l1<l2)
	{
		t1=a;
		a=b;
		b=t1;
		day=l2-l1;
	}
	else day=l1-l2;
	day=day-day/d*d;
	ans=max(ans,min(a,b-day));
	day-=d;
	ans=max(ans,min(a+day,b));
	cout<<ans; 
	
}