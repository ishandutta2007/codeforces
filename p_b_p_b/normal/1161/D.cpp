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
	#define sz 2020
	#define mod 998244353ll
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
char s[sz];
ll ans;

unordered_map<int,int>M; // M[x]=y: xy
struct hh{int t,w,nxt;}edge[sz<<4];
int head[sz],ecnt;
void make_edge(int f,int t,int w)
{
	edge[++ecnt]=(hh){t,w,head[f]};
	head[f]=ecnt;
	edge[++ecnt]=(hh){f,w,head[t]};
	head[t]=ecnt;
} 

int col[sz];
int id[sz],cc;
bool flg;
void dfs(int x)
{
	id[++cc]=x;
	#define v edge[i].t
	go(x)
	{
		if (col[v]==-1) col[v]=col[x]^edge[i].w,dfs(v);
		else if (col[v]==(col[x]^edge[i].w)) continue;
		else flg=0;
		if (!flg) return;
	}
	#undef v
}
int calc(int x)
{
	col[x]=0;cc=0;flg=1;
	dfs(x);
	if (!flg) return 0;
	int cnt=0,ccc=0;
	rep(i,1,cc) if (M.count(id[i])) ++ccc,cnt+=M[id[i]]^col[id[i]];
	if (!ccc) return 2;
	if (cnt==0||cnt==ccc) return 1;
	return 0; 
}
void work(int m)
{
	M[n]=M[1]=M[m+n]=M[1+n]=1;
	rep(i,1,n) if (s[i]!='?')
	{
		if (i>m) M[i]=s[i]-'0';
		else make_edge(i,i+n,s[i]-'0');
	}
	rep(i,1,n) make_edge(i,n-i+1,0);
	rep(i,1,m) make_edge(i+n,m-i+1+n,0);
	rep(i,1,n+m) col[i]=-1;
	ll cur=1;
	rep(i,1,n+m) if (col[i]==-1) cur=cur*calc(i)%mod;
	(ans+=cur)%=mod;
	M.clear();ecnt=0;rep(i,1,n+m) head[i]=0;
}

int main()
{
	file();
	cin>>(s+1);n=strlen(s+1);reverse(s+1,s+n+1);
	rep(i,1,n-1) work(i);
	cout<<ans;
	return 0; 
}