#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
typedef long long ll;
typedef unsigned un;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
ll read()
{
	ll f=1,x=0;int c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	return f*x;
}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
ll abs(ll x){return x>0?x:-x;}
template<typename T> inline bool umin(T& a,T t){if(t<a)return a=t,1;return 0;}
template<typename T> inline bool umax(T& a,T t){if(t>a)return a=t,1;return 0;}
/**********/
const int MAXN = 400011;
int a[MAXN], b[MAXN],add[MAXN];
int main()
{
	int task=read();
	while(task--)
	{
		int n=read();
		ll one=0;
		for(int i=1;i<=n;++i)b[i]=read(),one+=b[i];
		for(int i=0;i<=n;++i)add[i]=0;
		one/=n;
		int dec=0,rest=one;
		for(int i=n;i;--i)
		{
			dec-=add[i];
			//printf("i=%d,b[i]=%d,dec=%d\n",i,b[i],dec);
			if(b[i]-dec==i)
			{
				a[i]=1;
				++dec,++add[i-rest];
				--rest;
			}
			else if(b[i]-dec==1||b[i]==0)
			{
				++dec,++add[i-rest];
				a[i]=0;
			}
		}
		for(int i=1;i<=n;++i)printf("%d ",a[i]);
		puts("");
	}
	return 0;
}