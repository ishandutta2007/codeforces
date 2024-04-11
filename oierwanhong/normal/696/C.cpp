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
const int mod = 1e9+7,inv2=(mod+1)>>1;
ll Qpow(ll a,ll p)
{
	ll res=1;
	while(p){if(p&1)res=res*a%mod;a=a*a%mod,p>>=1;}
	return res;
}
int tp[4];
struct matrix
{
	int a[4];
	matrix(){memset(a,0,sizeof a);}
	matrix(int b[4]){memcpy(a,b,sizeof a);}
	matrix operator* (matrix you)
	{
		tp[0]=(ll(a[0])*you.a[0]+ll(a[1])*you.a[2])%mod;
		tp[1]=(ll(a[0])*you.a[1]+ll(a[1])*you.a[3])%mod;
		tp[2]=(ll(a[2])*you.a[0]+ll(a[3])*you.a[2])%mod;
		tp[3]=(ll(a[2])*you.a[1]+ll(a[3])*you.a[3])%mod;
		return matrix(tp);
	}
};
matrix Qpow(matrix a,ll p)
{
	matrix res;
	res.a[0]=res.a[3]=1;
	while(p)
	{
		if(p&1)res=res*a;
		a=a*a,p>>=1;
	}
	return res;
}
int main()
{
	int n=read(),all=1;
	matrix res,A;
	A.a[1]=1,A.a[2]=A.a[3]=inv2;
	int prod=1;
	for(int i=1;i<=n;++i)
	{
		ll x=read()%(mod-1);
		prod=ll(prod)*x%(mod-1);
	}
	res=Qpow(A,prod);
	all=Qpow(2,prod);
	int f1=res.a[0];
	printf("%lld/%lld\n",ll(f1)*all%mod*inv2%mod,ll(all)*inv2%mod);
	return 0;
}