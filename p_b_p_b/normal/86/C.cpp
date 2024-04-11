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
	#define sz 1010
	#define mod 1000000009
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

int n,m;
string s;

int ch[sz][30],fail[sz];
int cnt;
int ed[sz];
void insert(string s)
{
	int cur=0;
	rep(i,0,(int)s.size()-1)
	{
		int &x=ch[cur][s[i]-'A'+1];
		if (!x) x=++cnt;
		cur=x;
	}
	ed[cur]=s.size();
}
void getfail()
{
	queue<int>q;
	rep(i,1,26) if (ch[0][i]) fail[ch[0][i]]=0,q.push(ch[0][i]);
	while (!q.empty())
	{
		int x=q.front();q.pop();
		rep(i,1,26)
		{
			int &t=ch[x][i];
			if (t) fail[t]=ch[fail[x]][i],q.push(t);
			else t=ch[fail[x]][i];
		}
		chkmax(ed[x],ed[fail[x]]);
	}
}

ll dp[2][111][sz];

int main()
{
	file();
	read(n,m);
	rep(i,1,m) cin>>s,insert(s);
	getfail();
	dp[0][0][0]=1;
	int cur=1,lst=0;
	rep(i,0,n-1) 
	{
		rep(j,0,cnt) rep(k,max(0,i-12),i) rep(s,1,26)
		{
			int x=ch[j][s];
			int t=k;
			if (ed[x]&&i+1-ed[x]<=k) t=i+1;
			(dp[cur][x][t]+=dp[lst][j][k])%=mod; 
		}
		swap(cur,lst);
		rep(j,0,cnt) rep(k,max(i-12,0),i+1) dp[cur][j][k]=0;
	}
	ll ans=0;
	rep(i,0,cnt) (ans+=dp[lst][i][n])%=mod;
	cout<<ans;
	return 0;
}