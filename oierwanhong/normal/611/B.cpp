#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
typedef long long ll;
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

int main()
{
	ll l=read(),r=read(),ans=0;
	for(int x=0;x<61;++x)
		for(int y=0;y<x;++y)
		{
			ll v=(1ll<<(x+1))-1;
			v^=1ll<<y;
			if(l<=v&&v<=r)++ans;
		}
	printf("%lld\n",ans);
	return 0;
}