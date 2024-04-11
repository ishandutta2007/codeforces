#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;

int read()
{
	int s=0;
	char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(int x)
{
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
vector<int>son[N];
struct state
{
	int add;
	multiset<int>s;
	map<int,int>dp;
	int Min(){return *s.begin();}
	void pop(int x)
	{
		s.erase(s.find(dp[x]));
		dp.erase(x);
	}
	void change(int x,int y)
	{
		if (dp.count(x)) s.erase(s.find(dp[x]));
		s.insert(dp[x]=y);
	}
	void up(int x,int y)
	{
		y-=add;
		if (!dp.count(x)) s.insert(dp[x]=y);
		else if (y<dp[x]) s.erase(s.find(dp[x])),s.insert(dp[x]=y);
	}
}a[N];
int f[N],st[N],top=0,cnt=0,x[N],v[N],len,s;
void merge(int &x,int y,int z)
{
	if (!a[x].dp.count(z)) return;
	int tmp=a[x].dp[z]+a[x].add;
	a[x].pop(z);
	if (a[x].dp.size()>=a[y].dp.size())
	{
		for (auto i:a[y].dp)
		a[x].up(i.first,i.second+a[y].add+tmp);
	}
	else
	{
		a[y].add+=tmp;
		for (auto i:a[x].dp) a[y].up(i.first,i.second+a[x].add);
		x=y;
	}
}
void dfs(int now)
{
	for (int to:son[now])
	if (f[to]>=0)
	{
		dfs(to);
		merge(f[now],f[to],x[to]);
//	print(now);
//	for (auto i:a[f[now]].dp)
//	print(i.first,':'),print(i.second+a[f[now]].add);
	}
	else
	{
		a[f[now]].add+=v[-f[to]];
		if (x[-f[to]]!=s) a[f[now]].change(x[-f[to]],a[f[now]].Min()-v[-f[to]]);
//	print(now);
//	for (auto i:a[f[now]].dp)
//	print(i.first,':'),print(i.second+a[f[now]].add);
	}
}

signed main(signed bangumi,char *ss969[])
{
	(void)bangumi,(void)ss969;
	len=read(),s=read();
	a[0].dp[0]=0;
	for (int i=1;i<=len;i++)
	{
		string s; cin>>s;
		if (s=="if")
		{
			st[++top]=++cnt,f[cnt]=cnt;
			son[st[top-1]].push_back(st[top]);
			x[cnt]=read();
			a[cnt].dp[x[cnt]]=0;
		}
		if (s=="end") top--;
		if (s=="set")
		{
			son[st[top]].push_back(++cnt);
			f[cnt]=-cnt;
			x[cnt]=read();
			v[cnt]=read();
		}
	}
	for (int i=0;i<=cnt;i++) a[i].s.insert(0);
	dfs(0);
	print(a[f[0]].Min()+a[f[0]].add);
//	for (int i=0;i<cnt;i++)
//	for (int j:son[i]) print(i,' '),print(j);
	
	return 0;
}