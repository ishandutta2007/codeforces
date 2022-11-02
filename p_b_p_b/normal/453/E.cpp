#include<bits/stdc++.h>
clock_t __t=clock();
namespace my_std{
    using namespace std;
    #define pll pair<ll,ll>
    #define fir first
    #define sec second
    #define MP make_pair
    #define rep(i,x,y) for (int i=(x);i<=(y);i++)
    #define drep(i,x,y) for (int i=(x);i>=(y);i--)
    #define go(x) for (int i=head[x];i;i=edge[i].nxt)
    #define templ template<typename T>
    #define MX 100000
    #define sz 101001
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
        cout<<(clock()-__t)/1000.0<<'\n';
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
int sss[sz],M[sz],R[sz];
int vis[sz];

// mr
struct hh
{
	ll m,r;
	hh(ll M=0,ll R=0){m=M,r=R;}
	const hh operator + (const hh &x) const {return hh(m+x.m,r+x.r);}
};
namespace SegmentTree
{
	#define Tree sz*20
	hh sum[Tree];
	int ls[Tree],rs[Tree],cnt;
	int root[sz];
	#define lson ls[k],l,mid
	#define rson rs[k],mid+1,r
	void insert(int &k,int l,int r,int x,hh w,int pre)
	{
		k=++cnt;ls[k]=ls[pre],rs[k]=rs[pre],sum[k]=sum[pre]+w;
		if (l==r) return;
		int mid=(l+r)>>1;
		if (x<=mid) insert(lson,x,w,ls[pre]);
		else insert(rson,x,w,rs[pre]);
	}
	hh query(int k,int l,int r,int x,int y)
	{
		if (!k) return hh();
		if (x<=l&&r<=y) return sum[k];
		int mid=(l+r)>>1;hh ret;
		if (x<=mid) ret=ret+query(lson,x,y);
		if (y>mid) ret=ret+query(rson,x,y);
		return ret;
	}
} 
using namespace SegmentTree;

struct hhh{int l,r,t;hhh(int L=0,int R=0,int T=0){l=L,r=R,t=T;}const bool operator < (const hhh &x) const {return l<x.l;}};
set<hhh>s;
set<hhh>::iterator split(int pos)
{
	auto it=s.upper_bound(hhh(pos,0,0));--it;
	if ((*it).r<pos) return s.end();
	hhh x=*it,y=*it;s.erase(it);
	x.r=pos-1,y.l=pos;
	if (x.l<=x.r) s.insert(x);
	return s.insert(y).fir;
}

int main() // WRONG!!!
{
    file();
	read(n);
	rep(i,1,n) read(sss[i],M[i],R[i]);
	rep(i,1,n) 
		if (R[i]) insert(root[i],1,MX,(M[i]-1)/R[i]+1,hh(M[i],R[i]),root[i-1]);
		else root[i]=root[i-1];
	rep(i,1,n) s.insert(hhh(i,i,0));
	int Q;read(Q);
	rep(_,1,Q)
	{
		ll tt;int l,r;
		read(tt,l,r);
		auto it2=split(r+1),it1=split(l);
		ll ans=0;
		for (auto it=it1;it!=it2;s.erase(it++))
		{
			int l=(*it).l,r=(*it).r,T=(*it).t;
			if (l==r&&!vis[l]) ans+=min((ll)M[l],tt*R[l]+sss[l]),vis[l]=1;
			else
			{
				T=tt-T;
				ans+=query(root[r],1,MX,1,T).m-query(root[l-1],1,MX,1,T).m;
				ans+=(query(root[r],1,MX,T+1,MX).r-query(root[l-1],1,MX,T+1,MX).r)*T;
			}
		}
		printf("%I64d\n",ans);
		s.insert(hhh(l,r,tt));
	}
	return 0;
}