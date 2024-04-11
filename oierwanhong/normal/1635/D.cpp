#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<set>
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

const int MAXN = 800011;
Mint fib[MAXN],sum[MAXN];
int a[MAXN];
std::set<int>S;
int highbit(int x)
{
	int res=0;
	while(x)++res,x>>=1;
	return res;
}
int main()
{
	int n=read(),p=read();
	fib[0]=fib[1]=1,sum[0]=1,sum[1]=2;
	for(int i=2;i<=p;++i)fib[i]=fib[i-1]+fib[i-2],sum[i]=sum[i-1]+fib[i];
	for(int i=1;i<=n;++i)a[i]=read(),S.insert(a[i]);
	Mint ans=0;
	for(int i=1;i<=n;++i)
	{
		int x=a[i];
		bool del=0;
		while(x)
		{
			if((x&1)&&(x>1))x>>=1;
			else if(!(x&3))x>>=2;
			else break;
			if(S.count(x)){del=1;break;}
		}
		if(!del)
		{
			//printf("X=%d remains.\n",a[i]);
			int h=highbit(a[i]);
			if(h<=p)ans+=sum[p-h];
		}
	}
	printf("%d\n",ans.x);
	return 0;
}