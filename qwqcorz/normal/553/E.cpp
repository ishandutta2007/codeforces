#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=55;
const int M=105;
const int T=2e4+5;
const double pi=acos(-1);
const double inf=1e28;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

struct Complex
{
	double x,y;
	Complex operator +(const Complex &a){return (Complex){x+a.x,y+a.y};}
	Complex operator -(const Complex &a){return (Complex){x-a.x,y-a.y};}
	Complex operator *(const Complex &a){return (Complex){x*a.x-y*a.y,x*a.y+a.x*y};}
}F[T*4],G[T*4];
int lim,l,rev[T*4];
void FFT(Complex *a,int type)
{
	for (int i=0;i<lim;i++) if (i<rev[i]) swap(a[i],a[rev[i]]);
	for (int mid=1;mid<lim;mid*=2)
	for (int len=mid*2,k=0;k<lim;k+=len)
	{
		Complex Wn=(Complex){cos(pi/mid),type*sin(pi/mid)},w=(Complex){1,0};
		for (int i=k;i<k+mid;i++,w=w*Wn)
		{
			Complex x=a[i],y=w*a[i+mid];
			a[i]=x+y;
			a[i+mid]=x-y;
		}
	}
	if (type<0) for (int i=0;i<lim;i++) a[i].x=a[i].x/lim;
}
void mul(double *a,double *b,double *c,int n,int m)
{
//	cerr<<"a:";
//	for (int i=0;i<n;i++) cerr<<a[i]<<' ';
//	cerr<<endl;
//	cerr<<"b:";
//	for (int i=0;i<m;i++) cerr<<b[i]<<' ';
//	cerr<<endl;
	lim=1,l=0;
	for (int i=0;i<n;i++) F[i]=(Complex){a[i],0};
	for (int i=0;i<m;i++) G[i]=(Complex){b[i],0};
	while (lim<=n+m) lim*=2,l++;
	for (int i=n;i<lim;i++) F[i]=(Complex){0,0};
	for (int i=m;i<lim;i++) G[i]=(Complex){0,0};
	for (int i=0;i<lim;i++) rev[i]=(rev[i>>1]>>1)|((i&1)<<(l-1));
	FFT(F,1),FFT(G,1);
	for (int i=0;i<lim;i++) F[i]=F[i]*G[i];
	FFT(F,-1);
	for (int i=0;i<lim;i++) c[i]=F[i].x;
}
struct edge
{
	int u,v,w;
	double p[T],sum[T];
}e[M];
int dis[N][N],n,m,t,x;
double f[N][T],g[M][T];
void cdq(int l,int r)
{
//	print(l,' '),print(r);
	if (l==r)
	{
		for (int i=1;i<=n;i++) f[i][l]=inf;
		for (int i=1;i<=m;i++)
		{
			g[i][l]+=e[i].sum[l+1]*(dis[e[i].v][n]+x);
			f[e[i].u][l]=min(f[e[i].u][l],g[i][l]+e[i].w);
		}
		f[n][l]=0;
		return;
	}
	int mid=(l+r)/2;
	cdq(l,mid);
	for (int i=1;i<=m;i++)
	{
		static double ret[T*4];
		mul(f[e[i].v]+l,e[i].p,ret,mid-l+1,r-l+1);
//		cout<<ret[1]<<endl;
		for (int j=mid+1;j<=r;j++) g[i][j]+=ret[j-l];
	}
	cdq(mid+1,r);
}

signed main()
{
	memset(dis,0x3f,sizeof(dis));
	n=read(),m=read(),t=read(),x=read();
	for (int i=1;i<=m;i++)
	{
		e[i].u=read(),e[i].v=read(),e[i].w=read();
		for (int j=1;j<=t;j++) e[i].p[j]=read()/1e5;
		dis[e[i].u][e[i].v]=e[i].w;
		for (int j=t;j>=1;j--) e[i].sum[j]=e[i].sum[j+1]+e[i].p[j];
	}
	for (int i=1;i<=n;i++) dis[i][i]=0;
	for (int k=1;k<=n;k++)
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	cdq(0,t);
	printf("%.10lf\n",f[1][t]);
//	for (int i=0;i<=t;i++)
//	for (int j=1;j<=n;j++)
//	printf("%lf%c",f[j][i]," \n"[j==n]);
	
	return 0;
}
/*
3 2 1 10
1 2 1
100000
2 3 2
100000

*/