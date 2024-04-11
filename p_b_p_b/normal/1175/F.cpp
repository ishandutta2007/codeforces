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
    #define sz 303003
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

int L[sz],R[sz],cc[sz];
int st[sz],top;
int lst[sz];

#define Tree sz*25
#define lson ls[k],l,mid
#define rson rs[k],mid+1,r
int tr[Tree],ls[Tree],rs[Tree],cnt;
int root[sz];
void pushup(int k){tr[k]=tr[ls[k]]+tr[rs[k]];}
void insert(int &k,int l,int r,int x,int pre)
{
	k=++cnt;tr[k]=tr[pre]+1,ls[k]=ls[pre],rs[k]=rs[pre];
	if (l==r) return;
	int mid=(l+r)>>1;
	if (x<=mid) insert(lson,x,ls[pre]);
	else insert(rson,x,rs[pre]);
}
int query(int k,int l,int r,int x,int y)
{
	if (x<=l&&r<=y) return tr[k];
	if (!k) return 0;
	int mid=(l+r)>>1,ret=0;
	if (x<=mid) ret+=query(lson,x,y);
	if (y>mid) ret+=query(rson,x,y);
	return ret;
}

int main()
{
    file();
	read(n);
	rep(i,1,n) read(a[i]);
	int r=n;
	drep(i,n,1)
	{
		++cc[a[i]];
		while (cc[a[i]]>1) --cc[a[r]],--r;
		insert(root[i],1,n,r-i+1,root[i+1]);
	}
	st[top=1]=1;L[1]=0;
	rep(i,2,n)
	{
		while (top&&a[st[top]]<=a[i]) R[st[top]]=i,--top;
		L[i]=(top?st[top]:0);
		st[++top]=i;
	}
	while (top) R[st[top--]]=n+1;
	ll ans=0;
	rep(i,1,n)
	{
		int l=L[i]+1,r=i;
		chkmax(l,i-a[i]+1);
		chkmin(r,R[i]-a[i]);
		if (l>r) continue;
		ans+=query(root[l],1,n,a[i],n)-query(root[r+1],1,n,a[i],n);
	}
	cout<<ans;
	return 0;
}