#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
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
void ckmax(int &a,int b){a=(a>b?a:b);}
void ckmin(int &a,int b){a=(a<b?a:b);}

const int inf=5e18;
const int M=3e5+10;
int n,x[M],w[M],st[M],top,q,ans[M]; 
vector<pii>e[M],qu[M];

int calc(int a,int b){return abs(x[a]-x[b])*(w[a]+w[b]);}

struct BIT
{
	int c[M];
	void init(){memset(c,0x3f,sizeof(c));}
	int lowbit(int x){return x&(-x);}
	void upd(int k,int x)
	{
		for (int i=k;i<=n;i+=lowbit(i))ckmin(c[i],x);
	}
	int ask(int k)
	{
		int res=inf;
		for (int i=k;i>=1;i-=lowbit(i))ckmin(res,c[i]);
		return res;
	}
}T;

signed main()
{
	n=read(),q=read();T.init();
	for (int i=1;i<=n;i++)x[i]=read(),w[i]=read();
	for (int i=1;i<=n;i++)
	{
		while(top>0&&w[st[top]]>w[i])top--;
		if (top!=0)
		{
			int val=calc(st[top],i);
			e[st[top]].pb(mp(i,val));
		}st[++top]=i;
	}top=0;
	for (int i=n;i>=1;i--)
	{
		while(top>0&&w[st[top]]>w[i])top--;
		if (top!=0)
		{
			int val=calc(st[top],i);
			e[i].pb(mp(st[top],val));
		}st[++top]=i;
	}
	for (int i=1;i<=q;i++)
	{
		int l=read(),r=read();
		qu[l].pb(mp(r,i));
	}
	for (int i=n;i>=1;i--)
	{
		for (auto x:e[i])
			T.upd(x.x,x.y);
		for (auto x:qu[i])
			ans[x.y]=T.ask(x.x);
	}
	for (int i=1;i<=q;i++)cout<<ans[i]<<'\n';
	return 0;
}