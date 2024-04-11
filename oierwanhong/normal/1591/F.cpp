#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
typedef long long ll;
typedef unsigned un;
typedef unsigned long long ull;
typedef std::pair<int,int> pii;
ll read()
{
	ll x=0,f=1;int c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	return f*x;
}
ll min(ll a,ll b){return a<b?a:b;}
ll max(ll a,ll b){return a>b?a:b;}
template<typename T> bool umin(T& a,T t){if(a>t)return a=t,1;return 0;}
template<typename T> bool umax(T& a,T t){if(a<t)return a=t,1;return 0;}
/**********/
const int MAXN = 525011,mod = 998244353,inv2=(mod+1)>>1;
const int INF = 1e9+233;
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
	Mint operator- (){return x?mod-x:0;}
	Mint Inv(){return Qpow(x,mod-2);}
};
Mint operator+ (Mint a,Mint b){int t=a.x+b.x;return t>=mod?t-mod:t;}
Mint operator- (Mint a,Mint b){int t=a.x-b.x;return t<0?t+mod:t;}
Mint operator* (Mint a,Mint b){return ll(a.x)*b.x%mod;}
Mint operator/ (Mint a,Mint b){return ll(a.x)*Qpow(b.x,mod-2)%mod;}

Mint f[MAXN],prs[MAXN];
int s[MAXN],a[MAXN];
Mint sgn(int x){return x&1?-1:1;}
int main()
{
	int n=read(),top=0;
	for(int i=1;i<=n;++i)a[i]=read();
	f[0]=prs[0]=1;
	Mint sum=0;
	for(int i=1;i<=n;++i)
	{
		while(top&&a[s[top]]>a[i])
		{
			if(top==1)sum-=prs[s[top]-1]*(a[s[top]]-a[i]);
			else sum-=(prs[s[top]-1]-prs[s[top-1]-1])*(a[s[top]]-a[i]);
			--top;
		}
		s[++top]=i,sum+=f[i-1]*a[i];
		f[i]=-sum,prs[i]=prs[i-1]+f[i];
	}
	printf("%d\n",(f[n]*sgn(n)).x);
	return 0;
}