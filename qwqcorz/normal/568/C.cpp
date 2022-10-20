#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=405;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

bool a[N];
vector<int>e[N];
void add_edge(int u,int v){e[u].push_back(v);}
int is[N];
char ans[N],s[N];
int dfn[N],low[N],cntdfn,col[N],cntcol,st[N],top=0;
bool vis[N];
void tarjan(int now)
{
	low[now]=dfn[now]=++cntdfn;
	st[++top]=now;
	vis[now]=1;
	for (int to:e[now])
	if (!dfn[to]) tarjan(to),low[now]=min(low[now],low[to]);
	else if (vis[to]) low[now]=min(low[now],dfn[to]);
	if (low[now]==dfn[now])
	{
		int c=++cntcol,x;
		do
		{
			x=st[top--];
			col[x]=c;
			vis[x]=0;
		}while (x!=now);
	}
}
bool judge(int n)
{
//	for (int i=1;i<=n+n;i++)
//	for (int to:e[i]) print(i,' '),print(to);
//	puts("");
	cntdfn=cntcol=top=0;
	memset(dfn,0,sizeof(dfn));
	for (int i=1;i<=n+n;i++) if (!dfn[i]) tarjan(i);
	for (int i=1;i<=n;i++) if (col[i]==col[i+n]) return 0;
	return 1;
}
bool check(int n)
{
	for (int i=1;i<=n;i++) if (~is[i]) add_edge(i+!is[i]*n,i+is[i]*n);
	bool ret=judge(n);
	for (int i=1;i<=n;i++) if (~is[i]) e[i+!is[i]*n].pop_back();
	return ret;
}
bool same(int n)
{
	for (int i=1;i<n;i++) if (a[i]!=a[0]) return 0;
	return 1;
}

signed main()
{
	scanf("%s",s);
	int l=strlen(s);
	for (int i=0;i<l;i++) a[i]=s[i]=='V';
	int n=read(),m=read();
	for (int i=1;i<=m;i++)
	{
		int u,v,x,y; char c1,c2;
		cin>>u>>c1>>v>>c2;
		x=c1=='V',y=c2=='V';
		add_edge(u+x*n,v+y*n);
		add_edge(v+!y*n,u+!x*n);
	}
	if (same(l)) for (int i=1;i<=n;i++) add_edge(i+!a[0]*n,i+a[0]*n);
	memset(is,-1,sizeof(is));
	if (!check(n)) return puts("-1"),0;
	scanf("%s",s+1);
	int pos=0,ch=0;
	for (int i=1;i<=n+1;i++)
	if (i<=n)
	{
		bool can[2]={};
		for (int j=s[i]+1;j<'a'+l;j++) can[a[j-'a']]=1;
		for (int j=0;j<=1;j++) if (can[j]) is[i]=j,can[j]=check(n);
		for (int j=s[i]+1;j<'a'+l;j++) if (can[a[j-'a']])
		{pos=i,ch=j;break;}
		is[i]=a[s[i]-'a'];
	}
	else if (check(n)) return puts(s+1),0;
	if (!pos) return puts("-1"),0;
	for (int i=1;i<pos;i++) ans[i]=s[i];
	ans[pos]=ch;
//	print(pos,' '),putchar(ch),putchar('\n');
	is[pos]=a[ch-'a'];
	for (int i=pos+1;i<=n;i++) is[i]=-1;
	for (int i=pos+1;i<=n;i++)
	{
		bool can[2];
		for (int j=0;j<=1;j++) is[i]=j,can[j]=check(n);
		for (int j='a';j<'a'+l;j++)
		if (can[a[j-'a']])
		{
			is[i]=a[j-'a'];
			ans[i]=j;
			break;
		}
		assert(ans[i]);
	}
	puts(ans+1);
	
	return 0;
}