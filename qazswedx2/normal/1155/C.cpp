#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
ll n,m,a[500005],b[500005],ans;
ll gcd(ll a,ll b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}
int main()
{
	scanf("%I64d%I64d",&n,&m);
	ans=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%I64d",&a[i]);
		if(i>1) ans=gcd(ans,a[i]-a[i-1]);
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%I64d",&b[i]);
		if(ans%b[i]==0)
		{
			printf("YES\n");
			printf("%I64d %d",a[1],i);
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}