#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;

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
int Ask(vector<int>&a)
{
	cout<<"? ";
	print(a.size(),' ');
	for (int i:a) print(i,' ');
	cout<<endl;
	return read();
}
vector<int>g[N];
vector<pair<int,int>>e;
void dfs(int now,int father)
{
	for (int to:g[now])
	{
		if (to==father) continue;
		e.push_back(make_pair(now,to));
		dfs(to,now);
	}
}
bool vis[N];
int check(int l,int r)
{
	vector<int>a;
	for (int i=l;i<r;i++)
	{
		int u=e[i].first,v=e[i].second;
		if (!vis[u]) vis[u]=1,a.push_back(u);
		if (!vis[v]) vis[v]=1,a.push_back(v);
	}
	for (int i:a) vis[i]=0;
	return Ask(a);
}

signed main(signed bangumi,char *ss1672[])
{
	(void)bangumi,(void)ss1672;
	int n=read();
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read();
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector<int>tmp;
	for (int i=1;i<=n;i++) tmp.push_back(i);
	int maxdis=Ask(tmp);
	dfs(1,0);
	int l=0,r=n;
	while (l+1<r)
	{
		int mid=(l+r)/2;
		if (check(l,mid)==maxdis) r=mid;
							 else l=mid;
	}
	cout<<"! ",print(e[l].first,' '),print(e[l].second);
	
	return 0;
}