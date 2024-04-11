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
	#define sz 4666
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

int n,Q;
int a[sz];
int B;
vector<int>p[sz];
typedef vector<vector<int>> vv;
vv id[sz];

int cnt;
pii ans[2220202];
int merge(int x,int y){if (!x||!y) return x+y;++cnt;ans[cnt]=MP(x,y);return cnt;}

vv work(vector<int>p)
{
	int n=p.size();
	vv res;res.resize(n);rep(i,0,n-1) res[i].resize(n);
	if (n==1) return res[0][0]=p[0],res;
	vector<int>L,R;
	int l=1e9,r=0; for (auto x:p) chkmin(l,a[x]),chkmax(r,a[x]);
	int mid=(l+r)>>1;
	for (auto x:p) if (a[x]<=mid) L.push_back(x); else R.push_back(x);
	vv LL=work(L),RR=work(R);
	int n1=L.size(),n2=R.size();
	int l1=0,l2=0;
	rep(l,0,n-1)
	{
		int r1=l1-1,r2=l2-1;
		rep(r,l,n-1) (a[p[r]]<=mid)?++r1:++r2,res[l][r]=merge(((l1<=r1&&r1<n1)?LL[l1][r1]:0),((l2<=r2&&r2<n2)?RR[l2][r2]:0));
		(a[p[l]]<=mid)?++l1:++l2;
	}
	return res;
}

int ans2[sz<<4];

int main()
{
	file();
	read(n,Q); B=sqrt(Q); chkmin(B,n); cnt=n;
	rep(i,1,n) read(a[i]),p[a[i]/B].push_back(i);
	rep(i,1/B,n/B) id[i]=work(p[i]);
	rep(i,1,Q)
	{
		int l,r;read(l,r);
		rep(k,1/B,n/B) 
		{ 
			int L=lower_bound(p[k].begin(),p[k].end(),l)-p[k].begin(),R=upper_bound(p[k].begin(),p[k].end(),r)-p[k].begin()-1; 
			if (L<=R) ans2[i]=merge(ans2[i],id[k][L][R]); 
		}
	}
	printf("%d\n",cnt);
	rep(i,n+1,cnt) printf("%d %d\n",ans[i].fir,ans[i].sec);
	rep(i,1,Q) printf("%d ",ans2[i]);
	return 0;
}