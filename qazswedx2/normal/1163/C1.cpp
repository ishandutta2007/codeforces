#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
struct li
{
	int x,y;
	double b,c;
}a[1000005],val[1000005];
bool cmp(const li xx,const li yy)
{
	if(xx.y*yy.x!=yy.y*xx.x) return xx.y*yy.x<yy.y*xx.x;
	if(fabs(xx.b-yy.b)>1e-9) return xx.b<yy.b;
	return xx.c<yy.c;
}
bool isel(const li xx,const li yy)
{
	return xx.y*yy.x==yy.y*xx.x;
}
bool operator ==(const li xx,const li yy)
{
	return xx.y*yy.x==yy.y*xx.x&&fabs(xx.b-yy.b)<1e-9&&fabs(xx.c-yy.c)<1e-9;
}
int n,vx[100005],vy[100005],t=0,len;
ll ans=0;
double getb(int x,int y)
{
	if(a[t].x==0) return 0;
	double v=(double)a[t].y/a[t].x;
	double b=x*v-y;
	return b;
}
double getcc(int x,int y)
{
	if(a[t].x==0) return x;
	return 0;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&vx[i],&vy[i]);
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		{
			a[++t].x=vx[j]-vx[i];
			a[t].y=vy[j]-vy[i];
			if(a[t].x<0||(a[t].x==0&&a[t].y<0)) a[t].x=-a[t].x,a[t].y=-a[t].y;
			a[t].b=getb(vx[i],vy[i]);
			a[t].c=getcc(vx[i],vy[i]);
			//printf("x=%d,y=%d,b=%.2lf,c=%.2lf\n",a[t].x,a[t].y,a[t].b,a[t].c);
		}
	sort(a+1,a+t+1,cmp);
	for(int i=1;i<=t;i++)
	{
		if(i==1||!(a[i]==a[i-1]))
			val[++len]=a[i];
		//else printf("i=%d\n",i);
	}
	int sum=1;
	for(int i=2;i<=len;i++)
	{
		if(!isel(val[i],val[i-1]))
		{
			ans=ans-1ll*sum*(sum-1)/2;
			//printf("sum=%d\n",sum);
			sum=1;
		}
		else sum++;
		//printf("-x=%d,y=%d,b=%.2lf,c=%.2lf\n",val[i].x,val[i].y,val[i].b,val[i].c);
	}
	ans=ans-1ll*sum*(sum-1)/2;
	//printf("sum=%d\n",sum);
	//printf("len=%d,t=%d,ans=%d\n",len,t,ans);
	printf("%I64d",1ll*len*(len-1)/2+ans);
	return 0;
}