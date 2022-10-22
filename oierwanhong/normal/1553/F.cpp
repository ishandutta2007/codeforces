#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<random>
#include<chrono>
typedef long long ll;
typedef unsigned un;
typedef std::vector<int> P;
typedef std::pair<int,int> pii;
ll read(){ll x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
template <typename T> bool umax(T& a,T t){if(t>a)return a=t,1;return 0;}
template <typename T> bool umin(T& a,T t){if(t<a)return a=t,1;return 0;}
/**********/

const int MAXN = 300011,B = 555,MAXB = (300000-1)/B+1;
struct Block
{
	ll s[MAXN/B+11], a[MAXN];
	void modify(int i,int v)
	{
		int up=min(300000,(i-1)/B*B+B);
		for(int k=i;k<=up;++k)a[k]+=v;
		for(int I=(i-1)/B+2;I<=MAXB;++I)s[I]+=v;
	}
	ll Qsum(int i)
	{
		if(i<=0)return 0;
		if(i>300000)i=300000;
		//printf("Qsum[%d]=%lld\n",i,s[(i-1)/B+1]+a[i]);
		return s[(i-1)/B+1]+a[i];
	}
}b1,b2;//b1:ai mod ak b2: ak mod ai
ll f[B][B];
int main()
{
	int n=read();
	ll ans=0,tot=0;
	for(int i=1;i<=n;++i)
	{
		int x=read();
		for(int l=1,r;l<=x;l=r+1)
		{
			r=x/(x/l);
			ans-=ll(x/l)*(b1.Qsum(r)-b1.Qsum(l-1));
		}
		ans+=ll(i-1)*x;
		b1.modify(x,x);

		if(x<B)
		{
			for(int k=0;k<x;++k)ans+=ll(f[x][k])*k;
		}
		else
		{
			ans+=tot;
			for(int p=1;p*x<=300000;++p)
			{
				int l=p*x,r=(p+1)*x-1;
				//if(b2.Qsum(r)-b2.Qsum(l-1))printf("[%d,%d],sigma=%lld\n",l,r,b2.Qsum(r)-b2.Qsum(l-1));
				ans-=ll(p)*(b2.Qsum(r)-b2.Qsum(l-1))*x;
			}
		}
		b2.modify(x,1);
		for(int m=1;m<B;++m)++f[m][x%m];
		tot+=x;
		printf("%lld ",ans);
	}
	puts("");
	return 0;
}