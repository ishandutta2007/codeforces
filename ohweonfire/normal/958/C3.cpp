//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define bged(v) (v).begin(),(v).end()
#define foreach(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
typedef long long ll;
const int Imx=2147483647;
const ll Lbig=2e18;
const int mod=1e9+7;
//My i/o stream
struct fastio
{
	char s[100000];
	int it,len;
	fastio(){it=len=0;}
	inline char get()
	{
		if(it<len)return s[it++];it=0;
		len=fread(s,1,100000,stdin);
		if(len==0)return EOF;else return s[it++];
	}
	bool notend()
	{
		char c=get();
		while(c==' '||c=='\n')c=get();
		if(it>0)it--;
		return c!=EOF;
	}
}_buff;
#define geti(x) x=getnum()
#define getii(x,y) geti(x),geti(y)
#define getiii(x,y,z) getii(x,y),geti(z)
#define puti(x) putnum(x),putchar(' ')
#define putii(x,y) puti(x),puti(y)
#define putiii(x,y,z) putii(x,y),puti(z)
#define putsi(x) putnum(x),putchar('\n')
#define putsii(x,y) puti(x),putsi(y)
#define putsiii(x,y,z) putii(x,y),putsi(z)
inline ll getnum()
{
	ll r=0;bool ng=0;char c;c=_buff.get();
	while(c!='-'&&(c<'0'||c>'9'))c=_buff.get();
	if(c=='-')ng=1,c=_buff.get();
	while(c>='0'&&c<='9')r=r*10+c-'0',c=_buff.get();
	return ng?-r:r;
}
template<class T> inline void putnum(T x)
{
	if(x<0)putchar('-'),x=-x;
	register short a[20]={},sz=0;
	while(x)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1;i>=0;i--)putchar('0'+a[i]);
}
inline char getreal(){char c=_buff.get();while(c<=32)c=_buff.get();return c;}
ll qpow(ll x,ll k){return k==0?1:1ll*qpow(1ll*x*x%mod,k>>1)*(k&1?x:1)%mod;}
int n,K,p;
int a[500111];
int pre[500111];
int dp[500111],ndp[500111];
int tab[111],tab2[111];

void upd(int &x,int v){x=min(x,v);}
void addtab(int x,int v)
{
	if(v>233)return;
	for(int i=x;i<p;i++)
	{
		if(tab[i]<=v)return;
		upd(tab[i],v);
	}
}
void addtab2(int x,int v)
{
	if(v>233)return;
	for(int i=x;i>=0;i--)
	{
		if(tab2[i]<=v)return;
		upd(tab2[i],v);
	}
}
int main()
{
	getiii(n,K,p);
	for(int i=1;i<=n;i++)
	{
		geti(a[i]);
		a[i]=(a[i]%p+p)%p;
		pre[i]=pre[i-1]+a[i];
		pre[i]=(pre[i]%p+p)%p;
	}
	memset(dp,100,sizeof(dp));
	dp[0]=0;
	for(int i=1;i<=K;i++)
	{
		memset(ndp,100,sizeof(ndp));
		memset(tab,100,sizeof(tab));
		memset(tab2,100,sizeof(tab));
		addtab(0,dp[0]);
		addtab2(0,dp[0]);
		for(int j=1;j<=n;j++)
		{
			ndp[j]=min(tab[pre[j]],tab2[pre[j]+1]+1);
			addtab(pre[j],dp[j]);
			addtab2(pre[j],dp[j]);
		}
		swap(dp,ndp);
	}
	cout<<dp[n]*p+pre[n]<<endl;
	return 0;
}