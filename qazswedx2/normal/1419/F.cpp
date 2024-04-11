#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
struct pt
{
	int x,y,id;
}a[1005],a2[1005];
int n,b[1005],c[1005],bt,ct,f[1005],vis[1005],p[1005],p2[1005];
int find(int x)
{
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
void link(int x,int y)
{
	x=find(x),y=find(y);
	if(x==y) return;
	f[x]=y;
}
int F(int x)
{
	return x>0?x:-x;
}
inline bool check4(int a,int b,int c,int d)
{
	a=vis[find(a)],b=vis[find(b)];
	return (a==c&&b==d)||(a==d&&b==c);
}
bool check2(int xx,int yy,int zz,int l)
{
	for(int i=1;i<n;i++)
		if(a[i].x==a[i+1].x&&check4(a[i].id,a[i+1].id,xx,yy))
		{
			int x=a[i].x,ly=a[i].y,ry=a[i+1].y;
			if(ly>ry) swap(ly,ry);
			for(int j=1;j<=n;j++)
				if(vis[find(a[j].id)]==zz&&a[j].y>ly&&a[j].y<ry)
				{
					int tx=a[j].x,ty=a[j].y;
					if(F(x-tx)<=l&&F(ry-ty)<=l&&F(ly-ty)<=l) return 1;
				}
		}
	for(int i=1;i<n;i++)
		if(a2[i].y==a2[i+1].y&&check4(a2[i].id,a2[i+1].id,xx,yy))
		{
			int x=a2[i].y,ly=a2[i].x,ry=a2[i+1].x;
			if(ly>ry) swap(ly,ry);
			for(int j=1;j<=n;j++)
				if(vis[find(a2[j].id)]==zz&&a2[j].x>ly&&a2[j].x<ry)
				{
					int tx=a2[j].y,ty=a2[j].x;
					if(F(x-tx)<=l&&F(ry-ty)<=l&&F(ly-ty)<=l) return 1;
				}
		}
	return 0;
}
bool check3(int ww,int xx,int yy,int zz,int l)
{
//	printf("check3:ww=%d,xx=%d,yy=%d,zz=%d,l=%d\n",ww,xx,yy,zz,l);
	for(int i=1;i<n;i++)
		if(a[i].x==a[i+1].x&&check4(a[i].id,a[i+1].id,ww,xx))
		{
			int x=a[i].x,ly=a[i].y,ry=a[i+1].y;
			if(ly>ry) swap(ly,ry);
		//	printf("i=%d\n",i);
			for(int j=1;j<n;j++)
			{
			//	printf("j=%d,a=%d,%d,y=%d,%d\n",j,vis[find(a2[j].id)],vis[find(a2[j+1].id)],a2[j].y,a2[j+1].y);
				if(a2[j].y==a2[j+1].y&&check4(a2[j].id,a2[j+1].id,yy,zz))
				{
					int lx=a2[j].x,rx=a2[j+1].x,y=a2[j].y;
			//		printf("j=%d\n",j);
					if(F(lx-x)<=l&&F(rx-x)<=l&&F(ly-y)<=l&&F(ry-y)<=l) return 1;
				}
			}
		}
	return 0;
}
bool check(int l)
{
	for(int i=1;i<=n;i++)
		f[i]=i;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if((a[i].x==a[j].x&&F(a[i].y-a[j].y)<=l)||
			   (a[i].y==a[j].y&&F(a[i].x-a[j].x)<=l))
				link(a[i].id,a[j].id);
	for(int i=1;i<=n;i++)
		vis[i]=0;
	int ct=0;
	for(int i=1;i<=n;i++)
	{
		if(!vis[find(i)]) ct++;
		vis[find(i)]++;
	}
	if(ct==1) return 1;
	if(ct>4) return 0;
	ct=0;
	for(int i=1;i<=n;i++)
		if(vis[i])
			vis[i]=++ct;
//	printf("l=%d,ct=%d\n",l,ct);
	if(ct==2)
	{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(vis[find(i)]==1&&vis[find(j)]==2)
				{
				//	printf("i=%d,j=%d\n",i,j);
					if(F(a[p[i]].x-a[p[j]].x)<=l&&F(a[p[i]].y-a[p[j]].y)<=l||
						a[p[i]].x==a[p[j]].x&&F(a[p[i]].y-a[p[j]].y)<=2ll*l||
						a[p[i]].y==a[p[j]].y&&F(a[p[i]].x-a[p[j]].x)<=2ll*l)
						return 1;
				}
		return 0;
	}
	else if(ct==3)
		return check2(1,2,3,l)||check2(1,3,2,l)||check2(2,3,1,l);
	else
		return check3(1,2,3,4,l)||check3(1,3,2,4,l)||check3(3,4,1,2,l)||check3(2,4,1,3,l)||check3(1,4,2,3,l)||check3(2,3,1,4,l);
}
bool cmp(const pt a,const pt b)
{
	return a.x==b.x?a.y<b.y:a.x<b.x;
}
bool cmp2(const pt a,const pt b)
{
	return a.y==b.y?a.x<b.x:a.y<b.y;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i].x,&a[i].y);
		a[i].id=i;
	//	b[++bt]=a[i].x;
	//	c[++ct]=a[i].y;
		a2[i]=a[i];
	}
	sort(a+1,a+n+1,cmp);
	sort(a2+1,a2+n+1,cmp2);
	for(int i=1;i<=n;i++)
	{
		p[a[i].id]=i;
		p2[a2[i].id]=i;
	}
	/*sort(b+1,b+bt+1);
	sort(c+1,c+ct+1);
	for(int i=1;i<=n;i++)
	{
		a[i].x=lower_bound(b+1,b+bt+1,a[i].x)-b;
		a[i].y=lower_bound(c+1,c+ct+1,a2[i].y)-c;
	}*/
	ll l=1,r=2e9,mid;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(check(mid)) r=mid-1;
		else l=mid+1;
	}
	if(l>2e9) printf("-1\n");
	else printf("%lld\n",l);
	return 0;
}