#include <bits/stdc++.h>//
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 200010
using namespace std;
ll nxt[N],n,m,a[N],b[N],ans=0;
int main(){
	ll i,j;
	scanf("%lld%lld",&n,&m);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(i=0;i<m;i++)
	{
		scanf("%lld",&b[i]);
	}
	for(i=0;i<n;i++)
	{
		a[i]=a[i]-a[i+1];
	}
	for(i=0;i<m;i++)
	{
		b[i]=b[i]-b[i+1];
	}
	n--;
	m--;
	if(m==0)
	{
		printf("%lld\n",n+1);
		return 0;
	}
	nxt[0]=0;
	for(i=1,j=0;i<m;i++)
	{
		while(j&&b[j]!=b[i])
		{
			j=nxt[j-1];
		}
		if(b[j]==b[i])
		{
			j++;
		}
		nxt[i]=j;
	}
	for(i=0,j=0;i<n;i++)
	{
		while(j&&b[j]!=a[i])
		{
			j=nxt[j-1];
		}
		if(b[j]==a[i])
		{
			j++;
		}
		if(j==m)
		{
			ans++;
			j=nxt[j-1];
		}
	}
	printf("%lld\n",ans);
	return 0;
}