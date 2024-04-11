#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;

const int N=1e5+1e3+7;

long long n,k,x,a[N],ans;

int main()
{
	cin>>n>>x>>k;
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		long long l=a[i]/x+(a[i]%x!=0);
		long long f1=(l+k-1)*x,f2=f1+x-1;
		if(k==0)
		{
			f1=a[i];
			f2=l*x-1;
		}
		ans+=upper_bound(a+1,a+n+1,f2)-lower_bound(a+1,a+n+1,f1);
	}
	cout<<ans;
}