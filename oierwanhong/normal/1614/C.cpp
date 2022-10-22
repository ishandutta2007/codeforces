
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
typedef long long ll;
typedef std::vector<int> P;
typedef unsigned un;
ll read()
{
    ll x=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
    return f*x;
}
using std::min;
using std::max;
template<typename T>bool umin(T& a,T t){if(a>t)return a=t,1;return 0;}
template<typename T>bool umax(T& a,T t){if(a<t)return a=t,1;return 0;}

const int MAXN = 200011,mod = 1e9+7,inv2=(mod+1)>>1;
ll Qpow(ll a,ll p)
{
	if(a==2&&p==mod-2)return inv2;
	ll res=1;
	while(p){if(p&1)res=res*a%mod;a=a*a%mod,p>>=1;}
	return res;
}
struct Mint
{
	int x;
	Mint():x(0) {}
	Mint(ll x):x((0<=x&&x<mod?x:(x%mod+mod)%mod)) {}
	void operator+= (Mint you){x+=you.x;if(x>=mod)x-=mod;}
	void operator-= (Mint you){x-=you.x;if(x<0)x+=mod;}
	void operator*= (Mint you){x=ll(x)*you.x%mod;}
	void operator/= (Mint you){x=ll(x)*Qpow(you.x,mod-2)%mod;}
	Mint Inv(){return Qpow(x,mod-2);}
};
Mint operator+ (Mint a,Mint b){int t=a.x+b.x;return t>=mod?t-mod:t;}
Mint operator- (Mint a,Mint b){int t=a.x-b.x;return t<0?t+mod:t;}
Mint operator* (Mint a,Mint b){return ll(a.x)*b.x%mod;}
Mint operator/ (Mint a,Mint b){return ll(a.x)*Qpow(b.x,mod-2)%mod;}

Mint fac[MAXN],Ifac[MAXN],inv[MAXN];
int c[30][MAXN],f[30][MAXN],a[MAXN];
struct one{int l,r,v;}q[MAXN];
void init(int n)
{
	fac[0]=1;
	for(int i=1;i<=n;++i)fac[i]=fac[i-1]*i;
	inv[1]=1;
	for(int i=2;i<=n;++i)inv[i]=(mod-mod/i)*inv[mod%i];
	Ifac[0]=1;
	for(int i=1;i<=n;++i)Ifac[i]=Ifac[i-1]*inv[i];
}
Mint C(int n,int m){return n>=0&&m>=0&&n>=m?fac[n]*Ifac[m]*Ifac[n-m]:0;}
int main()
{
	init(200005);
	int task=read();
	while(task--)
	{
		int n=read(),m=read();
		for(int x=0;x<30;++x)
			for(int i=1;i<=n+1;++i)c[x][i]=f[x][i]=0;
		for(int i=1;i<=m;++i)
		{
			q[i].l=read(),q[i].r=read(),q[i].v=read();
			for(int x=0;x<30;++x)
				if(!(q[i].v&(1<<x)))++c[x][q[i].l],--c[x][q[i].r+1];
		}
		for(int x=0;x<30;++x)
		{
			int sum=0;
			for(int i=1;i<=n;++i)
			{
				f[x][i]=f[x][i-1];
				sum+=c[x][i];
				if(!sum)++f[x][i],a[i]+=1<<x;
			}
		}
		bool fail=0;
		Mint ans=0;
		for(int i=1;i<=m;++i)
		{
			for(int x=0;x<30;++x)
			{
				if(!(q[i].v&(1<<x)))fail|=bool(f[x][q[i].r]-f[x][q[i].l-1]);
				else if(q[i].v&(1<<x))fail|=!(f[x][q[i].r]-f[x][q[i].l-1]);
			}
		}
		for(int x=0;x<30;++x)
		{
			int cnt[2]={0,0};
			for(int i=1;i<=n;++i)++cnt[ f[x][i]>f[x][i-1]];
			Mint rate=Mint(1<<x)*Qpow(2,cnt[0]);
			for(int k=1;k<=cnt[1];k+=2)ans+=C(cnt[1],k)*rate;
		}
		if(fail)puts("-1");
		else printf("%d\n",ans.x);
	}
	return 0;
}