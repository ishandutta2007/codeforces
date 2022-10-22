#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
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
ll abs(ll x){return x>0?x:-x;}
/**********/
const int MAXN = 1000011,mod = 1e9+7,inv2=(mod+1)>>1;
struct Vec
{
	ll x,y;
	Vec():x(0),y(0){}
	Vec(ll x,ll y):x(x),y(y) {}
	Vec operator+ (Vec you){return Vec(x+you.x,y+you.y);}
	Vec operator- (Vec you){return Vec(x-you.x,y-you.y);}
	Vec operator+= (Vec you){return (*this)=(*this)+you;}
	Vec operator-= (Vec you){return (*this)=(*this)-you;}
}a[MAXN],sig[MAXN];
Vec takeM(Vec a){return Vec(a.x%mod,a.y%mod);}
Vec operator* (ll k,Vec a){return Vec(k*a.x,k*a.y);}
ll cross(Vec a,Vec b){return a.x*b.y-b.x*a.y;}

int main()
{
	int n=read();
	for(int i=0;i<n;++i)a[i].x=read(),a[i].y=read();
	std::reverse(a,a+n);
	for(int i=0;i<n;++i)a[n+i]=a[i];
	sig[0]=a[0];
	for(int i=1;i<n+n;++i)sig[i]=sig[i-1]+a[i];
	ll all=0,nows=0,nowf=0,ans=0;
	for(int i=0;i<n;++i)
	{
		all+=cross(a[i]-a[0],a[i+1]-a[0]);
	}
	int it=1;
	while((nows+cross(a[it]-a[0],a[it+1]-a[0]))<=all/2)nows+=cross(a[it]-a[0],a[it+1]-a[0]),nowf=(nowf+nows)%mod,++it;
	ans=nowf;
	if(nows*2==all)ans=(ans-(nows>>1))%mod;
	for(int i=1;i<n;++i)
	{
		nowf=(nowf-cross(a[i]-a[i-1],takeM(sig[it]-sig[i]-(it-i)*a[i])))%mod;
		nows-=cross(a[i]-a[i-1],a[it]-a[i-1]);
		while((nows+cross(a[it]-a[i],a[it+1]-a[i]))<=all/2)nows+=cross(a[it]-a[i],a[it+1]-a[i]),nowf=(nowf+nows)%mod,++it;
		ans=(ans+nowf)%mod;
		if(nows*2==all)ans=(ans-(nows>>1))%mod;
	}
	printf("%lld\n",((all%mod*n%mod*(n-3)%mod*inv2%mod-2*ans)%mod+mod)%mod);
	return 0;
}