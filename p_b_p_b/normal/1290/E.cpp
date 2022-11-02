#include<bits/stdc++.h>
clock_t t=clock();
namespace my_std{
    using namespace std;
    #define pii pair<int,int>
    #define fir first
    #define sec second
    #define MP make_pair
    #define rep(i,x,y) for (int i=(x);i<=(y);i++)
    #define drep(i,x,y) for (int i=(x);i>=(y);i--)
    #define go(x) for (int i=head[x];i;i=edge[i].nxt)
    #define templ template<typename T>
    #define sz 303030
    typedef long long ll;
    typedef double db;
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    templ inline T rnd(T l,T r) {return uniform_int_distribution<T>(l,r)(rng);}
    templ inline bool chkmax(T &x,T y){return x<y?x=y,1:0;}
    templ inline bool chkmin(T &x,T y){return x>y?x=y,1:0;}
    templ inline void read(T& t)
    {
        t=0;char f=0,ch=getchar();double d=0.1;
        while(ch>'9'||ch<'0') f|=(ch=='-'),ch=getchar();
        while(ch<='9'&&ch>='0') t=t*10+ch-48,ch=getchar();
        if(ch=='.'){ch=getchar();while(ch<='9'&&ch>='0') t+=d*(ch^48),d*=0.1,ch=getchar();}
        t=(f?-t:t);
    }
    template<typename T,typename... Args>inline void read(T& t,Args&... args){read(t); read(args...);}
    char __sr[1<<21],__z[20];int __C=-1,__zz=0;
    inline void Ot(){fwrite(__sr,1,__C+1,stdout),__C=-1;}
    inline void print(register int x)
    {
        if(__C>1<<20)Ot();if(x<0)__sr[++__C]='-',x=-x;
        while(__z[++__zz]=x%10+48,x/=10);
        while(__sr[++__C]=__z[__zz],--__zz);__sr[++__C]='\n';
    }
    void file()
    {
        #ifdef NTFOrz
        freopen("a.in","r",stdin);
        #endif
    }
    inline void chktime()
    {
        #ifndef ONLINE_JUDGE
        cout<<(clock()-t)/1000.0<<'\n';
        #endif
    }
    #ifdef mod
    ll ksm(ll x,int y){ll ret=1;for (;y;y>>=1,x=x*x%mod) if (y&1) ret=ret*x%mod;return ret;}
    ll inv(ll x){return ksm(x,mod-2);}
    #else
    ll ksm(ll x,int y){ll ret=1;for (;y;y>>=1,x=x*x) if (y&1) ret=ret*x;return ret;}
    #endif
//	inline ll mul(ll a,ll b){ll d=(ll)(a*(double)b/mod+0.5);ll ret=a*b-d*mod;if (ret<0) ret+=mod;return ret;}
}
using namespace my_std;

int n;
int a[sz];
ll ans[sz];
int p[sz];

int fp[sz];
void add(int x){for (;x<=n;++fp[x],x+=(x&(-x)));}
int query(int x){int ret=0;for (;x;ret+=fp[x],x-=(x&(-x)));return ret;}

ll cur=0;

#define ls k<<1
#define rs k<<1|1
#define lson ls,l,mid
#define rson rs,mid+1,r

namespace seg // how many times each fp is counted
{
	int cnt[sz<<2];
	void modify(int k,int l,int r,int x,int w)
	{
		if (!x) return;
		cnt[k]+=w;
		if (l==r) return cur+=1ll*query(x)*w,void();
		int mid=(l+r)>>1;
		if (x<=mid) modify(lson,x,w);
		else modify(rson,x,w);
	}
	int query(int k,int l,int r,int x,int y)
	{
		if (x<=l&&r<=y) return cnt[k];
		int mid=(l+r)>>1,ret=0;
		if (x<=mid) ret+=query(lson,x,y);
		if (y>mid) ret+=query(rson,x,y);
		return ret;
	}
}

int mx[sz<<2],cm[sz<<2],mxx[sz<<2],tag[sz<<2];
void pushup(int k)
{
	mx[k]=max(mx[ls],mx[rs]);
	if (mx[ls]!=mx[rs]) mxx[k]=max({mxx[ls],mxx[rs],mx[ls]+mx[rs]-mx[k]}),cm[k]=mx[ls]>mx[rs]?cm[ls]:cm[rs];
	else mxx[k]=max(mxx[ls],mxx[rs]),cm[k]=cm[ls]+cm[rs];
}
void Tag(int k,int w,int ww,int flg)
{
	if (w>=mx[k]) return;
	if (w>mxx[k])
	{
		tag[k]=w;
		chkmin(mx[k],ww);
		if (flg) seg::modify(1,1,n,mx[k],-cm[k]);
		mx[k]=w;
		if (flg) seg::modify(1,1,n,mx[k],cm[k]);
		return;
	}
	chkmin(ww,tag[k]);
	Tag(ls,w,ww,flg),Tag(rs,w,ww,flg);tag[k]=1e9;
	pushup(k);
}
void pushdown(int k){if (tag[k]>n) return;Tag(ls,tag[k],1e9,0),Tag(rs,tag[k],1e9,0),tag[k]=1e9;}
void modify(int k,int l,int r,int x,int w)
{
	if (l==r) return seg::modify(1,1,n,mx[k],-1),mx[k]=w,cm[k]=1,seg::modify(1,1,n,mx[k],1);
	pushdown(k);
	int mid=(l+r)>>1;
	if (x<=mid) modify(lson,x,w);
	else modify(rson,x,w);
	pushup(k);
}
void change(int k,int l,int r,int x,int y,int w)
{
	if (x<=l&&r<=y) return Tag(k,w,1e9,1);
	int mid=(l+r)>>1;
	pushdown(k);
	if (x<=mid) change(lson,x,y,w);
	if (y>mid) change(rson,x,y,w);
	pushup(k);
}

void work()
{
	rep(i,1,n) p[a[i]]=i;
	memset(tag,0x3f,sizeof(tag));
	rep(i,1,n) modify(1,1,n,i,0);
	memset(fp,0,sizeof(fp));
	memset(seg::cnt,0,sizeof(seg::cnt));
	cur=0;
	set<int>s;
	rep(i,1,n)
	{
		s.insert(p[i]);auto it=s.find(p[i]);
		if (it!=s.begin()&&*(s.begin())+1<p[i]) change(1,1,n,*(s.begin())+1,p[i]-1,p[i]-1);
		if (next(it)!=s.end()) modify(1,1,n,*next(it),n);
		if (next(it)!=s.end()&&it!=s.begin()&&a[*prev(it)]<a[*next(it)]) seg::modify(1,1,n,*next(it)-1,-1);
		if (it==s.begin()) seg::modify(1,1,n,p[i]-1,-1),modify(1,1,n,p[i],n);
		int c=seg::query(1,1,n,p[i],n);cur+=c;assert(seg::cnt[1]>=0);assert(c>=0);
		add(p[i]);
		ans[i]+=cur;
	}
}

int main()
{
    file();
	read(n);
	rep(i,1,n) read(a[i]);
	work();
	reverse(a+1,a+n+1);
	work();
	rep(i,1,n) printf("%lld\n",ans[i]-i);
	return 0;
}