#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int inf=(1e9);
struct P
{
	int x,y;
	P(int _x=0,int _y=0):x(_x),y(_y){}
	P operator -(P X) {return P(x-X.x,y-X.y);}
	long long operator ^(P X) {return 1ll*x*X.y-1ll*y*X.x;}
}a[40004],A[40004],v,v1,v2;
struct C
{
	int x,y,r;
	P operator -(C X) {return P(x-X.x,y-X.y);}
}c[204];
int g[404][404],h[404],d[404],n,w,m,ma,mi,p[404],ans,nw,W[404],la[404],sta1[40004],tp1,sta2[40004],tp2,cnt,R,mii;
bool bo;

bool cmp(P a,P b) {return a.x<b.x||a.x==b.x&&a.y<b.y;}
int getmin(int a,int b) {return a<b?a:b;}
int getmax(int a,int b) {return a>b?a:b;}
long long getm(long long a,long long b) {return a<b?a:b;}
long long dis(P a,P b) {return 1ll*(a.x-b.x)*(a.x-b.x)+1ll*(a.y-b.y)*(a.y-b.y);}

long double getdis(P a,P b,P c)
{
	P t; t.x=-((b-a).y); t.y=(b-a).x;
	long long A=((a-c)^t),B=((b-c)^t);
	long double ans;
	if (A>=0&&B>=0||A<=0&&B<=0) ans=getm(dis(a,c),dis(b,c)),ans=ans*dis(a,b);
	else 
	{
		A=((a-c)^(b-c)); if (A<0) A=-A;
		ans=A,ans=ans*A;
	}
	return ans;
}

bool check(int x,int y)
{
	v=c[x]-c[y]; R=c[x].r+c[y].r;
	bo=1;
	for (int i=1; i<=cnt; i++)
		if (((a[i]-v)^(a[i+1]-v))>0) {bo=0; break;}
	if (bo) return 1;
	bo=1;
	for (int i=1; i<=cnt; i++)
		if (((a[i]-v)^(a[i+1]-v))<0) {bo=0; break;}
	if (bo) return 1;
	long double A=1ll*R*R;
	for (int i=1; i<=cnt; i++)
		if (getdis(a[i],a[i+1],v)+0.5<A*dis(a[i],a[i+1])) return 1;
	return 0;
}

int main()
{
	memset(g,0,sizeof(g));
	scanf("%d%d",&n,&w); ma=-1; mi=inf;
	for (int i=1; i<=n; i++) 
		scanf("%d%d",&a[i].x,&a[i].y),ma=getmax(a[i].x,ma),mi=getmin(a[i].x,mi);
	scanf("%d",&m);
	for (int i=1; i<=m; i++) 
	{
		scanf("%d%d%d",&c[i].x,&c[i].y,&c[i].r);
		if (c[i].x-c[i].r<ma-mi) g[1][i+1]=inf;
		if (w-c[i].x-c[i].r<ma-mi) g[i+m+1][m+m+2]=inf;
	}
	cnt=0;
	for (int i=1; i<=n; i++) 
		for (int j=1; j<=n; j++) A[++cnt]=a[i]-a[j];
	sort(A+1,A+1+cnt,cmp); tp1=tp2=0;
	sta1[++tp1]=1; sta2[++tp2]=1;
	for (int i=2; i<=cnt; i++)
	{
		while (tp1>1&&((A[sta1[tp1]]-A[sta1[tp1-1]])^(A[i]-A[sta1[tp1]]))>=0) tp1--;
		sta1[++tp1]=i;
		while (tp2>1&&((A[sta2[tp2]]-A[sta2[tp2-1]])^(A[i]-A[sta2[tp2]]))<=0) tp2--;
		sta2[++tp2]=i;
	}
	cnt=0;
	for (int i=1; i<=tp1; i++) a[++cnt]=A[sta1[i]];
	for (int i=tp2-1; i>1; i--) a[++cnt]=A[sta2[i]];
	a[cnt+1]=a[1];
	for (int i=1; i<=m; i++) g[i+1][i+m+1]=1;
	for (int i=1; i<m; i++)
		for (int j=i+1; j<=m; j++)
			if (check(i,j)) g[i+m+1][j+1]=g[j+m+1][i+1]=inf;
	n=m+m+2; h[0]=n;
	for (int i=1; i<=n; i++) p[i]=1;
	memset(d,0,sizeof(d));
	ans=0; nw=inf; int i=1;
	while (d[1]<n)
	{
		W[i]=nw; bo=0;
		for (int j=p[i]; j<=n; j++)
			if (d[j]==d[i]-1&&g[i][j]>0)
			{
				la[j]=i; bo=1;
				nw=getmin(nw,g[i][j]);
				p[i]=j; i=j; 
				if (i==n)
				{
					while (i!=1) g[i][la[i]]+=nw,g[la[i]][i]-=nw,i=la[i];
					ans+=nw; nw=inf;
				}
				break;
			}
		if (bo) continue;
		mi=n-1;
		for (int j=1; j<=n; j++)
			if (g[i][j]&&d[j]<mi) mi=d[j],mii=j;
		p[i]=mii; h[d[i]]--;
		if (!h[d[i]]) break;
		d[i]=mi+1; h[d[i]]++;
		if (i!=1) i=la[i],nw=W[i];
	}
	printf("%d\n",ans);
	return 0;
}