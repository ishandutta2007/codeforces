#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
struct pt
{
	int x,y;
	pt(int x=0,int y=0):x(x),y(y){}
}a[100005],b[100005];
int n,bt;
ll ans=0;
pt operator-(const pt a,const pt b)
{
	return pt(a.x-b.x,a.y-b.y);
}
ll Cross(pt a,pt b)
{
	return 1ll*a.x*b.y-1ll*a.y*b.x;
}
bool cmp(const pt p,const pt q)
{
	if((p.x>0)!=(q.x>0)) return (p.x>0)>(q.x>0);
	return Cross(p,q)>0;
}
void solve()
{
	sort(b+1,b+bt+1,cmp);
	int nw=1;
	ll nans=0;
	for(int i=1;i<=bt;i++)
	{
		while(nw%bt+1!=i&&Cross(b[i],b[nw%bt+1])>=0) nw=nw%bt+1;
		int len=(nw-i+bt)%bt;
		nans+=1ll*len*(len-1)/2;
	}
//	printf("nans=%lld,%lld\n",nans,1ll*(n-1)*(n-2)*(n-3)/6-nans);
	ans+=1ll*(n-1)*(n-2)*(n-3)/6-nans;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)	
		scanf("%d%d",&a[i].x,&a[i].y);
	for(int i=1;i<=n;i++)
	{
		bt=0;
		for(int j=1;j<=n;j++)
			if(i!=j)
				b[++bt]=a[j]-a[i];
		solve();
	}
	ans=ans*(n-4);
	printf("%lld\n",ans/2);
	return 0;
}