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
	#define sz 505050 
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

int n;
char s[sz];
int m;
char ss[sz];

namespace SGT
{
	#define Tree sz*30
	int ls[Tree],rs[Tree],cnt;
	#define lson ls[k],l,mid
	#define rson rs[k],mid+1,r
	struct hh
	{
		int mx,pos;
		hh(int MX=0,int POS=0){mx=MX,pos=POS;}
		inline bool operator < (const hh &y) const {return mx==y.mx?pos>y.pos:mx<y.mx;};
	}tr[Tree];
	void pushup(int k){tr[k]=max(tr[ls[k]],tr[rs[k]]);}
	void insert(int &k,int l,int r,int x)
	{
		if (!k) k=++cnt;
		if (l==r) return (void)(++tr[k].mx,tr[k].pos=l);
		int mid=(l+r)>>1;
		if (x<=mid) insert(lson,x);
		else insert(rson,x);
		pushup(k);
	}
	int merge(int k1,int k2,int l,int r)
	{
		if (!k1||!k2) return k1+k2;
		int k=++cnt;
		if (l==r) return tr[k]=tr[k1],tr[k].mx+=tr[k2].mx,k;
		int mid=(l+r)>>1;
		ls[k]=merge(ls[k1],ls[k2],l,mid);
		rs[k]=merge(rs[k1],rs[k2],mid+1,r);
		pushup(k);
		return k;
	}
	hh query(int k,int l,int r,int x,int y)
	{
		if (!k) return tr[k];
		if (x<=l&&r<=y) return tr[k];
		int mid=(l+r)>>1;hh ret;
		if (x<=mid) chkmax(ret,query(lson,x,y));
		if (y>mid) chkmax(ret,query(rson,x,y));
		return ret;
	}
}

namespace SAM
{
	struct hh{int link,len,ch[28];}a[sz<<1];
	int root[sz<<1];
	int cnt=1,lst;
	int pos[sz],mxl[sz];
	void insert(int c,int id)
	{
		int cur=++cnt,p=lst;lst=cur;
		a[cur].len=a[p].len+1;
		SGT::insert(root[cur],1,m,id);
		while (p&&!a[p].ch[c]) a[p].ch[c]=cur,p=a[p].link;
		if (!p) return (void)(a[cur].link=1);
		int q=a[p].ch[c];
		if (a[q].len==a[p].len+1) return (void)(a[cur].link=q);
		int t=++cnt;
		a[t]=a[q];a[t].len=a[p].len+1;a[q].link=a[cur].link=t;
		while (p&&a[p].ch[c]==q) a[p].ch[c]=t,p=a[p].link;
	}
	int fa[sz<<1][25];
	struct hhh{int t,nxt;}edge[sz<<1];
	int head[sz],ecnt;
	void make_edge(int f,int t){edge[++ecnt]=(hhh){t,head[f]};head[f]=ecnt;}
	void dfs(int x)
	{
		rep(i,1,20) fa[x][i]=fa[fa[x][i-1]][i-1];
		go(x)
		{
			int v=edge[i].t;
			fa[v][0]=x;
			dfs(v);
			root[x]=SGT::merge(root[x],root[v],1,m);
		}
	}
	void work()
	{
		rep(i,2,cnt) make_edge(a[i].link,i);
		dfs(1);
		int cur=1,curL=0;
		rep(i,1,n)
		{
			int c=s[i]-'a'+1;
			if (a[cur].ch[c]) ++curL,cur=a[cur].ch[c];
			else
			{
				while (cur&&!a[cur].ch[c]) cur=a[cur].link;
				if (!cur) cur=1,curL=0;
				else curL=a[cur].len+1,cur=a[cur].ch[c],pos[i]=cur;
			}
			pos[i]=cur,mxl[i]=curL;
		}
	}
	int jump(int x,int len){drep(i,20,0) if (fa[x][i]&&a[fa[x][i]].len>=len) x=fa[x][i];return x;}
}

int main()
{
	file();
	cin>>(s+1);n=strlen(s+1);
	read(m);
	rep(i,1,m)
	{
		SAM::lst=1;
		cin>>(ss+1);int l=strlen(ss+1);
		rep(j,1,l) SAM::insert(ss[j]-'a'+1,i); 
	}
	SAM::work();
	int Q;read(Q);
	while (Q--)
	{
		int l,r,pl,pr;
		read(l,r,pl,pr);
		if (SAM::mxl[pr]<pr-pl+1) { printf("%d 0\n",l); continue; }
		int x=SAM::jump(SAM::pos[pr],pr-pl+1);
		SGT::hh ans=SGT::query(SAM::root[x],1,m,l,r);
		if (!ans.mx) printf("%d 0\n",l);
		else printf("%d %d\n",ans.pos,ans.mx);
	}
	return 0;
}