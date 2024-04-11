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
inline char getreal(){char c=_buff.get();while(c==' '||c=='\n')c=_buff.get();return c;}
int n,m;
ll a[100111];
pair<ll,ll> b[100111]; 
pair<ll,int> pp[100111];
int yuan[100111];

struct SGT
{
	struct node
	{
		ll dlt;
		ll mn;
		node(){dlt=mn=0;}
	}a[400111];
	#define ls p<<1
	#define rs p<<1|1
	void pushdown(int p)
	{
		if(a[p].dlt!=0)
		{
			a[ls].dlt+=a[p].dlt;
			a[rs].dlt+=a[p].dlt;
			a[ls].mn+=a[p].dlt;
			a[rs].mn+=a[p].dlt;
			a[p].dlt=0;
		}
	}
	void update(int p)
	{
		a[p].mn=min(a[ls].mn,a[rs].mn);
	}
	void add(int x,int y,ll v,int l,int r,int p=1)
	{
		if(x<=l&&r<=y)
		{
			a[p].mn+=v;
			a[p].dlt+=v;
			return;
		}
		pushdown(p);
		int m=l+r>>1;
		if(x<=m)add(x,y,v,l,m,ls);
		if(m<y)add(x,y,v,m+1,r,rs);
		update(p);
	}
	ll query(int x,int y,int l,int r,int p=1)
	{
		if(x<=l&&r<=y)return a[p].mn;
		pushdown(p);
		int m=l+r>>1;
		if(x<=m&&m<y)return min(query(x,y,l,m,ls),query(x,y,m+1,r,rs));
		else if(x<=m)return query(x,y,l,m,ls);
		else return query(x,y,m+1,r,rs);
	}
}sgt;
int main()
{
	getii(n,m);
	for(int i=1;i<=n;i++)geti(a[i]),sgt.add(i,n,a[i],1,n);
	for(int i=1;i<=m;i++)geti(b[i].FF);
	for(int i=1;i<=m;i++)geti(b[i].SS);
	sort(b+1,b+m+1);
	int it=1;
	ll mx=0;
	for(int i=n;i>=1;i--)
	{
		mx=max(mx,a[i]);
		while(it<=m&&b[it].FF<=mx)
		{
			yuan[it]=i;
			it++;
		}
	}
	for(int i=1;i<=m;i++)pp[i]=MP(b[i].SS,-yuan[i]);
	sort(pp+1,pp+m+1);
	int ans=0;
	for(int i=1;i<=m;i++)
	{
		int x=-pp[i].SS,w=pp[i].FF;
		if(x==0)continue;
		ll cur=sgt.query(x,n,1,n);
		if(cur>=w)
		{
			ans++;
			sgt.add(x,n,-w,1,n);
		}
	}
	cout<<ans<<endl;
	return 0;
}