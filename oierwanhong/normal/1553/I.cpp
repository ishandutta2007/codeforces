#include<cstdio>
#include<vector>
#include<algorithm>
typedef long long ll;
ll read()
{
	ll x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	return f*x;
}

const int MAXN = 265011, mod = 998244353,inv2=(mod+1)>>1;
ll Qpow(ll a,ll p)
{
	ll res=1;
	while(p){if(p&1)res=res*a%mod;a=a*a%mod,p>>=1;}
	return res;
}
void Add(int& a,int t){a+=t;if(a>=mod)a-=mod;}
inline int S(int x){return x<mod?x:x-mod;}
inline int D(int x){return x<0?x+mod:x;}
namespace NTT
{
	ll RT[MAXN],invL[MAXN];
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
	}
	int f[MAXN],g[MAXN],status[MAXN];
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
		for(int i=0;i<len;++i)a[i]=a[i]*invL[len]%mod;
	}
	void Mul(int n)
	{
		int len=1;
		while(len<n)len<<=1;
		for(int i=0;i<len;++i)
			status[i]=(status[i>>1]>>1)|((i&1)?len>>1:0);
		DFT(f,len),DFT(g,len);
		for(int i=0;i<len;++i)f[i]=ll(f[i])*g[i]%mod,g[i]=0;
		IDFT(f,len);
	}
}

struct poly:std::vector<int>
{
	poly(){clear();}
	poly(int x){resize(x);}
	poly operator+ (poly you)
	{
		poly res=*this;
		if(res.size()<you.size())res.resize(you.size());
		for(int i=0;i<you.size();++i)Add(res[i],you[i]);
		return res;
	}
	poly operator* (poly you)
	{
		if(empty()||you.empty())return poly();
		int n=size()+you.size()-1;
		poly res(n);
		for(int i=0;i<size();++i)NTT::f[i]=(*this)[i];
		for(int i=0;i<you.size();++i)NTT::g[i]=you[i];
		NTT::Mul(n);
		for(int i=0;i<n;++i)res[i]=NTT::f[i],NTT::f[i]=0;
		return res;
	}
};
struct Matrix
{
	poly a[4];
	Matrix(){}
	Matrix(poly* b){a[0]=b[0],a[1]=b[1],a[2]=b[2],a[3]=b[3];}
	Matrix operator* (Matrix you)
	{
		poly tp[4];
		tp[0]=(a[0]*you.a[0]+a[1]*you.a[2]);
		tp[1]=(a[0]*you.a[1]+a[1]*you.a[3]);
		tp[2]=(a[2]*you.a[0]+a[3]*you.a[2]);
		tp[3]=(a[2]*you.a[1]+a[3]*you.a[3]);
		return Matrix(tp);
	}
}mat[MAXN];
int a[MAXN];
ll fac[MAXN];
Matrix merge(int l,int r)
{
	if(l==r)return mat[l];
	int mid=(l+r)>>1;
	return merge(l,mid)*merge(mid+1,r);
}
int main()
{
	NTT::init();
	int n=read();
	fac[0]=1;
	for(int i=1;i<=n;++i)fac[i]=fac[i-1]*i%mod;
	for(int i=1;i<=n;++i)a[i]=read();
	int cur=0;
	for(int i=1,j;i<=n;i=j)
	{
		j=i+1;
		while(j-i+1<=a[i]&&a[j]==a[i])++j;
		if(j-i<a[i]){puts("0");return 0;}
		++cur;
		if(cur==1)
		{
			if(a[i]==1)mat[1].a[0].push_back(0),mat[1].a[0].push_back(1);
			else mat[1].a[1].push_back(0),mat[1].a[1].push_back(2);
		}
		else
		{
			if(a[i]==1)
			{
				mat[cur].a[0].push_back(0),mat[cur].a[0].push_back(1);
				mat[cur].a[1].push_back(2);
				mat[cur].a[2]=mat[cur].a[0];
				mat[cur].a[3].push_back(1);
			}
			else
			{
				mat[cur].a[1].push_back(2),mat[cur].a[1].push_back(2);
				mat[cur].a[3].push_back(1),mat[cur].a[3].push_back(2);
			}
		}
	}
	if(cur>1)mat[1]=mat[1]*merge(2,cur);
	poly res=(mat[1].a[0]+mat[1].a[1]);
	res.resize(cur+1);
	ll ans=0;
	for(int i=1;i<=cur;++i)
	{
		if((cur-i)&1)ans=(ans-fac[i]*(res[i]))%mod;
		else ans=(ans+fac[i]*(res[i]))%mod;
	}
	printf("%lld\n",(ans+mod)%mod);
	return 0;
}