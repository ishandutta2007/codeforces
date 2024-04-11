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
	#define sz 202020
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
#define lson ls,l,mid
#define rson rs,mid+1,r

int n;
int a[sz],b[sz];

namespace SGT1 //  
{
	#define ls k<<1
	#define rs k<<1|1
	int tr[sz<<2];
	void pushup(int k){tr[k]=min(tr[ls],tr[rs]);}
	void modify(int k,int l,int r,int x)
	{
		if (l==r) return tr[k]=b[x],void();
		int mid=(l+r)>>1;
		if (x<=mid) modify(lson,x);
		else modify(rson,x);
		pushup(k);
	}
	int query(int k,int l,int r,int p)
	{
		if (l==r) return l;
		int mid=(l+r)>>1;
		if (tr[ls]<p) return query(lson,p);
		return query(rson,p);
	}
	#undef ls
	#undef rs
}

namespace SGT2 //  
{
	#define Tree 25100100
	#define ls ch[k][0]
	#define rs ch[k][1]
	int ch[Tree][2]; ll tr[Tree],tag[Tree];
	int cc;
	void modify(int &k,int l,int r,int x,int y,ll w,int pre)
	{
		k=++cc; tr[k]=tr[pre],tag[k]=tag[pre],ls=ch[pre][0],rs=ch[pre][1];
		if (x<=l&&r<=y) return tag[k]+=w,tr[k]+=w*(r-l+1),void();
		int mid=(l+r)>>1;
		if (x<=mid) modify(lson,x,y,w,ch[pre][0]);
		if (y>mid) modify(rson,x,y,w,ch[pre][1]);
		tr[k]=tr[ls]+tr[rs];
	}
	ll query(int k,int l,int r,int x,int y)
	{
		if (!k) return 0;
		if (x<=l&&r<=y) return tr[k];
		int mid=(l+r)>>1; ll res=tag[k]*(min(y,r)-max(x,l)+1);
		if (x<=mid) res+=query(lson,x,y);
		if (y>mid) res+=query(rson,x,y);
		return res;
	}
}

struct hh
{
	int l,r,w,t;
	const bool operator < (const hh &a) const {return w<a.w;}
};
set<hh>cur;
struct hhh
{
	int l,r; hh w;
	const bool operator < (const hhh &a) const {return l<a.l;}
};
set<hhh>vis[sz];
struct tr
{
	int p,rt;
	const bool operator < (const tr &a) const {return p<a.p;}
};
set<tr>RT[sz];

void del(hh x,int r) //  a_r  x 
{
	int k=x.w;
	cur.erase(x);
	if (x.t!=r) vis[k].insert((hhh){x.t,r-1,x});
	int pre=(RT[k].size()?(*prev(RT[k].end())).rt:0); int rt;
	SGT2::modify(rt,1,n,x.l,x.r,r-x.t,pre);
	if (RT[k].size()&&(*prev(RT[k].end())).p==r) RT[k].erase(prev(RT[k].end()));
	RT[k].insert((tr){r,rt});
}
void add(hh x,int r) //  a_r  x
{
	auto it=cur.find(x);
	if (it!=cur.end()) x.l=(*it).l,del(*it,r);
	cur.insert(x);
} 
void work1(int p,int x)
{
	a[p]=x; b[x]=p; SGT1::modify(1,0,n,x);
	auto it=cur.find((hh){0,0,x,0});
	if (it!=cur.end())
	{
		int l=(*it).l,r=(*it).r;
		del(*it,p);
		while (l<=r) { int w=SGT1::query(1,0,n,r); 
		add((hh){max(l,b[w]+1),r,w,p},p); r=b[w]; }
	}
	add((hh){p,p,!x,p},p);
}

ll work2(int l,int r,int k)
{
	ll ans=0;
	if (RT[k].size())
	{
		auto it=RT[k].upper_bound((tr){r,0});
		if (it!=RT[k].begin())
		{
			--it;
			ans+=SGT2::query((*it).rt,1,n,l,r);
		}
	}
	auto it=cur.find((hh){0,0,k,0});
	if (it!=cur.end()&&(*it).t<=r) ans+=1ll*(r-(*it).t+1)*(max(l-1,(*it).r)-max(l,(*it).l)+1);
	else
	{
		auto itt=vis[k].upper_bound((hhh){r,0,(hh){0,0,0,0}});
		if (itt==vis[k].begin()) return ans;
		--itt;
		if ((*itt).r<r) return ans;
		hh w=(*itt).w;
		ans+=1ll*(r-w.t+1)*(max(l-1,w.r)-max(l,w.l)+1);
	}
	return ans;
}

int main()
{
	file();
	read(n);
	ll lans=0;
	rep(i,1,n)
	{
		int x,l,r,k;read(x,l,r,k);
		x=(x+lans)%(n+1),l=(l+lans)%i+1,r=(r+lans)%i+1,k=(k+lans)%(n+1);
		if (l>r) swap(l,r);
		work1(i,x);
		printf("%lld\n",lans=work2(l,r,k));
	}
	return 0;
}