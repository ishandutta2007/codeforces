#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
typedef long long ll;
typedef std::pair<int,int> pii;
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
const int mod = 998244353;
ll Qpow(ll a,ll p)
{
	ll res=1;
	while(p){if(p&1)res=res*a%mod;a=a*a%mod,p>>=1;}
	return res;
}
struct Mint
{
	int x;
	Mint(){x=0;}
	Mint(ll y){x=(0<=y&&y<mod?y:(y%mod+mod)%mod);}
	void operator+= (Mint a){x+=a.x;if(x>=mod)x-=mod;}
	void operator-= (Mint a){x-=a.x;if(x<0)x+=mod;}
	void operator*= (Mint a){x=ll(x)*a.x%mod;}
	Mint operator- (){return x?mod-x:0;}
	Mint operator++ (){x=(x+1==mod?0:x+1);return x;}
};
Mint operator+ (Mint a,Mint b){int t=a.x+b.x;return t<mod?t:t-mod;}
Mint operator- (Mint a,Mint b){int t=a.x-b.x;return t>=0?t:t+mod;}
Mint operator* (Mint a,Mint b){return ll(a.x)*b.x%mod;}

int gcd(int a,int b){return b?gcd(b,a%b):a;}
const int MAXL = 12252245;
Mint pw[20],f[MAXL],pre[MAXL];
int main()
{
	int n=read(),s=read(),x=read(),y=read(),k=read(),m=read();
	int L=1;
	pw[0]=1;
	for(int i=1;i<=k;++i)pw[i]=pw[i-1]*n;
	for(int i=1;i<k;++i)L=L/gcd(L,i)*i;
	Mint ans=0;
	for(int i=1;i<=n;++i)
	{
		int r=s%L;
		ans+=Mint(s-r)*k*pw[k-1];
		++f[r];
		s=(ll(s)*x+y)%m;
	}
	for(int i=1;i<=k;++i)
	{
		memcpy(pre,f,sizeof f),memset(f,0,sizeof f);
		for(int j=0;j<L;++j)
		{
			ans+=pre[j]*pw[k-i]*j;
			f[j]+=pre[j]*(n-1);
			f[j-j%i]+=pre[j];
		}
	}
	printf("%d\n",ans.x);
	return 0;
}