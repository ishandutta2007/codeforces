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

const int MAXN = 265011,mod = 998244353,inv2=(mod+1)>>1;
inline int S(int x){return x<mod?x:x-mod;}
inline int D(int x){return x<0?x+mod:x;}
ll Qpow(ll a,ll p)
{
	ll res=1;
	while(p){if(p&1)res=res*a%mod;a=a*a%mod,p>>=1;}
	return res;
}
ll RT[MAXN],invL[MAXN],fac[MAXN],Ifac[MAXN];
void init()
{
	invL[1]=1;
	for(int i=1;i<(1<<18);i<<=1)
	{
		ll R=Qpow(3,(mod-1)/(i<<1));
		RT[i]=1;
		for(int j=1;j<i;++j)RT[i+j]=RT[i+j-1]*R%mod;
		invL[i<<1]=invL[i]*inv2%mod;
	}
	fac[0]=Ifac[0]=Ifac[1]=1;
	for(int i=1;i<MAXN;++i)fac[i]=fac[i-1]*i%mod;
	for(int i=2;i<MAXN;++i)Ifac[i]=(mod-mod/i)*Ifac[mod%i]%mod;
	for(int i=2;i<MAXN;++i)Ifac[i]=Ifac[i-1]*Ifac[i]%mod;
}
ll C(int n,int m){return n>=0&&m>=0&&n>=m?fac[n]*Ifac[m]%mod*Ifac[n-m]%mod:0;}
int f[MAXN],g[MAXN],res[MAXN], status[MAXN];
void DFT(int* a,int len)
{
	for(int i=0;i<len;++i)
		if(status[i]>i)std::swap(a[i],a[status[i]]);
	for(int cur=1;cur<len;cur<<=1)
		for(int j=0;j<len;j+=cur<<1)
			for(int k=0;k<cur;++k)
			{
				int x=a[j+k],y=RT[cur+k]*a[j+cur+k]%mod;
				a[j+k]=S(x+y),a[j+cur+k]=D(x-y);
			}
}
void IDFT(int* a,int len)
{
	std::reverse(a+1,a+len);
	DFT(a,len);
	for(int i=0;i<len;++i)a[i]=ll(a[i])*invL[len]%mod;
}
void Mul(int n)
{
	int len=1;
	while(len<n)len<<=1;
	for(int i=0;i<len;++i)
		status[i]=(status[i>>1]>>1)|((i&1)?len>>1:0);
	DFT(f,len),DFT(g,len);
	for(int i=0;i<len;++i)res[i]=ll(f[i])*g[i]%mod,f[i]=g[i]=0;
	IDFT(res,len);
}
struct poly:std::vector<int>
{
	poly(){resize(0);}
	poly(int x){resize(x);}
	poly operator* (poly you)
	{
		if(empty()||you.empty())return poly();
		for(int i=0;i<size();++i)f[i]=(*this)[i];
		for(int i=0;i<you.size();++i)g[i]=you[i];
		int n=size()+you.size()-1;
		Mul(n);
		poly t(n);
		for(int i=0;i<n;++i)t[i]=res[i];
		return t;
	}
};
poly Merge(int l,int r)
{
	if(l==r){poly res;res.push_back(l),res.push_back(1);return res;}
	int mid=(l+r)>>1;
	return Merge(l,mid)*Merge(mid+1,r);
}
int main()
{
	init();
	int n=read(),A=read(),B=read();
	if(A==0||B==0){puts("0");return 0;}
	//Ans=S1(n-1,A+B-2)*C(A+B-2,A-1)
	poly res;
	if(n>=2)res=Merge(0,n-2);
	else res.push_back(1);
	printf("%lld\n",A+B-2<res.size()?res[A+B-2]*C(A+B-2,A-1)%mod:0);
	return 0;
}