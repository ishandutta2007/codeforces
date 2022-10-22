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
const int mod = 1e9+7;
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
	Mint operator++ (){return x+1==mod?0:x+1;}
};
Mint operator+ (Mint a,Mint b){int t=a.x+b.x;return t<mod?t:t-mod;}
Mint operator- (Mint a,Mint b){int t=a.x-b.x;return t>=0?t:t+mod;}
Mint operator* (Mint a,Mint b){return ll(a.x)*b.x%mod;}

const int MAXN = 2000011;
Mint fac[MAXN],Ifac[MAXN];
void init(int n)
{
	fac[0]=1;
	for(int i=1;i<=n;++i)fac[i]=fac[i-1]*i;
	Ifac[n]=Qpow(fac[n].x,mod-2);
	for(int i=n-1;i>=0;--i)Ifac[i]=Ifac[i+1]*(i+1);
}
Mint C(int n,int m){return n>=0&&m>=0&&n>=m?fac[n]*Ifac[m]*Ifac[n-m]:0;}
int main()
{
	init(2000000);
	int task=read();
	while(task--)
	{
		int n=read(),m=n-read();
		Mint k=read();
		if(m==0)
		{
			printf("%d\n",(n*k).x);
			continue;
		}
		Mint res=0,mul=1;
		for(int i=1;i<n;++i)
		{
			//printf("i=%d,C(%d,%d)\n",i,n-i-1,m-1);
			res+=C(n-i-1,m-1)*i*mul;
			mul*=2;
		}
		printf("%d\n",(res*Qpow(mul.x,mod-2)*k).x);
	}
	return 0;
}