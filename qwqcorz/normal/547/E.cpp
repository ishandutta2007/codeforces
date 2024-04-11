#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
const int M=5e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

struct bit
{
	int t[N],n;
	void add(int x){for (;x<=n;x+=x&-x) t[x]++;}
	int query(int x){int ret=0;for (;x;x&=x-1) ret+=t[x];return ret;}
	int query(int l,int r){return query(r)-query(l-1);}
}t;
vector<int>e[N];
int st[N],ed[N],cntdfn=0;
int cnt=0,son[N][26],fail[N],pos[N];
void dfs(int now)
{
	st[now]=++cntdfn;
	for (int to:e[now]) dfs(to);
	ed[now]=cntdfn;
}
void build()
{
	queue<int>q;
	for (int i=0;i<26;i++) if (son[0][i]) q.push(son[0][i]);
	while (!q.empty())
	{
		int now=q.front(); q.pop();
		for (int i=0;i<26;i++)
		if (son[now][i])
		{
			fail[son[now][i]]=son[fail[now]][i];
			q.push(son[now][i]);
		}
		else son[now][i]=son[fail[now]][i];
	}
	for (int i=1;i<=cnt;i++) e[fail[i]].push_back(i);
	dfs(0),t.n=cntdfn;
}
char tmp[N];
string s[N];
struct Query{int id,k,f;};
vector<Query>q[N];
int ans[M];

signed main()
{
	int n=read(),Q=read();
	for (int i=1;i<=n;i++)
	{
		scanf("%s",tmp);
		int len=strlen(tmp);
		for (int j=0;j<len;j++) s[i]+=tmp[j];
		int now=0;
		for (int j=0;j<len;j++)
		{
			if (!son[now][tmp[j]-'a']) son[now][tmp[j]-'a']=++cnt;
			now=son[now][tmp[j]-'a'];
		}
		pos[i]=now;
	}
	build();
	for (int i=1;i<=Q;i++)
	{
		int l=read(),r=read(),k=read();
		q[r].push_back((Query){i,k,1});
		q[l-1].push_back((Query){i,k,-1});
	}
	for (int i=1;i<=n;i++)
	{
		int len=s[i].size(),now=0;
		for (int j=0;j<len;j++) t.add(st[now=son[now][s[i][j]-'a']]);
		for (auto j:q[i]) ans[j.id]+=j.f*t.query(st[pos[j.k]],ed[pos[j.k]]);
	}
	for (int i=1;i<=Q;i++) print(ans[i]);
	
	return 0;
}