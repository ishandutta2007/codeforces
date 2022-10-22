#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<set>
typedef long long ll;
typedef std::pair<int,int> pii;
ll read(){ll x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
void umax(int& a,int t){if(a<t)a=t;}
bool umin(int& a,int t){if(a>t)return a=t,1;return 0;}
int abs(int x){return x>0?x:-x;}
/**********/
#define MAXN 2011
const double eps=1e-8;
double f[MAXN];
int g1[MAXN],g2[MAXN],n,m,a,b;
double va[MAXN],vb[MAXN];

double Ca,Cb;
int count()
{
	for(int i=1;i<=n;++i)
	{
		f[i]=f[i-1],g1[i]=g1[i-1],g2[i]=g2[i-1];
		if(f[i-1]+(va[i]-Ca)>f[i])f[i]=f[i-1]+(va[i]-Ca), g1[i]=g1[i-1]+1,g2[i]=g2[i-1];
		if(f[i-1]+(vb[i]-Cb)>f[i])f[i]=f[i-1]+(vb[i]-Cb), g1[i]=g1[i-1],g2[i]=g2[i-1]+1;
		if(f[i-1]+(va[i]-Ca+vb[i]-Cb-va[i]*vb[i])>f[i])
			f[i]=f[i-1]+(va[i]-Ca+vb[i]-Cb-va[i]*vb[i]),g1[i]=g1[i-1]+1,g2[i]=g2[i-1]+1;
	}
	return g2[n];
}
int solve()
{
	double l=0,r=1;
	while(r-l>eps)
	{
		Cb=(l+r)/2;
		int cur=count();
		if(cur==b)return g1[n];
		if(cur>b)l=Cb;
		else r=Cb;
	}
	Cb=(l+r)/2;
	return g1[n];
}
int main()
{
	n=read(),a=read(),b=read();
	double tp;
	for(int i=1;i<=n;++i)scanf("%lf",&tp),va[i]=tp;
	for(int i=1;i<=n;++i)scanf("%lf",&tp),vb[i]=tp;
	double l=0,r=1;
	while(r-l>eps)
	{
		Ca=(l+r)/2;
		int cur=solve();
		if(cur==a)break;
		if(cur>a)l=Ca;
		else r=Ca;
	}
	printf("%.6lf\n",double(f[n]+Ca*a+Cb*b));
	return 0;
}