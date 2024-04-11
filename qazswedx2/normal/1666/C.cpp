#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
struct pt
{
	int x,y;
}a[15];
struct Line
{
	int x,y,xx,yy;
	Line(int x=0,int y=0,int xx=0,int yy=0):x(x),y(y),xx(xx),yy(yy){}
};
Line tans[100005];
int n=3,t;
ll F(ll x)
{
	return x>0?x:-x;
}
/*ll getdis(pt x,pt y)
{
	return F(x.x-y.x)+F(x.y-y.y);
}
ll ans=1e18;
void upd(pt x,pt y,pt z)
{
	ll q=getdis(x,y)+getdis(x,z);
	if(ans>q)
	{
		ans=q;
		t=0;
		tans[++t]=Line()
	}
}*/
int G(int x,int y,int z)
{
	if(x>y) swap(x,y);
	if(x>z) swap(x,z);
	if(y>z) swap(y,z);
	return y;
}
void print(int x,int y,int xx,int yy)
{
	if(x!=xx) tans[++t]=Line(x,y,xx,y);
	if(y!=yy) tans[++t]=Line(xx,y,xx,yy);
}
int main()
{
	for(int i=1;i<=n;i++)
		scanf("%d%d",&a[i].x,&a[i].y);
/*	upd(a[1],a[2],a[3]);
	upd(a[2],a[1],a[3]);
	upd(a[3],a[1],a[2]);*/
	int x=G(a[1].x,a[2].x,a[3].x),y=G(a[1].y,a[2].y,a[3].y);
	for(int i=1;i<=n;i++)
		print(x,y,a[i].x,a[i].y);
	printf("%d\n",t);
	for(int i=1;i<=t;i++)
		printf("%d %d %d %d\n",tans[i].x,tans[i].y,tans[i].xx,tans[i].yy);
	return 0;
}