#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
const int B=300;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

struct bl
{
	inline int bel(int x){return (x-1)/B+1;}
	int sum1[N],sum2[N],n,m,L[N],R[N];
	void send(int _n)
	{
		n=_n,m=bel(n);
		for (int i=1;i<=n;i++) R[bel(i)]=i;
		for (int i=n;i>=1;i--) L[bel(i)]=i;
	}
	void add(int x,int y)
	{
		for (int i=bel(x);i<=m;i++) sum1[i]+=y;
		for (int i=x;i<=R[bel(x)];i++) sum2[i]+=y;
	}
	int query(int x)
	{
		if (!x) return 0;
		return sum1[bel(x)-1]+sum2[x];
	}
	int query(int x,int y)
	{
		return query(y)-query(x-1);
	}
}b;
struct Query
{
	int l,r,k;
	ll ans;
}q[N];
vector<int>qi[N],q1[N];
ll sum[N],val[N];
vector<int>e[N];
struct node
{
	int son[26],fail;
	vector<int>id;
}t[N];
int cnt=0;
inline void build()
{
	queue<int>q;
	t[0].fail=0;
	for (int i=0;i<26;i++)
	if (t[0].son[i])
	{
	   	q.push(t[0].son[i]);
		t[t[0].son[i]].fail=0;
	}
	while (!q.empty())
	{
		int now=q.front(); q.pop();
		for (int i=0;i<26;i++)
		if (t[now].son[i])
		{
			t[t[now].son[i]].fail=t[t[now].fail].son[i];
			q.push(t[now].son[i]);
		}
		else t[now].son[i]=t[t[now].fail].son[i];
	}
	for (int i=1;i<=cnt;i++) e[t[i].fail].push_back(i);
}
string a[N];
void dfs0(int now)
{
	for (int to:e[now])
	{
		dfs0(to);
		sum[now]+=sum[to];
	}
	for (int i:t[now].id) val[i]=sum[now];
}
void dfs1(int now)
{
	for (int i:t[now].id) b.add(i,1);
	for (int i:q1[now]) q[i].ans+=b.query(q[i].l,q[i].r);
	for (int to:e[now]) dfs1(to);
	for (int i:t[now].id) b.add(i,-1);
}
void GreenDay()
{
	int n=read(),Q=read();
	b.send(n);
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		int now=0,len=a[i].size();
		for (int j=0;j<len;j++)
		{
			if (!t[now].son[a[i][j]-'a']) t[now].son[a[i][j]-'a']=++cnt;
			now=t[now].son[a[i][j]-'a'];
		}
		t[now].id.push_back(i);
	}
	build();
	for (int i=1;i<=Q;i++)
	{
		q[i].l=read(),q[i].r=read(),q[i].k=read();
		qi[q[i].k].push_back(i);
	}
	for (int i=1;i<=n;i++)
	if (a[i].size()<=B)
	{
		int now=0,len=a[i].size();
		for (int j=0;j<len;j++)
		{
			now=t[now].son[a[i][j]-'a'];
			for (int k:qi[i]) q1[now].push_back(k);
		}
	}
	else
	{
		memset(sum,0,sizeof(sum));
		int now=0,len=a[i].size();
		for (int j=0;j<len;j++)
		{
			now=t[now].son[a[i][j]-'a'];
			sum[now]++;
		}
		dfs0(0);
		for (int j=1;j<=n;j++) sum[j]=sum[j-1]+val[j];
		for (int j:qi[i]) q[j].ans=sum[q[j].r]-sum[q[j].l-1];
	}
	dfs1(0);
	for (int i=1;i<=Q;i++) print(q[i].ans);
}

signed main()
{
	int T=1;
//	int T=read();
	while (T--) GreenDay();
	
	return 0;
}