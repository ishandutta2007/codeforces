#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
typedef long long ll;
ll read()
{
	ll f=1,x=0;int c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	return f*x;
}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
template<typename T> inline bool umin(T& a,T t){if(t<a)return a=t,1;return 0;}
template<typename T> inline bool umax(T& a,T t){if(t>a)return a=t,1;return 0;}
/**********/
const int MAXN = 111,MAXM = 10011;
double f[MAXN][MAXM];
int a[MAXN];
int main()
{
	int n=read(),x=read(),tot=0;
	for(int i=1;i<=n;++i)a[i]=read(),tot+=a[i];
	f[0][0]=1;
	for(int i=1;i<=n;++i)
		for(int j=i;j;--j)
			for(int s=a[i];s<=tot;++s)f[j][s]+=f[j-1][s-a[i]];
	double ans=0;
	for(int j=0;j<n;++j)
	{
		double coef=1;//coef=C(n,j)
		for(int i=0;i<j;++i)coef*=n-i;
		for(int i=1;i<=j;++i)coef/=i;
		for(int s=0;s<=tot;++s)
		{
			double cost=std::min(double(tot-s)/(n-j),(double(n)/(n-j)+1)*(x/2.00));
			ans+=cost*f[j][s]/coef;
		}
	}
	printf("%.10lf\n",ans);
	return 0;
}