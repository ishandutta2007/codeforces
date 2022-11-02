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
	#define sz 404040
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
		#ifndef ONLINE_JUDGE
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
char s[sz];

namespace SGT
{
	#define Tree sz*20
	int ls[Tree],rs[Tree],cnt;
	#define lson ls[k],l,mid
	#define rson rs[k],mid+1,r
	void insert(int &k,int l,int r,int x)
	{
		if (!k) k=++cnt;
		if (l==r) return;
		int mid=(l+r)>>1;
		if (x<=mid) insert(lson,x);
		else insert(rson,x);
	}
	int merge(int k1,int k2,int l,int r)
	{
		if (!k1||!k2) return k1+k2;
		int k=++cnt;
		if (l==r) return k;
		int mid=(l+r)>>1;
		ls[k]=merge(ls[k1],ls[k2],l,mid);
		rs[k]=merge(rs[k1],rs[k2],mid+1,r);
		return k;
	}
	int query(int k,int l,int r,int x,int y)
	{
		if (!k) return 0;
		if (x<=l&&r<=y) return 1;
		int mid=(l+r)>>1;
		if (x<=mid&&query(lson,x,y)) return 1;
		if (y>mid&&query(rson,x,y)) return 1;
		return 0;
	}
}

namespace SAM
{
	struct hh{int ch[30],link,len;}a[sz];
	int pos[sz],root[sz];
	int lst=1,cnt=1;
	void insert(int c,int id)
	{
		int cur=++cnt,p=lst;lst=cur;
		a[cur].len=a[p].len+1;
		pos[cur]=id;SGT::insert(root[cur],1,n,id);
		while (p&&!a[p].ch[c]) a[p].ch[c]=cur,p=a[p].link;
		if (!p) return (void)(a[cur].link=1);
		int q=a[p].ch[c];
		if (a[q].len==a[p].len+1) return (void)(a[cur].link=q);
		int t=++cnt;
		a[t]=a[q];a[t].len=a[p].len+1;a[cur].link=a[q].link=t;
		while (p&&a[p].ch[c]==q) a[p].ch[c]=t,p=a[p].link;
	}
	int cc[sz],id[sz];
	void init()
	{
		rep(i,2,cnt) ++cc[a[i].len];
		rep(i,1,n) cc[i]+=cc[i-1];
		drep(i,cnt,2) id[cc[a[i].len]--]=i;
		drep(i,cnt-1,1)
		{
			int x=id[i],fa=a[x].link;
			pos[fa]=pos[x];
			root[fa]=SGT::merge(root[fa],root[x],1,n);
		}
	}
	int dp[sz],top[sz],ans;
	void work()
	{
		top[1]=1;
		rep(i,1,cnt-1)
		{
			int x=id[i],fa=top[a[x].link];
			if (fa==1||SGT::query(root[fa],1,n,pos[x]-a[x].len+a[fa].len,pos[x]-1)) top[x]=x,chkmax(ans,dp[x]=dp[fa]+1);
			else top[x]=fa;
		}
		cout<<ans;
	}
}

int main()
{
	file();
	read(n);
	cin>>(s+1);
	rep(i,1,n) SAM::insert(s[i]-'a'+1,i);
	SAM::init();SAM::work();
	return 0;
}