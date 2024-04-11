//  
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
	#define sz 233333
	#define mod 1000000007ll
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
		#ifdef NTFOrz
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

int K,n,m;
pii a[sz],b[sz];

void work(pii *a,int &n)
{
	sort(a+1,a+n+1);
	stack<pii>s;
	rep(i,1,n) { while (s.size()&&s.top().sec>=a[i].sec) s.pop(); s.push(a[i]); }
	for (n=0;s.size();a[++n]=s.top(),s.pop());
	reverse(a+1,a+n+1);
}

ll dp[sz<<1];
pair<pii,int>c[sz<<1];
ll sum[2][2];
priority_queue<pii,vector<pii>,greater<pii>>q[2];

int main()
{
	file();
	read(K,n,m);
	rep(i,1,n) read(a[i].fir,a[i].sec);
	rep(i,1,m) read(b[i].fir,b[i].sec);
	work(a,n),work(b,m);
	rep(i,1,n) c[i]=MP(a[i],1); 
	rep(i,1,m) c[i+n]=MP(b[i],0);
	n+=m; sort(c+1,c+n+1);
	rep(i,1,n)
	{
		dp[i]=mod-ksm(2,c[i].fir.fir-1);
		rep(k,0,1) 
			while (q[k].size()&&q[k].top().fir<c[i].fir.fir) 
				(sum[k][1]+=mod-dp[q[k].top().sec])%=mod,(sum[k][0]+=dp[q[k].top().sec]*ksm(2,mod-1-c[q[k].top().sec].fir.sec-1)%mod)%=mod,q[k].pop();
		rep(k,0,1) (dp[i]+=mod-ksm(2,c[i].fir.fir)*sum[k][0]%mod)%=mod;
		(dp[i]+=mod-sum[c[i].sec][1])%=mod;
		q[c[i].sec].push(MP(c[i].fir.sec,i));(sum[c[i].sec][1]+=dp[i])%=mod;
//		rep(j,1,i-1)
//			if (c[j].sec==c[i].sec) (dp[i]+=mod-dp[j]*ksm(2,max(0,c[i].fir.fir-c[j].fir.sec-1))%mod)%=mod;
//			else if (c[i].fir.fir>c[j].fir.sec) (dp[i]+=mod-dp[j]*ksm(2,c[i].fir.fir-c[j].fir.sec-1)%mod)%=mod;
	}
	ll ans=ksm(2,K);
	rep(i,1,n) (ans+=dp[i]*ksm(2,K-c[i].fir.sec)%mod)%=mod;
	cout<<ans;
	return 0;
}