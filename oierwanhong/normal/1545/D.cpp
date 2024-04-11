#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<random>
#include<map>
typedef long long ll;
typedef unsigned un;
typedef unsigned long long ull;
typedef std::pair<int,int> pii;
ll read()
{
	ll x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	return f*x;
}
ll min(ll a,ll b){return a<b?a:b;}
ll max(ll a,ll b){return a>b?a:b;}
template<typename T> bool umin(T& a,T t){if(a>t)return a=t,1;return 0;}
template<typename T> bool umax(T& a,T t){if(a<t)return a=t,1;return 0;}
/**********/
const int MAXN = 1011,mod = 998244353;
int a[MAXN][MAXN];
ll S1[MAXN],S2[MAXN],DS2[MAXN];
std::map<ll,int>mp;
int main()
{
	int n=read(),m=read();
	for(int i=0;i<m;++i)
	{
		for(int j=1;j<=n;++j)a[i][j]=read(),S1[i]+=a[i][j],S2[i]+=ll(a[i][j])*a[i][j];
		if(i>0)++mp[S1[i]-S1[i-1]],DS2[i]=S2[i]-S2[i-1];
	}
	/*
	puts("S2:");
	for(int i=1;i<m;++i)printf("%lld ",S2[i]);
	puts("");
	puts("DS2:");
	for(int i=1;i<m;++i)printf("%lld ",S2[i]-S2[i-1]);
	puts("");
	puts("DDS2:");
	for(int i=1;i<m;++i)printf("%lld ",DS2[i]-DS2[i-1]);
	puts("");
	*/
	for(int t=1;t<m;++t)
		if(mp[S1[t]-S1[t-1]]==1)
		{
			printf("%d ",t);
			ll x,y;
			if(t>2)
			{
				x=S1[t]-(S1[t-1]+(S1[2]-S1[1]));
				y=S2[t]-(S2[t-1]+DS2[t-1]+(DS2[2]-DS2[1]));
			}
			else
			{
				x=S1[t]-(S1[t-1]+(S1[m-1]-S1[m-2]));
				y=S2[t]-(S2[t-1]+DS2[m-1]-(m-1-t)*(DS2[m-1]-DS2[m-2]));
			}
			printf("%lld\n",(y/x-x)/2);
			fflush(stdout);
			return 0;
		}
	return 0;
}