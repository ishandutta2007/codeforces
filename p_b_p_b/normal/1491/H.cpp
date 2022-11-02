#include<bits/stdc++.h>
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
	#define sz 101100
	#define M 400
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

int n,Q,B;
int bel[sz],L[sz],R[sz];
int fa[sz],up[sz],tag[sz];

void rebuild(int id)
{
	if (tag[id]) return;
	int l=L[id],r=R[id];
	rep(i,max(2,l),r) chkmax(fa[i],1);
	int flg=1; rep(i,l,r) if (fa[i]<l) up[i]=fa[i]; else up[i]=up[fa[i]],flg=0;
	if (flg) { rep(i,l,r) ++fa[i]; ++tag[id]; }
}

int main()
{
	file();
	read(n,Q);
	rep(i,2,n) read(fa[i]);
	B=sqrt(n); chkmax(B,2);
	rep(i,1,n) bel[i]=(i-1)/B+1,R[bel[i]]=i; drep(i,n,1) L[bel[i]]=i;
	L[1]=2;
	rep(i,1,n) if (fa[i]<L[bel[i]]) up[i]=fa[i]; else up[i]=up[fa[i]];
	bel[1]=0;
	while (Q--)
	{
		int t,l,r,x,y;
		read(t);
		if (t==1)
		{
			read(l,r,x);
			if (bel[l]==bel[r])
			{
				rep(i,max(2,l),r) fa[i]-=x,chkmax(fa[i],1);
				rebuild(bel[l]);
			}
			else
			{
				rep(i,bel[l]+1,bel[r]-1) if (!tag[i]) { rep(k,L[i],R[i]) fa[k]-=x; rebuild(i); } else tag[i]+=x,chkmin(tag[i],n);
				rep(i,l,R[bel[l]]) chkmax(fa[i]-=x,1); rebuild(bel[l]);
				rep(i,L[bel[r]],r) chkmax(fa[i]-=x,1); rebuild(bel[r]);
			}
		}
		else
		{
			read(x,y);
			auto qq=[&](int x)
			{
				int res; if (x==1) return 0;
				if (!tag[bel[x]]) res=up[x]; else res=max(1,fa[x]-tag[bel[x]]);
				return res;
			};
			while (233)
			{
				if (x==y) break;
				if (bel[x]<bel[y]) swap(x,y);
				if (bel[x]!=bel[y]) { x=qq(x); continue; }
				int xx=qq(x),yy=qq(y);
				if (xx!=yy) { x=xx,y=yy; continue; }
				break;
			}
			while (x!=y)
			{
				if (x<y) swap(x,y);
				x=max(1,fa[x]-tag[bel[x]]);
			}
			printf("%d\n",x);
		}
	}
}