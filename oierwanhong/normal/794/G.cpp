#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<set>
typedef long long ll;
typedef std::vector<int> P;
typedef std::pair<int,int> pii;
ll read(){ll x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();return f*x;}
using std::max;
using std::min;
template <typename T> bool umax(T& a,T t){if(t>a)return a=t,1;return 0;}
template <typename T> bool umin(T& a,T t){if(t<a)return a=t,1;return 0;}
/**********/
const int MAXN = 600011, mod = 1e9+7;
ll Qpow(ll a,ll p)
{
	ll res=1;
	while(p){if(p&1)res=res*a%mod;a=a*a%mod,p>>=1;}
	return res;
}
char s[MAXN],t[MAXN];
ll pw2[MAXN],fac[MAXN],inv[MAXN],f[MAXN];
int mu[MAXN],pri[MAXN];
bool vis[MAXN];
ll C(int n,int m){return n>=0&&m>=0&&n>=m?fac[n]*inv[m]%mod*inv[n-m]%mod:0;}
void init(int n)
{
	fac[0]=inv[0]=1,pw2[0]=1;
	for(int i=1;i<=n;++i)fac[i]=fac[i-1]*i%mod,pw2[i]=pw2[i-1]*2%mod;
	inv[n]=Qpow(fac[n],mod-2);
	for(int i=n-1;i;--i)inv[i]=inv[i+1]*(i+1)%mod;
	
	mu[1]=1;
	int cnt=0;
	for(int i=2;i<=n;++i)
	{
		if(!vis[i])pri[++cnt]=i,mu[i]=-1;
		for(int j=1;j<=cnt&&i*pri[j]<=n;++j)
		{
			vis[i*pri[j]]=1;
			if(i%pri[j]==0)break;
			mu[i*pri[j]]=-mu[i];
		}
	}
	for(int i=1;i<=n;++i)
	{
		int p=pw2[i];
		for(int j=1;i*j<=n;++j)
			f[i*j]+=p*mu[j];
	}
	for(int i=1;i<=n;++i)f[i]%=mod;
}
int gcd(int a,int b){return b?gcd(b,a%b):a;}
ll cal(ll n,ll a,ll b)
{
	if(a*b==0)return a==0&&b==0?f[n]:0;
	if(a*b>0)return 0;
	if(a<0)a=-a;
	else b=-b;
	return (pw2[ll(n)*gcd(a,b)/max(a,b)+1]-2+mod)%mod;
}
int main()
{
	init(MAXN-1);
	scanf("%s%s",s+1,t+1);
	int n=read(),ls=strlen(s+1),lt=strlen(t+1);
	for(int i=1;i<=n;++i)f[i]=(f[i-1]+f[i]*(n/i)%mod*(n/i))%mod;
	ll ans=0;
	int Qn=0,Qm=0,a=0,b=0;
	for(int i=1;i<=ls;++i)Qn+=(s[i]=='?'),a+=(s[i]=='A'),b+=(s[i]=='B');
	for(int i=1;i<=lt;++i)Qm+=(t[i]=='?'),a-=(t[i]=='A'),b-=(t[i]=='B');
	for(int k=-Qm;k<=Qn;++k)ans=(ans+C(Qn+Qm,Qm+k)*cal(n,a+k,b+Qn-Qm-k))%mod;
	if(ls==lt)
	{
		int tp=1;
		for(int i=1;i<=ls;++i)
			if(s[i]=='?'||t[i]=='?')
			{
				if(s[i]==t[i])tp=(tp*2)%mod;
			}
			else if(s[i]!=t[i])tp=0;
		ans=(ans+tp*((pw2[n+1]-2)*(pw2[n+1]-2)%mod- cal(n,0,0)))%mod;
	}
	printf("%lld\n",(ans+mod)%mod);
	return 0;
}