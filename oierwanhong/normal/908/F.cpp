#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
typedef long long ll;
typedef std::pair<int,int> pii;
int read()
{
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	return f*x;
}
ll min(ll a,ll b){return a<b?a:b;}
ll max(ll a,ll b){return a>b?a:b;}
template<typename T> bool umin(T& a,T t){if(a>t)return a=t,1;return 0;}
template<typename T> bool umax(T& a,T t){if(a<t)return a=t,1;return 0;}
/**********/
const int MAXN = 300011;
int a[MAXN];
int main()
{
	int n=read(),lstR=0,lstB=0,lstG=0,sumr=0,sumb=0,mxr=0,mxb=0;
	ll ans=0;
	for(int i=1;i<=n;++i)
	{
		a[i]=read();
		char c=getchar();
		while(c!='R'&&c!='B'&&c!='G')c=getchar();
		if(c=='R')
		{
			if(!lstR)
			{
				if(lstG)sumr=a[i]-a[lstG],umax(mxr,a[i]-a[lstG]);
			}
			else sumr+=a[i]-a[lstR],umax(mxr,a[i]-a[lstR]);
			lstR=i;
		}
		else if(c=='B')
		{
			if(!lstB)
			{
				if(lstG)sumb=a[i]-a[lstG],umax(mxb,a[i]-a[lstG]);
			}
			else sumb+=a[i]-a[lstB],umax(mxb,a[i]-a[lstB]);
			lstB=i;
		}
		else
		{
			if(!lstG)
			{
				ans+=(lstR?sumr+a[i]-a[lstR]:0)+(lstB?sumb+a[i]-a[lstB]:0);
			}
			else
			{
				ans+=a[i]-a[lstG]+min(a[i]-a[lstG],
					(lstR?sumr+a[i]-a[lstR]- max(mxr,a[i]-a[lstR]):0)+(lstB?sumb+a[i]-a[lstB]-max(mxb,a[i]-a[lstB]):0));
			}
			sumr=sumb=mxr=mxb=0,lstR=lstB=0;
			lstG=i;
		}
	}
	printf("%lld\n",ans+sumr+sumb);
	return 0;
}