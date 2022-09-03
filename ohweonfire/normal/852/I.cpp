//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define bged(v) (v).begin(),(v).end()
#define foreach(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
typedef long long ll;
const int Imx=2147483647;
const ll Lbig=2e18;
const int mod=1e9+7;
//My i/o stream
struct fastio
{
	char s[100000];
	int it,len;
	fastio(){it=len=0;}
	inline char get()
	{
		if(it<len)return s[it++];it=0;
		len=fread(s,1,100000,stdin);
		if(len==0)return EOF;else return s[it++];
	}
	bool notend()
	{
		char c=get();
		while(c==' '||c=='\n')c=get();
		if(it>0)it--;
		return c!=EOF;
	}
}_buff;
#define geti(x) x=getnum()
#define getii(x,y) geti(x),geti(y)
#define getiii(x,y,z) getii(x,y),geti(z)
#define puti(x) putnum(x),putchar(' ')
#define putii(x,y) puti(x),puti(y)
#define putiii(x,y,z) putii(x,y),puti(z)
#define putsi(x) putnum(x),putchar('\n')
#define putsii(x,y) puti(x),putsi(y)
#define putsiii(x,y,z) putii(x,y),putsi(z)
inline ll getnum()
{
	ll r=0;bool ng=0;char c;c=_buff.get();
	while(c!='-'&&(c<'0'||c>'9'))c=_buff.get();
	if(c=='-')ng=1,c=_buff.get();
	while(c>='0'&&c<='9')r=r*10+c-'0',c=_buff.get();
	return ng?-r:r;
}
template<class T> inline void putnum(T x)
{
	if(x<0)putchar('-'),x=-x;
	register short a[20]={},sz=0;
	while(x)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1;i>=0;i--)putchar('0'+a[i]);
}
inline char getreal(){char c=_buff.get();while(c==' '||c=='\n')c=_buff.get();return c;}
int n,dfn[100111],dfnr[100111],dfntot;
int p[20][100111],lv[100111];
vector<int>con[100111];
int a[200111];
bool ty[100111];
int f[100111];
int cnt0[100111],cnt1[100111];
ll curans;
bool st[100111];
void _add(int x)
{
//	cerr<<"add:"<<x<<endl;
	if(!ty[x])cnt0[f[x]]++,curans+=cnt1[f[x]];
	else cnt1[f[x]]++,curans+=cnt0[f[x]];
}
void _del(int x)
{
//	cerr<<"del:"<<x<<endl;
	if(!ty[x])cnt0[f[x]]--,curans-=cnt1[f[x]];
	else cnt1[f[x]]--,curans-=cnt0[f[x]];
}
void add(int x)
{
	if(st[a[x]])_del(a[x]);
	else _add(a[x]);
	st[a[x]]^=1;
}
void add0(int x)
{
	if(st[x])_del(x);
	else _add(x);
	st[x]^=1;
}
int mptot;
map<int,int> mp;
void dfs(int x,int pre=0)
{
	p[0][x]=pre;lv[x]=lv[pre]+1;
	for(int i=1;i<20;i++)p[i][x]=p[i-1][p[i-1][x]];
	dfn[x]=++dfntot;a[dfntot]=x;
	for(int i=0;i<con[x].size();i++)
	{
		int u=con[x][i];
		if(u==pre)continue;
		dfs(u,x);
//		a[++dfntot]=x;
	}
	dfnr[x]=++dfntot;a[dfntot]=x;
}
const int B=400;
struct command
{
	int l,r,id;
	command(int L=0,int R=0,int Id=0){l=L;r=R;id=Id;}
	bool operator<(const command &t)const
	{
		if(l/B!=t.l/B)return l/B<t.l/B;
		else return r<t.r;
	}
}cmd[100111];
ll ans[100111];
int getlca(int x,int y)
{
	if(lv[x]>lv[y])swap(x,y);
	for(int i=19;i>=0;i--)
		if((lv[y]-lv[x])>=(1<<i))
			y=p[i][y];
	if(x==y)return x;
	for(int i=19;i>=0;i--)
		if(p[i][x]!=p[i][y])
			x=p[i][x],y=p[i][y];
	return p[0][x];
}
int main()
{
	geti(n);
	for(int i=1;i<=n;i++)geti(ty[i]);
	for(int i=1;i<=n;i++)
	{
		geti(f[i]);
		int &v=mp[f[i]];
		if(!v)v=++mptot;
		f[i]=v;
	}
	for(int i=1;i<n;i++)
	{
		int x,y;
		getii(x,y);
		con[x].PB(y);
		con[y].PB(x);
	}
	dfs(1);
//	for(int i=1;i<=dfntot;i++)cout<<a[i]<<" ";cout<<endl;
	int q;
	geti(q);
	for(int i=1;i<=q;i++)
	{
		int x,y;
		getii(x,y);
		if(dfn[x]>dfn[y])swap(x,y);
		cmd[i]=command(dfn[x],dfn[y],i);
	}
	sort(cmd+1,cmd+q+1);
	int L=1,R=0;
	for(int i=1;i<=q;i++)
	{
		int l=cmd[i].l,r=cmd[i].r;
		int x=a[l],y=a[r];
//		cerr<<l<<" "<<r<<endl;
		while(L>l)add(--L);
		while(R<r)add(++R);
		while(L<l)add(L++);
		while(R>r)add(R--);
		if(dfn[x]<=dfn[y]&&dfnr[y]<=dfn[y])
		{
			ans[cmd[i].id]=curans;
		}
		else
		{
			int p=getlca(x,y);
			add0(x);
			add0(p);
//			cerr<<x<<","<<y<<":"<<p<<endl;
			ans[cmd[i].id]=curans;
			add0(x);
			add0(p);
		}
	}
	for(int i=1;i<=q;i++)putsi(ans[i]);
	return 0;
}