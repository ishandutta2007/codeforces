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
const int MAXN = 400011,B = 1000;
int n,k,x;
int a[MAXN],b[MAXN],c[MAXN],pos[MAXN];
int nextX()
{
	x=(ll(x)*37+10007)%1000000007;
	return x;
}
void init()
{
	for(int i=0;i<n;++i)a[i]=i+1;
	for(int i=0;i<n;++i)std::swap(a[i],a[nextX()%(i+1)]);
	for(int i=0;i<n;++i)pos[a[i]]=i;
	for(int i=0;i<n;++i)
		if(i<k)b[i]=1;
		else b[i]=0;
	for(int i=0;i<n;++i)std::swap(b[i],b[nextX()%(i+1)]);
}
int main()
{
	n=read(),k=read(),x=read();
	init();
	if(k<B)// k<B
	{
		for(int i=0;i<n;++i)
			if(b[i])
				for(int j=0;j<n-i;++j)umax(c[i+j],a[j]);
		for(int i=0;i<n;++i)printf("%d\n",c[i]);
	}
	else
	{
		for(int x=n;x>=n-600&&x;--x)
		{
			int i=pos[x];
			for(int j=0;j<n-i;++j)
				if(b[j]&&c[i+j]==0)c[i+j]=x;
		}
		for(int i=0;i<n;++i)
			if(c[i]==0)
			{
				for(int j=0;j<=i;++j)
					if(b[j])umax(c[i],a[i-j]);
			}
		for(int i=0;i<n;++i)printf("%d\n",c[i]);
	}
	return 0;
}