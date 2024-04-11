#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long ll;

const int N=3e5+1e3+7;

int n,k,a[N],b[N];

int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	ll ans=-a[1]+a[n];
	for(int i=1;i<=n-1;i++)
		b[i]=a[i]-a[i+1];
	sort(b+1,b+n);
	for(int i=1;i<=k-1;i++)
		ans+=b[i];
	printf("%lld",ans);
}