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
	Mint operator++ (){return x+1==mod?0:x+1;}
};
Mint operator+ (Mint a,Mint b){int t=a.x+b.x;return t<mod?t:t-mod;}
Mint operator- (Mint a,Mint b){int t=a.x-b.x;return t>=0?t:t+mod;}
Mint operator* (Mint a,Mint b){return ll(a.x)*b.x%mod;}

const int MAXN = 311;
Mint inv[MAXN];
Mint f[MAXN][MAXN][MAXN],pw[MAXN][MAXN];
void init(int n)
{
	inv[1]=1;
	for(int i=2;i<=n;++i)inv[i]=(mod-mod/i)*inv[mod%i];
	for(int i=1;i<=n;++i)
	{
		pw[i][0]=1;
		for(int j=1;j<=n;++j)pw[i][j]=pw[i][j-1]*i;
	}
}
int main()
{
	int n=read()-1,k=read();
	init(300);
	Mint fac=1;
	for(int i=1;i<=n;++i)fac*=i;
	for(int j=1;j<=k;++j)f[1][j][1]=1;
	for(int i=2;i<=n;++i)
	{
		Mint sum=0;
		for(int j=1;j<=k;++j)
		{
			for(int l=2;l<=i;++l)
				f[i][j][l]+=f[i-1][j][l-1]*inv[l]*pw[k-j+1][i-1];
			f[i][j][1]+=sum*pw[k-j+1][i-1];
			for(int l=1;l<=i;++l)
				sum+=f[i-1][j][l];
		}
	}
	Mint ans=0;
	for(int j=1;j<=k;++j)
		for(int l=1;l<=n;++l)ans+=f[n][j][l];
	printf("%d\n",(fac*ans).x);
	return 0;
}