#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<cmath>
using namespace std;
typedef unsigned long long ll;
/*int modd=67;
const int table[67]={0,0,1,39,2,15,40,23,3,12,16,59,41,19,24,54,4,0,13,10,17,62,60,28,42,30,20,51,25,
44,55,47,5,32,0,38,14,22,11,58,18,53,63,9,61,27,29,50,43,46,31,37,21,57,52,8,26,
49,45,36,56,7,48,35,6,34,33};
inline int getans(ll x)
{
	return table[x%modd];
}*/
ll F(ll x,ll y,int k=5);
ll FF(ll x,ll y);
ll g[105][105];
ll G(ll x,ll y)
{
	if(!x||!y) return 1ull<<(x+y);
	if(g[x][y]) return g[x][y];
	ll ans=1;
	for(int i=0;(1ull<<i)<=(x^y);i++)
		if((x^y)&(1<<i)) ans<<=(1<<i);
	for(int i=0;(1ull<<i)<=(x&y);i++)
		if((x&y)&(1<<i)) ans=FF(ans,3ull<<((1<<i)-1));
//	printf("x=%d,y=%d,ans=%d\n",x,y,ans);
	return g[x][y]=ans;
}
//int cct=0;
ll f[305][305];
ll FF(ll x,ll y)
{
	if(x<=1||y<=1) return x*y;
//	if(x<=300&&y<=300&&f[x][y]) return f[x][y];
	ll ans=0;
	for(int i=0;i<32;i++)
		if(x&(1ull<<i))
			for(int j=0;j<32;j++)
				if(y&(1ull<<j))
					ans^=G(i,j);
	if(x<=300&&y<=300)
	{
		f[x][y]=ans;
	///	if(x==2&&y==8) printf("f=%llu\n",f[x][y]);
	}
//	if(x==2&&y==8) printf("ans=%llu\n",ans);
	return ans;
}
ll F(ll x,ll y,int k)
{
//	return FF(x,y);
	if(x<=1||y<=1) return x*y;
	if(x<256&&y<256)
		return f[x][y];
	int u=(1<<k);
	ll v=((1ull<<u)-1);
//	if((x>>u)==0&&(y>>u)==0) return FF(x,y);
	ll a=F((x>>u),(y>>u),k-1),b=F(x&v,y&v,k-1);
	ll c=F((x>>u)^(x&v),(y>>u)^(y&v),k-1)^a^b;
	ll ans=b;
	for(int i=0;i<u;i++)
		if(c&(1ull<<i))
			ans^=G(u,i);
	for(int i=0;i<u;i++)
		if(a&(1ull<<i))
			ans^=G(u,i)^G(u-1,i);
	return ans;
}
ll nfpow(ll x,ll y)
{
	ll ans=1;
	while(y)
	{
		if(y&1) ans=F(ans,x);
		x=F(x,x);
		y/=2;
	}
	return ans;
}
int fpow(int x,int y,int mod)
{
	int ans=1;
	while(y)
	{
		if(y&1) ans=1ll*ans*x%mod;
		x=1ll*x*x%mod;
		y/=2;
	}
	return ans;
}
map<ll,int> mp;
int t,prime[7]={3,5,17,257,641,65537,6700417},pt=7;
ll mod=-1ull,c[7],d[7];
ll getadd(ll a,ll b)
{
	ll ans=a+b;
	if(ans<a||ans<b) return (ans+1)%mod;
	return ans%mod;
}
ll getmul(ll x,ll y)
{
	ll ans=0;
	while(y)
	{
		if(y&1) ans=getadd(ans,x);
		x=getadd(x,x);
		y/=2;
	}
	return ans;
}
ll st[100005];
int solve(ll a,ll b,int p)
{
	mp.clear();
	int sp=sqrt(p)+1;
	ll q=nfpow(a,sp),mul=q;
//	printf("a=%llu,b=%llu,q=%llu,p=%d\n",a,b,q,p);
	for(int i=1;(i-1)*sp<p;i++)
	{
		if(!mp.count(mul)) mp[mul]=i*sp;
	//	printf("i=%d,%d,mul=%llu\n",i,i*sp,mul);
		mul=F(mul,q);
	}
	mul=b;
	for(int i=0;i<sp;i++)
	{
		if(mp.count(mul)) return (mp[mul]-i)%p;
		mul=F(mul,a);
	}
	return -1;
}
ll a,b;
int main()
{
//	freopen("CF1310F.in","r",stdin);
//	freopen("CF1310F.out","w",stdout);
	for(int i=0;i<256;i++)
		for(int j=0;j<256;j++)
			FF(i,j);
/*	for(int i=0;i<16;i++)
	{
		for(int j=0;j<16;j++)
			printf("%llu ",FF(i,j));
		printf("\n");
	}*/
	for(int i=0;i<7;i++)
	{
		c[i]=(-1ull)/prime[i];
		d[i]=fpow(c[i]%prime[i],prime[i]-2,prime[i]);
	}
	scanf("%d",&t);
	while(t--)
	{
		scanf("%llu%llu",&a,&b);
		ll ans=0;
		int fl=1;
		for(int i=0;i<7;i++)
		{
			int q=solve(nfpow(a,c[i]),nfpow(b,c[i]),prime[i]);
			if(q==-1)
			{
				fl=0;
				break;
			}
	//		printf("i=%d,p=%d,q=%d\n",i,prime[i],q);
			ans=getadd(ans,getmul(getmul(c[i],d[i]),q));
		}
		if(fl)
		{
			if(nfpow(a,ans)!=b)
			{
				printf("error\n");
			}
			printf("%llu\n",ans);
		}
		else printf("-1\n");
	}
	return 0;
}