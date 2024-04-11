#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
struct pt
{
	int p,t,id;
	ll l,r;
}a[1000005],f[1000005];
int n,ft;
ll nw;
bool operator<(const pt x,const pt y)
{
	return 1ll*x.p*y.t>1ll*y.p*x.t;
}
bool cmp(const pt x,const pt y)
{
	return x.p<y.p;
}
bool check(double c)
{
	for(int i=1;i<ft;i++)
	{
		//printf("c=%f,i=%d,%f,%f\n",c,i,f[i].p*(1-c*f[i].l/nw),f[i+1].p*(1-c*f[i+1].r/nw));
		if(f[i].p*(1-c*f[i].l/nw)>f[i+1].p*(1-c*f[i+1].r/nw))
			return 0;
	}
	return 1;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i].p),a[i].id=i;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i].t);
	sort(a+1,a+n+1);
	nw=0;
	for(int l=1,r;l<=n;l=r+1)
	{
		r=l;
		while(r<n&&1ll*a[r+1].p*a[l].t==1ll*a[r+1].t*a[l].p)
			r++;
		ll q=nw;
		for(int i=l;i<=r;i++)
			q+=a[i].t;
		for(int i=l;i<=r;i++)
			a[i].l=nw+a[i].t,a[i].r=q;
		nw=q;
	}
	sort(a+1,a+n+1,cmp);
	for(int l=1,r;l<=n;l=r+1)
	{
		r=l;
		while(r<n&&a[r+1].p==a[l].p) r++;
		ft++;
		f[ft]=a[l];
		for(int i=l;i<=r;i++)
			f[ft].l=min(f[ft].l,a[i].l),f[ft].r=max(f[ft].r,a[i].r);
	}
	double l=0,r=1,mid;
	for(int i=1;i<=50;i++)
	{
		mid=(l+r)/2;
		if(check(mid)) l=mid;
		else r=mid;
	}
	printf("%.10f\n",l);
	return 0;
}