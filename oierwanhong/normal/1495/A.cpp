#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
typedef long long ll;
typedef unsigned un;
typedef std::vector<int> P;
typedef std::pair<int,int> pii;
ll read(){ll x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
template <typename T> bool umax(T& a,T t){if(t>a)return a=t,1;return 0;}
template <typename T> bool umin(T& a,T t){if(t<a)return a=t,1;return 0;}
int abs(int x){return x>0?x:-x;}
/**********/
const int MAXN = 400011;
int a[MAXN],b[MAXN];
int main()
{
	int task=read();
	while(task--)
	{
		int n=read(),n1=0,n2=0;
		for(int i=1;i<=2*n;++i)
		{
			int x=read(),y=read();
			if(x==0)a[++n1]=abs(y);
			else b[++n2]=abs(x);
		}
		std::sort(a+1,a+n+1),std::sort(b+1,b+n+1);
		double ans=0;
		for(int i=1;i<=n;++i)ans+=sqrt(double(a[i])*a[i]+double(b[i])*b[i]);
		printf("%.12lf\n",ans);
	}
	return 0;
}