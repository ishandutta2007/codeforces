#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,a[1000005];
ll m;
ll F(ll x,ll y)
{
	ll d=x/y,r=x%y;
	return d*d*(y-r)+(d+1)*(d+1)*r; 
}
ll query(ll x,ll y)
{
	ll l=1,r=x-1,mid;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(F(x,mid)-F(x,mid+1)>=y) l=mid+1;
		else r=mid-1; 
	}
	return l;
}
ll sum,tans;
bool check(ll x)
{
	sum=0,tans=0;
	for(int i=1;i<=n;i++)
	{
		ll q=query(a[i]-a[i-1],x);
		sum+=(q-1);
		tans+=F(a[i]-a[i-1],q);
	//	printf("x=%lld,i=%d,q=%lld\n",x,i,q);
	}
	return tans<=m;
}
int main()
{
//	freopen("CF1661F.in","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	scanf("%lld",&m);
	ll l=0,r=1e18,mid;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(check(mid)) l=mid+1;
		else r=mid-1;
	}
	check(r);
	sum-=(m-tans)/r;
	printf("%lld\n",sum);
	return 0;
}