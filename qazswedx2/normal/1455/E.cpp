#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
inline int F(int x)
{
	return x>=0?x:-x;
}
struct pt
{
	int x,y;
	pt(int x=0,int y=0):x(x),y(y){}
};
pt operator-(const pt a,const pt b)
{
	return pt(a.x-b.x,a.y-b.y);
}
ll getlen(pt a)
{
	return (ll)F(a.x)+F(a.y);
}
pt a[4];
int c[4],t,vis[4],b[15],bt;
ll ans;
void upd(int r,int xx,int yy,int fl)
{
	ll nans=0;
	nans+=getlen(a[c[0]]-pt(xx,yy));
	nans+=getlen(a[c[1]]-pt(xx+r,yy));
	nans+=getlen(a[c[2]]-pt(xx,yy+r*fl));
	nans+=getlen(a[c[3]]-pt(xx+r,yy+r*fl));
	ans=min(ans,nans);
}
void dfs(int dep,int xx,int yy)
{
	if(dep==4)
	{
		b[0]=a[c[1]].x-xx;
		b[1]=a[c[2]].y-yy;
		b[2]=a[c[3]].x-xx;
		b[3]=a[c[3]].y-yy;
		sort(b,b+4);
		upd(b[1],xx,yy,1);
		b[0]=a[c[1]].x-xx;
		b[1]=yy-a[c[2]].y;
		b[2]=a[c[3]].x-xx;
		b[3]=yy-a[c[3]].y;
		sort(b,b+4);
		upd(b[1],xx,yy,-1);
		return;
	}
	for(int i=0;i<4;i++)
		if(!vis[i])
		{
			vis[i]=1;
			c[dep]=i;
			dfs(dep+1,xx,yy);
			vis[i]=0;
		}
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		ans=1e18;
		for(int i=0;i<4;i++)
			scanf("%d%d",&a[i].x,&a[i].y);
		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++)
				dfs(0,a[i].x,a[j].y);
		printf("%lld\n",ans);
	}
	return 0;
}