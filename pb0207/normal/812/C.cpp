#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const long long N=1e5+1e3+7;

long long n,s,a[N],b[N];

bool can(long long m)
{
	memset(b,0,sizeof(b));
	for(long long i=1;i<=n;i++)
		b[i]=a[i]+m*i;
	sort(b+1,b+n+1);
	long long sum=0;
	for(long long i=1;i<=m;i++)
		sum+=b[i];
	if(sum<=s)
		return true;
	else
		return false;
}

int main()
{
	cin>>n>>s;
	for(long long i=1;i<=n;i++)
		cin>>a[i];
	long long l=0,r=n+1;
	while(r-l>1)
	{
		long long mid=(l+r)>>1;
		if(can(mid))
			l=mid;
		else
			r=mid;
	}
	for(long long i=1;i<=n;i++)
		b[i]=a[i]+l*i;
	sort(b+1,b+n+1);
	long long sum=0;
	for(long long i=1;i<=l;i++)
		sum+=b[i];
	cout<<l<<" "<<sum;
}