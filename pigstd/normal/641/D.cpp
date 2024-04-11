#include<bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int M=1e5+10;
int n;
double maxn[M],minn[M],sum1[M],sum2[M],p1[M],p2[M];

signed main()
{
	cin>>n;
	for (int i=1;i<=n;i++)cin>>maxn[i];
	for (int i=1;i<=n;i++)cin>>minn[i];
	for (int i=1;i<=n;i++)sum1[i]=maxn[i]+sum1[i-1];
	for (int i=n;i>=1;i--)sum2[i]=minn[i]+sum2[i+1];
	for (int i=1;i<=n;i++)
	{
		double x1=sum1[i],x2=sum1[i]-sum2[i+1]+1;
		double d=sqrt(max(x2*x2-4*x1,0.0));
		p1[i]=(x2-d)/2.0,p2[i]=(x2+d)/2.0;
	}
	for (int i=1;i<=n;i++)
		printf("%.8lf ",p1[i]-p1[i-1]);puts("");
	for (int i=1;i<=n;i++)
		printf("%.8lf ",p2[i]-p2[i-1]);puts("");
	return 0;
}