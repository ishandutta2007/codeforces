#include<bits/stdc++.h>
//#define int long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define WT int TT=read();while(TT--) 
#define NO puts("NO");
#define YES puts("YES");
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int M=3e5+10;
int n,m,u[M],v[M],w[M],p[M],b[M],ans[M],cnt;
map<int,int>t;
struct node{int a,b,c;};
vector<node>e[M];

struct dsu
{
	int now,top,sz[M],f[M];
	pair<int,int>st[M];
	int find(int x){while(f[x]!=x)x=f[x];return x;}
	int check(){return now==0;}
	void init(int n){for (int i=1;i<=n;i++)f[i]=i,sz[i]=1;now=n;}
	void merge(int x,int y)
	{
		x=find(x),y=find(y);
		if (x==y)return;
		if (sz[x]>sz[y])swap(x,y);
		f[x]=y,sz[y]+=sz[x],st[++top]=mp(x,y);
		if ((sz[x]&1)&&((sz[y]&1)^1))now-=2;
	}
	void clear(int bf)
	{
		while(top>bf)
		{
			auto x=st[top--];
			f[x.x]=x.x,sz[x.y]-=sz[x.x];
			if ((sz[x.y]&1)&&(sz[x.x]&1))now+=2;
		}
	}
}T;

void work(int l,int r,int L,int R)
{
	if (l>r||L>R)return;
	int Mid=(l+r)>>1,bf=T.top;
	int mid=-1;
	for (int i=l;i<=Mid;i++)
		if (w[i]<=L)T.merge(u[i],v[i]);
	for (int i=L;i<=R;i++)
	{
		for (auto x:e[i])
			if (x.a<=Mid)T.merge(x.b,x.c);
		if (T.check()){mid=i;break;}
	}
	if (mid==-1)ans[Mid]=-1;
	else ans[Mid]=b[mid];
	T.clear(bf);
	if (mid!=-1)
	{
		for (int i=L;i<=mid;i++)
			for (auto x:e[i])if (x.a<=l)
				T.merge(x.b,x.c);
		work(l,Mid-1,mid,R);T.clear(bf);
	}
	else for (int i=l;i<Mid;i++)ans[i]=-1;
	mid=(mid==-1?cnt+1:mid);
	for (int i=l;i<=Mid;i++)if (w[i]<=L)T.merge(u[i],v[i]);
	work(Mid+1,r,L,mid-1);T.clear(bf);
}

signed main()
{
//	freopen("qwq.txt","r",stdin);
//	freopen("1.out","w",stdout);
	n=read(),m=read();T.init(n);
	for (int i=1;i<=m;i++)u[i]=read(),v[i]=read(),w[i]=p[i]=read();
	sort(p+1,p+1+m);
	for (int i=1;i<=m;i++)
		if (p[i]!=p[i-1])t[p[i]]=++cnt,b[cnt]=p[i];
	for (int i=1;i<=m;i++)w[i]=t[w[i]],e[w[i]].pb((node){i,u[i],v[i]});
	work(1,m,1,cnt);cout<<ans[1]<<endl;
	for (int i=2;i<=m;i++)
	{
		if (ans[i]<=0)ans[i]=ans[i-1];
		else if (ans[i-1]!=-1) ans[i]=min(ans[i],ans[i-1]);
		if (ans[i]==0)ans[i]=-1;
		printf("%d\n",ans[i]); 
	}
	return 0;
}
/*

*/