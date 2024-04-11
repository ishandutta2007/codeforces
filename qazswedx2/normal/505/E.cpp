#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
struct pt
{
	int h,a;
	ll val,d;
	pt(int h=0,int a=1,ll val=0):h(h),a(a),val(val){d=val/a;}
};
int n,m,k,p,h[100005],a[100005];
bool operator<(const pt x,const pt y)
{
	if(x.d<m||y.d<m) return x.d>y.d;
	return x.val-1ll*m*x.a-x.h>y.val-1ll*m*y.a-y.h;
}
priority_queue<pt> pq;
bool check(ll mid)
{
	while(!pq.empty()) pq.pop();
	for(int i=1;i<=n;i++)
		if(mid-1ll*m*a[i]-h[i]<0) pq.push(pt(h[i],a[i],mid));
	for(int i=1;i<=m;i++)
	{
		if(pq.empty()) return 1;
		pt u=pq.top();
		if(u.d<i) return 0;
		for(int j=1;j<=k;j++)
		{
			if(pq.empty()) return 1;
			pt u=pq.top();
			pq.pop();
			u.val+=p;
			u.d=u.val/u.a;
			if(u.val-1ll*m*u.a-u.h<0)
				pq.push(u);
		}
	}
	return pq.empty();
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&k,&p);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&h[i],&a[i]);
	ll l=1,r=1e18;
	while(l<=r)
	{
		ll mid=(l+r)/2;
		if(check(mid)) r=mid-1;
		else l=mid+1;
	}
	printf("%I64d",l);
	return 0;
}