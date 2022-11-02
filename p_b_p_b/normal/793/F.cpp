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

int n,m,Q;
struct hh{int l,r,id;}a[sz];
inline bool cmp1(hh x,hh y){return x.r<y.r;}
inline bool cmp2(hh x,hh y){return x.l<y.l;}
int L[sz],R[sz];
int ans[sz];

int blo;
int bL[sz],bR[sz],bel[sz];
vector<int>q[sz];

int mx[sz];
void solve(int id)
{
	rep(i,1,n) mx[i]=i;
	vector<hh>V;
	stack<pii>s;
	drep(i,m,1) if (bel[a[i].id]<=id)
	{
		int l=a[i].l,r=a[i].r;
		while (!s.empty()&&r>=s.top().fir) chkmax(r,s.top().sec),s.pop();
		mx[l]=r,s.push(MP(l,r));
	} else if (bel[a[i].id]<=id+1) V.push_back(a[i]);
	reverse(V.begin(),V.end());
	for (auto x:q[id])
	{
		int l=L[x],r=R[x];
		int cur=mx[l];
		for (auto y:V) if (y.id<=r&&y.l<=cur&&y.l>=l) 
			chkmax(cur,y.r);
		ans[x]=cur;
	}
}

int main()
{
    file();
	read(n,m);blo=sqrt(m)+3;
	rep(i,1,m) read(a[i].l,a[i].r);
	sort(a+1,a+m+1,cmp1);
	rep(i,1,m) a[i].id=i;
	rep(i,1,m) bel[i]=i/blo+1,bR[bel[i]]=i; drep(i,m,1) bL[bel[i]]=i; 
	read(Q);
	rep(i,1,Q)
	{
		read(L[i],R[i]);
		int p=upper_bound(a+1,a+m+1,(hh){0,R[i]},cmp1)-a-1;
		q[p/blo].push_back(i);R[i]=p;
	}
	sort(a+1,a+m+1,cmp2);
	rep(i,0,m/blo) solve(i);
	rep(i,1,Q) printf("%d\n",ans[i]);
	return 0;
}