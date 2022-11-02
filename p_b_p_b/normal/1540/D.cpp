#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
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
	#define sz 101010
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

int n,B,cc;
int b[sz];
int L[sz],R[sz],bel[sz];

int tr[sz];
void add(int x,int w){while (x<=n) tr[x]+=w,x+=x&-x;}
int query(int K){int x=0,cur=0;drep(i,16,0) if ((1<<i)+x<=n&&cur+tr[1<<i|x]<K) x+=1<<i,cur+=tr[x];return x+1;}
int qq(int x){int res=0;while (x) res+=tr[x],x-=x&-x;return res;}

vector<int>T[1033];
void rebuild(int id)
{
	T[id].clear();
	static int pos[sz];
	drep(i,R[id],L[id])
	{
		pos[i]=query(b[i]+1);
		add(pos[i],-1);
	}
	rep(i,L[id],R[id]) T[id].push_back(qq(pos[i]));
	sort(T[id].begin(),T[id].end());
	rep(i,L[id],R[id]) add(pos[i],1);
}

int main()
{
	file();
	read(n);
	rep(i,1,n) read(b[i]);
	B=sqrt(n/2); chkmax(B,1); cc=(n-1)/B+1;
	rep(i,1,cc) L[i]=R[i-1]+1,R[i]=R[i-1]+B; R[cc]=n;
	rep(i,1,cc) rep(k,L[i],R[i]) bel[k]=i;
	rep(i,1,n) add(i,1);
	rep(i,1,cc) rebuild(i);
	int Q; read(Q);
	while (Q--)
	{
		int tp,x,y; read(tp,x);
		if (tp==1) read(y),b[x]=y,rebuild(bel[x]);
		else
		{
			int cur=b[x]+1;
			rep(i,x+1,R[bel[x]]) if (b[i]<cur) ++cur;
			rep(i,bel[x]+1,cc) { int p=lower_bound(T[i].begin(),T[i].end(),cur)-T[i].begin(); cur+=p; }
			printf("%d\n",n-cur+1);
		}
	}
	return 0;
}