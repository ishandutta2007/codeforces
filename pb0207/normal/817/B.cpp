#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int N=1e5+1e3+7;

int a[N],n,tmp,ans=1,cnt,a1,a2,a3,b[N];

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],b[i]=a[i];
	sort(a+1,a+n+1);
	a1=a[1],a2=a[2],a3=a[3];
	sort(b+1,b+n+1);
	if(a1==a2&&a2==a3)
	{
		long long k=upper_bound(b+1,b+n+1,a1)-lower_bound(b+1,b+n+1,a1);
		cout<<k*(k-1)*(k-2)/6;
	}
	else
	if(a1==a2)
	{
	    long long k1=upper_bound(b+1,b+n+1,a1)-lower_bound(b+1,b+n+1,a1);
		long long k3=upper_bound(b+1,b+n+1,a3)-lower_bound(b+1,b+n+1,a3);
		cout<<k3;
	}
	else
	if(a2==a3)
	{
	    long long k3=upper_bound(b+1,b+n+1,a3)-lower_bound(b+1,b+n+1,a3);
	    cout<<k3*(k3-1)/2;
	}
	else
	{
		ans*=upper_bound(b+1,b+n+1,a1)-lower_bound(b+1,b+n+1,a1);
		ans*=upper_bound(b+1,b+n+1,a2)-lower_bound(b+1,b+n+1,a2);
		ans*=upper_bound(b+1,b+n+1,a3)-lower_bound(b+1,b+n+1,a3);
		cout<<ans;
	}
	
}