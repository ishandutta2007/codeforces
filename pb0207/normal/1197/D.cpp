#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long ll;

const int N=3e5+1e3+7;

int n;

ll m,k,a[N],s[N],mn[N];

int main()
{
	scanf("%d%lld%lld",&n,&m,&k);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]),s[i]=s[i-1]+a[i];
	ll ans=0;
	for(int i=0;i<m;i++)
		mn[i]=1e18;
	mn[0]=k;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<m;j++)
			ans=max(ans,s[i]-mn[j]);
		mn[i%m]=min(mn[i%m]+k,s[i]+k);
	}
	printf("%lld",ans);
}