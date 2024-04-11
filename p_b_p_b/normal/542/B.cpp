#include<bits/stdc++.h>
namespace my_std{
	using namespace std;
	#define pii pair<int,int>
	#define fir first
	#define sec second
	#define l fir
	#define r sec
	#define MP make_pair
	#define rep(i,x,y) for (int i=(x);i<=(y);i++)
	#define drep(i,x,y) for (int i=(x);i>=(y);i--)
	#define go(x) for (int i=head[x];i;i=edge[i].nxt)
	#define templ template<typename T>
	#define sz 403030
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
	inline void print(int x)
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
		#ifdef NTFOrz
		cerr<<clock()/1000.0<<'\n';
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

int n,T,_cnt;
pii D[sz>>1]; int _w[sz>>1];

void init()
{
	static int l[sz],r[sz],p[sz],_l[sz],_r[sz];
	rep(i,1,n) read(l[i],r[i]),chkmax(l[i],0);
	int m=0,K=0;
	rep(i,1,n) if (r[i]>=l[i]&&r[i]-l[i]<2*T-2) p[++m]=l[i],p[++m]=r[i],++K,_l[K]=l[i],_r[K]=r[i]; else if (r[i]>=l[i]) ++_cnt;
	sort(p+1,p+m+1); m=unique(p+1,p+m+1)-p-1;
	n=K; rep(i,1,n) l[i]=_l[i],r[i]=_r[i];
	rep(i,1,n) l[i]=lower_bound(p+1,p+m+1,l[i])-p,r[i]=lower_bound(p+1,p+m+1,r[i])-p;
	ll dt=p[1]; p[1]=0; rep(i,2,m) if ((p[i]-=dt)>p[i-1]+2ll*T) dt+=p[i]-(p[i-1]+2*T),p[i]=p[i-1]+2*T;
	rep(i,1,n) D[i]=MP(p[l[i]],p[r[i]]+1); sort(D+1,D+n+1);
	rep(i,1,n) { int r=D[i].r; int x=lower_bound(D+1,D+n+1,MP(r,-1))-D; ++_w[i],--_w[x]; }
	rep(i,1,n) _w[i]+=_w[i-1];
}

vector<pii>Dec[sz<<1];
struct hh{int tp,ti,l,r;hh(int a,int b,int c,int d){tp=a,ti=b,l=c,r=d;}const bool operator < (const hh &a) const {return ti==a.ti?tp<a.tp:ti<a.ti;}};
vector<hh>op[sz<<1];
vector<pii>inc[sz<<1];

const int Tree=sz*35;
int ch[Tree][2],mx[Tree],cc;
int root[sz<<1];
#define ls ch[k][0]
#define rs ch[k][1]
#define lson ls,l,mid
#define rson rs,mid+1,r
void add(int &k,int l,int r,int x,int y,int w)
{
	if (!k) return;
	int kk=k; k=++cc; ls=ch[kk][0],rs=ch[kk][1],mx[k]=mx[kk];
	if (x<=l&&r<=y) return mx[k]+=w,void();
	int tg=mx[k]-max(mx[ls],mx[rs]),mid=(l+r)>>1;
	if (x<=mid) add(lson,x,y,w);
	if (y>mid) add(rson,x,y,w);
	mx[k]=tg+max(mx[ls],mx[rs]);
}
int query(int k,int l,int r,int x,int y)
{
	if (!k) return -1e7;
	if (x<=l&&r<=y) return mx[k];
	int tg=mx[k]-max(mx[ls],mx[rs]),mid=(l+r)>>1,res=-1e7;
	if (x<=mid) chkmax(res,query(lson,x,y));
	if (y>mid) chkmax(res,query(rson,x,y));
	return res+tg;
}
void modify(int &k,int l,int r,int x,int w)
{
	int kk=k; k=++cc; mx[k]=mx[kk],ls=ch[kk][0],rs=ch[kk][1];
	if (l==r) return chkmax(mx[k],w),void();
	int mid=(l+r)>>1; int tg=(ls||rs)?mx[k]-max(mx[ls],mx[rs]):0; w-=tg;
	if (x<=mid) modify(lson,x,w);
	else modify(rson,x,w);
	mx[k]=max(mx[ls],mx[rs])+tg;
}
vector<pii>V[3];
void rebuild(int k,int l,int r,int tg,int tp)
{
	if (!k) return;
	if (l==r) return V[tp].push_back(MP(l,tg+mx[k]));
	int mid=(l+r)>>1; tg+=mx[k]-max(mx[ls],mx[rs]);
	rebuild(lson,tg,tp),rebuild(rson,tg,tp);
}
void Rebuild(int r)
{
	int l=max(0,r-2);
	rep(i,0,2) V[i].clear();
	rep(i,l,r) rebuild(root[i],0,T-1,0,i-l);
	cc=0;
	rep(i,l,r)
	{
		root[i]=0;
		for (auto t:V[i-l]) modify(root[i],0,T-1,t.fir,t.sec);
	}
}

int main()
{
	file();
//	cout<<(sizeof(mx)*3)/1024/1024;return 0; 
	read(n,T);
	init();
	rep(i,1,n)
	{
		op[D[i].l/T].push_back(hh(i,D[i].l%T,0,0));
		if (D[i].r-D[i].l>T)
		{
			auto add=[&](int l,int r,int re)
			{
				Dec[l/T].push_back(MP(l%T,(r%T==0?T:r%T))),op[re/T].push_back(hh(-1,re%T,l,r));
			};
			int l=D[i].l,r=D[i].r-T;
			if (l%T<r%T||r%T==0) add(l,r,D[i].r);
			else add(l,l-l%T+T,D[i].r),add(r-r%T,r,D[i].r);
		}
		int l=D[i].l,r=D[i].r; while (l-l%T+T<=r) inc[l/T].push_back(MP(l%T,T)),l=l-l%T+T;
		if (l<r) inc[l/T].push_back(MP(l%T,r%T));
	}
	mx[0]=-1e7; const int RE=n/10;
	int ti=0;
	rep(i,0,4*n)
	{
		if (i) root[i]=root[i-1];
		for (auto p:inc[i]) { add(root[i],0,T-1,p.fir,p.sec-1,1); if ((++ti)>RE) ti=0,Rebuild(i); }
		sort(op[i].begin(),op[i].end());
		for (auto p:op[i])
		{
			++ti;
			if (p.tp==-1) add(root[p.l/T],0,T-1,p.l%T,(p.r%T==0?T-1:p.r%T-1),1);
			else
			{
				int x=p.ti,w=0;
				if (i>0) chkmax(w,query(root[i-1],0,T-1,0,x));
				if (i>1) chkmax(w,mx[root[i-2]]);
				modify(root[i],0,T-1,x,w+_w[p.tp]);
			}
			if (ti>RE) ti=0,Rebuild(i);
		}
		for (auto p:Dec[i]) { add(root[i],0,T-1,p.fir,p.sec-1,-1); if ((++ti)>RE) ti=0,Rebuild(i); }
//		cout<<mx[root[i]]<<'\n';
	}
	cout<<max(0,mx[root[n*4]])+_cnt;
	return 0;
}