#include<bits/stdc++.h>
using namespace std;
int T,n,m,k;
long long a[1111111];
int main()
{
	scanf("%d",&n);
	long long s=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		s+=a[i];
	}
	long long base=1ll*n*(n-1)/2;
	s-=base;
	long long q=s/n,r=s%n;
//	cerr<<s<<' '<<q<<' '<<r<<endl;
	for(int i=1;i<=n;i++)
	{
		printf("%lld ",q+i-1+(i<=r));
	}
	return 0;
}