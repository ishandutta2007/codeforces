#include<bits/stdc++.h>
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
void print(int x=-1,char c='\n')
{
	write(x);
	putchar(c);
}
struct edge
{
	int to,nxt;
}e[N*2];
int head[N],cnte=0;
void add_edge(int u,int v)
{
	e[++cnte].to=v;
	e[cnte].nxt=head[u];
	head[u]=cnte;
}
int ans,f[N];
vector<int>a[N];
void clear(int n)
{
	ans=n>1;
	for (int i=1;i<=n;i++) f[i]=0;
	for (int i=1;i<=n;i++) a[i].clear();
	cnte=0;
	for (int i=1;i<=n;i++) head[i]=0;
}
void dfs(int now,int father)
{
//	cout<<"in:";
//	print(now);
	for (int i=head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if (to==father) continue;
		dfs(to,now);
		a[now].push_back(f[to]);
	}
//	cout<<"out:";
//	print(now);
	if (a[now].empty()) return void(f[now]=0);
	sort(a[now].begin(),a[now].end(),greater<int>());
	if (father)
	{
		f[now]=a[now].back()+1;
		ans=max(ans,*a[now].begin()+2);
	}
	else ans=max(ans,max(a[now][0]+1,(int)a[now].size()>1?a[now][1]+2:0));
}

signed main(signed Recall,char *_902_[])
{
	(void)Recall,(void)_902_;
	int T=read();
	while (T--)
	{
		int n=read();
		clear(n);
		for (int i=1;i<n;i++)
		{
			int u=read(),v=read();
			add_edge(u,v);
			add_edge(v,u);
		}
		dfs(1,0);
		print(ans);
	}
	
	return 0;
}