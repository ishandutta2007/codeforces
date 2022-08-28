#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
struct pt
{
	ll val,id;
}a[500005];
ll n,m,k,ans=0;
bool cmp(const pt x,const pt y)
{
	return x.val>y.val;
}
bool cmp2(const pt x,const pt y)
{
	return x.id<y.id;
}
int main()
{
	scanf("%I64d%I64d%I64d",&n,&m,&k);
	for(ll i=1;i<=n;i++)
	{
		scanf("%I64d",&a[i].val);
		a[i].id=i;
	}
	sort(a+1,a+n+1,cmp);
	sort(a+1,a+m*k+1,cmp2);
	for(ll i=1;i<=m*k;i++)
		ans+=a[i].val;
	printf("%I64d\n",ans);
	for(ll i=m;i<m*k;i+=m)
	{
		printf("%I64d ",a[i].id);
	}
	return 0;
}