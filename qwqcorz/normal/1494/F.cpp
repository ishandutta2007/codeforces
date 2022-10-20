#include<bits/stdc++.h>
using namespace std;
const int N=3e3+5;

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
void print(int x=-1,char c='\n')
{
	write(x);
	putchar(c);
}
bool is[N];
set<int>e[N],E[N];
vector<int>t,ans;
void dfs(int now)
{
	while (!e[now].empty())
	{
		int to=*e[now].begin();
		e[now].erase(to);
		e[to].erase(now);
		dfs(to);
	}
	ans.push_back(now);
}
bool check(int n,int s)
{
	for (int i=1;i<=n;i++) e[i]=E[i];
	for (int to:t) e[s].erase(to),e[to].erase(s);
	dfs(s);
	for (int i=1;i<=n;i++) if (!e[i].empty()) return 0;
	ans.push_back(-1);
	for (int to:t) ans.push_back(to),ans.push_back(s);
	return 1;
}

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	int n=read(),m=read(),cnt=0;
	for (int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		E[u].insert(v);
		E[v].insert(u);
	}
	for (int i=1;i<=n;i++) cnt+=is[i]=E[i].size()&1;
	for (int i=1;i<=n;i++)
	{
		int tot=is[i];
		for (int to:E[i]) tot+=is[to];
		if (tot>=cnt-1)
		{
			t.clear();
			for (int to:E[i]) if (is[to]) t.push_back(to);
			if (!t.empty()&&(int)t.size()+is[i]==cnt)
			{
				int siz=(int)t.size();
				for (int j=0;j<siz;j++)
				{
					int tmp=t[j];
					swap(t[j],t[siz-1]);
					t.pop_back();
					if (check(n,i))
					{
						print(ans.size());
						for (int i:ans) print(i,' ');
						return 0;
					}
					else ans.clear();
					t.push_back(tmp);
					swap(t[j],t[siz-1]);
				}
			}
			else
				if (check(n,i))
				{
					print(ans.size());
					for (int i:ans) print(i,' ');
					return 0;
				}
				else ans.clear();
		}
	}
	puts("0");
	
	return 0;
}