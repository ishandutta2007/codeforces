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
struct Matching
{
	int n,m;
	int mx[611],my[611];
	bool f[611][611];
	int tag[611],cur;
	void init(int N,int M)
	{
		n=N;m=M;
		memset(mx,0,sizeof(mx));
		memset(my,0,sizeof(my));
		memset(f,0,sizeof(f));
		memset(tag,0,sizeof(tag));
		cur=0;
	}
	void sete(int x,int y){f[x][y]=1;}
	bool dfs(int x)
	{
		if(tag[x]==cur)return false;
		tag[x]=cur;
		for(int y=1;y<=m;y++)
		{
			if(f[x][y])
			{
				if(!my[y]||dfs(my[y]))
				{
					mx[x]=y;
					my[y]=x;
					return true;
				}
			}
		}
		return false;
	}
	int solve()
	{
		int ans=0;
		for(int i=1;i<=n;i++)cur++,ans+=dfs(i);
		return ans;
	}
}graph;
int n,m,tn,K;
int st[611];
int w[611][611];
bool check(int T)
{
	graph.init(tn,n);
	for(int i=1;i<=tn;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(w[st[i]][j]<=T)
			{
				graph.sete(i,j);
			}
		}
	}
	return graph.solve()>=K;
}
int main()
{
	getii(n,m);
	getii(tn,K);
	for(int i=1;i<=tn;i++)geti(st[i]);
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)w[i][j]=i==j?0:mod;
	for(int i=1;i<=m;i++)
	{
		int x,y,t;
		getiii(x,y,t);
		w[x][y]=min(w[x][y],t);
		w[y][x]=min(w[y][x],t);
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				w[i][j]=w[i][k]+w[k][j]<w[i][j]?w[i][k]+w[k][j]:w[i][j];
	int l=0,r=1731311;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(check(mid))r=mid-1;
		else l=mid+1;
	}
	if(l>1731311)puts("-1");
	else cout<<l<<endl;
	return 0;
}