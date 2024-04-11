#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e3+5;
const double inf=1e18;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

template<typename T>
void up(T &x,T y){if (x<y) x=y;}
double a[N],b[N];
pair<double,int>dp[N][N];
pair<double,int>check(int n,int A,double k)
{
	for (int i=1;i<=n;i++)
	for (int j=0;j<=min(i,A);j++) dp[i][j]=make_pair(-inf,0);
	dp[0][0]=make_pair(0,0);
	for (int i=0;i<n;i++)
	for (int j=0;j<=min(i,A);j++)
	for (int x=0;x<=1;x++)
	for (int y=0;y<=1;y++)
	{
		auto nxt=dp[i][j];
		nxt.second+=y;
		nxt.first+=x*a[i+1]+y*b[i+1]-x*y*a[i+1]*b[i+1]-k*y;
		up(dp[i+1][j+x],nxt);
	}
	return dp[n][A];
}

signed main()
{
	int n=read(),A=read(),B=read();
	for (int i=1;i<=n;i++) scanf("%lf",a+i);
	for (int i=1;i<=n;i++) scanf("%lf",b+i);
	double l=0,r=N;
	for (int i=1;i<=60;i++)
	{
		double mid=(l+r)/2;
		auto ans=check(n,A,mid);
		if (ans.second==B) break;
		if (ans.second>B) l=mid;
					 else r=mid;
	}
	double mid=(l+r)/2;
	auto ans=check(n,A,mid);
	printf("%.7lf\n",ans.first+B*mid);
	
	return 0;
}