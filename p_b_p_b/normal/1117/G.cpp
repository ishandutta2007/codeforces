#include<bits/stdc++.h>
clock_t t=clock();
namespace my_std{
	using namespace std;
	#define pil pair<int,ll>
	#define fir first
	#define sec second
	#define MP make_pair
	#define rep(i,x,y) for (int i=(x);i<=(y);i++)
	#define drep(i,x,y) for (int i=(x);i>=(y);i--)
	#define go(x) for (int i=head[x];i;i=edge[i].nxt)
	#define sz 1010010
	#define templ template<typename T>
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
	char sr[1<<21],z[20];int C=-1,Z=0;
    inline void Ot(){fwrite(sr,1,C+1,stdout),C=-1;}
    inline void print(register int x)
    {
    	if(C>1<<20)Ot();if(x<0)sr[++C]='-',x=-x;
    	while(z[++Z]=x%10+48,x/=10);
    	while(sr[++C]=z[Z],--Z);sr[++C]='\n';
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

int n,m;
int a[sz];
int L[sz],R[sz];

const int Tree=sz<<2;
struct TREE
{
	ll sum[Tree];
	int cnt[Tree];
	#define ls k<<1
	#define rs k<<1|1
	#define lson k<<1,l,mid
	#define rson k<<1|1,mid+1,r
	void insert(int k,int l,int r,ll x)
	{
		++cnt[k];sum[k]+=x;
		if (l==r) return;
		int mid=(l+r)>>1;
		if (x<=mid) insert(lson,x);
		else insert(rson,x);
	}
	pil query(int k,int l,int r,int x,int y)
	{
		if (x>r||y<l) return MP(0,0);
		if (x<=l&&r<=y) return MP(cnt[k],sum[k]);
		int mid=(l+r)>>1;
		pil L=query(lson,x,y),R=query(rson,x,y);
		return MP(L.fir+R.fir,L.sec+R.sec);
	}
	pil query(int l,int r){return query(1,0,n+1,l,r);}
}l,r;

int LL[sz],RR[sz];
int id[sz];
inline bool cmp(const int &x,const int &y){return a[x]<a[y];}
void init()
{
	rep(i,1,n) LL[i]=i-1,RR[i]=i+1,id[i]=i;
	RR[0]=1;LL[n+1]=n;
	sort(id+1,id+n+1,cmp);
	int x;
	rep(i,1,n) x=id[i],L[x]=LL[x],R[x]=RR[x],RR[LL[x]]=RR[x],LL[RR[x]]=LL[x];
}

int ql[sz],qr[sz];
ll Ans[sz];
struct hh{int x,l,r,id,v;}q[sz<<1];
inline bool cmpp(const hh &x,const hh &y){return x.x<y.x;}

signed main()
{
	file();
	read(n,m);
	rep(i,1,n) read(a[i]);
	init();
	int x,y;
	rep(i,1,m) read(ql[i]); rep(i,1,m) read(qr[i]);
	rep(i,1,m) q[i*2-1]=(hh){ql[i]-1,ql[i],qr[i],i,-1},q[i*2]=(hh){qr[i],ql[i],qr[i],i,1};
	sort(q+1,q+m+m+1,cmpp);
	int p=1;
	while (!q[p].x) ++p;
	rep(i,1,n)
	{
		if (p>m*2) break;
		l.insert(1,0,n+1,L[i]+1),r.insert(1,0,n+1,R[i]-1);
		while (p<=m*2&&q[p].x==i)
		{
			x=q[p].l,y=q[p].r;
			ll ans=0;
			pil a,b;
			a=r.query(y+1,n+1),b=r.query(0,y);
			ans+=1ll*y*a.fir+b.sec;
			a=l.query(0,x-1),b=l.query(x,n+1);
			ans-=1ll*x*a.fir+b.sec;
			Ans[q[p].id]+=1ll*q[p].v*ans;
			++p;
		}
	}
	rep(i,1,m) printf("%I64d ",Ans[i]+1ll*(qr[i]-ql[i]+1));
	return 0;//
}