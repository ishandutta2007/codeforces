#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
struct Point
{
	ll x,y;
	Point(ll x=0,ll y=0):x(x),y(y){}
}p[10005],p2[10005],q[4000005];
typedef Point Vector;
Point operator+(const Point a,const Point b)
{
	return Point(a.x+b.x,a.y+b.y);
}
Point operator-(const Point a,const Point b)
{
	return Point(a.x-b.x,a.y-b.y);
}
ll Cross(const Point a,const Point b)
{
	return a.x*b.y-a.y*b.x;
}
bool operator<(const Point a,const Point b)
{
	return Cross(a,b)>0;
}
bool operator<=(const Point a,const Point b)
{
	return Cross(a,b)>=0;
}
bool cmp2(const Point a,const Point b)
{
	return a.y==b.y?a.x>b.x:a.y<b.y;
}
struct pt
{
	Point l,r;
	pt(){}
	pt(Point l,Point r):l(l),r(r){}
}b[2000005],c[2000005];
bool cmp(const pt a,const pt b)
{
	return Cross(a.l,b.l)>0;
}
double getans(Point p,Vector v)
{
	return p.x-1.0*p.y/v.y*v.x;
}
int n,a[100005][3],bt,ct,t,st[100005],tp,st2[100005],tp2;
double tans[4000005];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
		p[i]=Point(a[i][0],a[i][2]);
		p2[i]=Point(a[i][1],a[i][2]);
	}
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		{
			int xl=a[i][0],xr=a[i][1],y=a[i][2];
			int xxl=a[j][0],xxr=a[j][1],yy=a[j][2];
			if(y==yy) continue;
			if(y<yy) swap(y,yy),swap(xl,xxl),swap(xr,xxr);
			b[++bt]=pt(Point(xxl-xr,yy-y),Point(xxr-xl,yy-y));
		}
	sort(b+1,b+bt+1,cmp);
	//for(int i=1;i<=bt;i++)
	//	printf("i=%d,l=%d,%d,r=%d,%d\n",i,b[i].l.x,b[i].l.y,b[i].r.x,b[i].r.y);
	for(int i=1;i<=bt;i++)
	{
		if(!ct)
		{
			c[++ct]=b[i];
			continue;
		}
	//	printf("i=%d,%d,b=%d,%d,c=%d,%d\n",i,(int)(b[i].l<=c[ct].r),b[i].l.x,b[i].l.y,c[ct].r.x,c[ct].r.y);
		if(b[i].l<c[ct].r)
		{
			if(c[ct].r<b[i].r) c[ct].r=b[i].r;
		}
		else c[++ct]=b[i];
	}
	for(int i=1;i<=ct;i++)
	{
		q[i*2-1]=c[i].l;
		q[i*2]=c[i].r;
	}
	//for(int i=1;i<=ct*2;i++)
	//	printf("i=%d,q=%d,%d\n",i,q[i].x,q[i].y);
	sort(p+1,p+n+1,cmp2);
	sort(p2+1,p2+n+1,cmp2);
	for(int i=1;i<=n;i++)
	{
		//if(i>1&&p[i].x==p[i-1].x) continue;
		while(tp>1&&Cross(p[st[tp]]-p[st[tp-1]],p[i]-p[st[tp]])>=0) tp--;
		st[++tp]=i;
	}
	for(int i=1;i<=n;i++)
	{
	//	if(i>1&&p2[i].x==p2[i-1].x) continue;
		while(tp2>1&&Cross(p[st2[tp2]]-p[st2[tp2-1]],p[i]-p[st2[tp2]])<=0) tp2--;
		st2[++tp2]=i;
	}
/*	printf("tp=%d,tp2=%d\n",tp,tp2);
	for(int i=1;i<=tp;i++)
		printf("%d ",st[i]);
	printf("\n");
	for(int i=1;i<=tp2;i++)
		printf("%d ",st2[i]);
	printf("\n");*/
	if(!ct)
	{
		ct++;
		q[1]=q[2]=Point(0,-1);
	}
	int nw=1,nw2=1;
	double ans=1e18;
	for(int i=1;i<=ct*2;i++)
	{
		while(nw2<tp2&&getans(p2[st2[nw2]],q[i])<getans(p2[st2[nw2+1]],q[i])) nw2++;
	//	printf("i=%d,nw2=%d,st2=%d,p2=%d,%d,q=%d,%d,getans=%f\n",i,nw2,st2[nw2],p2[st2[nw2]].x,p2[st2[nw2]].y,q[i].x,q[i].y,getans(p2[st2[nw2]],q[i]));
		tans[i]=getans(p2[st2[nw2]],q[i]);
	}
	for(int i=ct*2;i;i--)
	{
		while(nw<tp&&getans(p[st[nw]],q[i])>getans(p[st[nw+1]],q[i])) nw++;
	//	printf("i=%d,nw=%d,st=%d,p=%d,%d,q=%d,%d,getans=%f\n",i,nw,st[nw],p[st[nw]].x,p[st[nw]].y,q[i].x,q[i].y,getans(p[st[nw]],q[i]));
		ans=min(ans,tans[i]-getans(p[st[nw]],q[i]));
	}
	printf("%.10f",ans);
	return 0;
}