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
    #define sz 505005
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
pii a[sz];
int ans[sz];

struct hh
{
	int l,r,lw,rw;
	const bool operator < (const hh &x) const {return r==x.r?l<x.l:r<x.r;}
};
set<hh>s;
priority_queue<int>q1,q2;
int top(){while (q2.size()&&q1.top()==q2.top()) q1.pop(),q2.pop();return q1.top();}
void del(int x){q2.push(x);}
void push(int x){q1.push(x);}
void Insert(hh x){push(x.r-x.l+1);s.insert(x);}

struct hhh{int l,r,w;}tmp1[sz],tmp2[sz];int c1,c2;

void add(hhh *tmp,int &c,hh p)
{
	if (p.lw==p.rw) tmp[++c]=(hhh){p.l,p.r,p.lw};
	else tmp[++c]=(hhh){p.l,(p.l+p.r)>>1,p.lw},tmp[++c]=(hhh){((p.l+p.r)>>1)+1,p.r,p.rw};
}
void work(hhh *tmp,int &c,hh L,int w,hh R)
{
	c=0;
	hh cur=L;
	if (cur.rw==1-w) ++cur.r,cur.rw^=1; else add(tmp,c,cur),cur=(hh){L.r+1,L.r+1,w,w};
	if (cur.rw==1-R.lw) cur.r=R.r,cur.rw=R.rw; else add(tmp,c,cur),cur=R;
	add(tmp,c,cur);
}
void work(set<hh>::iterator it,int w)
{
	hh L,R;
	if (it==s.begin()) L=(hh){0,0,1,1}; else L=*prev(it),s.erase(prev(it)),del(L.r-L.l+1);
	if (next(it)==s.end()) R=(hh){n+1,n+1,1,1}; else R=*next(it),s.erase(next(it)),del(R.r-R.l+1);
	s.erase(it);
	work(tmp1,c1,L,1,R);
	if (L.r==0) L=(hh){0,0,0,0};
	if (R.l==n+1) R=(hh){n+1,n+1,0,0};
	work(tmp2,c2,L,0,R);
	rep(i,1,c1) rep(j,1,c2)
	{
		int l=max(tmp1[i].l,tmp2[j].l),r=min(tmp1[i].r,tmp2[j].r);
		if (l>r||tmp1[i].w==tmp2[j].w) continue;
		rep(k,max(1,l),min(n,r)) ans[k]=w;
	}
	if (L.r==0) { if (R.lw==1) R.lw=0,--R.l; else Insert((hh){1,1,0,0}); Insert(R); }
	else if (R.l==n+1) { if (L.rw==1) L.rw=0,++L.r; else Insert((hh){n,n,0,0}); Insert(L); }
	else
	{
		hh cur=L;
		if (cur.rw==1) ++cur.r,cur.rw=0; else Insert(cur),cur=(hh){L.r+1,L.r+1,0,0};
		if (cur.rw==1-R.lw) cur.r=R.r,cur.rw=R.rw; else Insert(cur),cur=R;
		Insert(cur);
	}
}

int main()
{
    file();
	read(n);
	rep(i,1,n) read(a[i].fir),a[i].sec=i;
	if (n==1) return printf("0\n%d\n",a[1].fir),0;
	if (n==2) return printf("0\n%d %d\n",a[1].fir,a[2].fir),0;
	sort(a+1,a+n+1);
	rep(i,1,n) s.insert((hh){i,i,1,1});
	int Ans=0;
	rep(i,1,n)
	{
		int x=a[i].sec;
		auto it=s.lower_bound((hh){-1,x,1,1});
		hh p=*it;s.erase(it);del(p.r-p.l+1);
		if (x!=p.l) Insert((hh){p.l,x-1,p.lw,p.lw^((x-1-p.l)&1)});
		if (x!=p.r) Insert((hh){x+1,p.r,p.rw^((p.r-1-x)&1),p.rw});
		it=s.insert((hh){x,x,1,1}).fir;
		work(it,a[i].fir);
		if (i==n||a[i].fir!=a[i+1].fir) chkmax(Ans,(top()-1)>>1);
	}
	printf("%d\n",Ans);
	rep(i,1,n) printf("%d ",ans[i]);
	return 0;
}