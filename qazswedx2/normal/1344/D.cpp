#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;
typedef long long ll;
struct pt
{
	ll a,b;
	int id;
	pt(ll a=0,ll b=0,int id=0):a(a),b(b),id(id){}
	bool operator<(const pt x) const
	{
		return (x.a-a)>3ll*(x.b+b+1)*(x.b-b);
	}
};
priority_queue<pt> pq;
int n;
ll k,a[100005],b[100005];
bool check(double x)
{
	double ans=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>=x)
		{
			ans+=min(sqrt((a[i]-x)/3.0),(double)a[i]);
			if(ans>k) return 0;
		}
	}
//	printf("x=%lf,ans=%lf\n",x,ans);
	return ans<=k;
}
int main()
{
	//freopen("cf1344d.in","r",stdin);
	scanf("%d%lld",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	ll l=-3e18,r=1e9,mid;
	while(r-l>1)
	{
	//	printf("l=%Lf,r=%Lf\n",l,r);
		mid=(l+r)/2;
		if(check(mid)) r=mid;
		else l=mid;
	}
	for(int i=1;i<=n;i++)
		if(a[i]>=r) b[i]=max(min(max((ll)floor(sqrt((a[i]-r)/3.0)-1e-9),0ll),a[i])-2,0ll);
		else b[i]=0;
	//return 0;
	for(int i=1;i<=n;i++)
	{
		k-=b[i];
		//printf("i=%d,b=%d\n",i,b[i]);
		if(b[i]<a[i]) pq.push(pt(a[i],b[i],i));
	}
	//printf("k=%lld\n",k);
	while(k--)
	{
		pt u=pq.top();
		pq.pop();
		b[u.id]++;
		if(u.b+1<u.a) pq.push(pt(u.a,u.b+1,u.id));
	}
	for(int i=1;i<=n;i++)
		printf("%lld ",b[i]);
	return 0;
}