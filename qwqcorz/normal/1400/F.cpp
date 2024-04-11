#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e3+5;
const int inf=1e9+7;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

char s[N];
int a[N];
namespace AC_automaton
{
	int cnt=0;
	struct node
	{
		int fail,son[10],ed;
	}t[N*50];
	vector<int>e[N*50];
	void insert(int n)
	{
		int now=0;
		for (int i=1;i<=n;i++)
		{
			if (!t[now].son[a[i]-1]) t[now].son[a[i]-1]=++cnt;
			now=t[now].son[a[i]-1];
		}
		t[now].ed=1;
	}
	void dfs(int now)
	{
		t[now].ed|=t[t[now].fail].ed;
		for (int to:e[now]) dfs(to);
	}
	void build()
	{
		queue<int>q;
		for (int i=0;i<9;i++) if (t[0].son[i]) q.push(t[0].son[i]);
		while (!q.empty())
		{
			int now=q.front(); q.pop();
			e[t[now].fail].push_back(now);
			for (int i=0;i<9;i++)
			if (t[now].son[i])
			{
				t[t[now].son[i]].fail=t[t[now].fail].son[i];
				q.push(t[now].son[i]);
			}
			else t[now].son[i]=t[t[now].fail].son[i];
		}
		dfs(0);
	}
}
using namespace AC_automaton;
bool check(int n,int x)
{
	int sum=0;
	for (int i=n;i>=1;i--)
	if (x%(sum+=a[i])==0&&sum<x) return 0;
	return 1;
}
void dfs(int now,int sum,int x)
{
	if (sum==0) return insert(now-1);
	for (int i=1;i<=9&&i<=sum;i++)
	{
		a[now]=i;
		if (check(now,x)) dfs(now+1,sum-i,x);
	}
}

signed main()
{
	scanf("%s",s+1);
	int x=read(),n=strlen(s+1);
	dfs(1,x,x);
	build();
	vector<int>f(cnt+1);
	f[0]=0;
	for (int i=1;i<=cnt;i++) f[i]=-inf;
	for (int i=1;i<=n;i++)
	{
		vector<int>g(f);
		for (int j=0;j<=cnt;j++) g[t[j].son[s[i]-'1']]=max(g[t[j].son[s[i]-'1']],f[j]+1);
		for (int j=0;j<=cnt;j++) if (t[j].ed) g[j]=-inf;
		f.swap(g);
	}
	print(n-*max_element(f.begin(),f.end()));
	
	return 0;
}