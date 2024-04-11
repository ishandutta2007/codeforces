#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;

int get()
{
	string s;
	cin>>s;
	return s=="RIGHT";
}
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
int son[N][2],fa[N],fin[N];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
vector<int>a[N][2];
void connect(int x,int y)
{
	son[y][1]=x;
	fa[x]=find(y);
	fin[find(y)]=fin[x];
}
void dfs(int now)
{
	if (!now) return;
	dfs(son[now][0]);
	print(now,' ');
	dfs(son[now][1]);
}

signed main(signed bangumi,char *ss969[])
{
	(void)bangumi,(void)ss969;
	int n=read(),q=read();
	for (int i=1;i<=q;i++)
	{
		int x=read(),y=read(),z=get();
		a[x][z].push_back(y);
		if (x>=y) return puts("IMPOSSIBLE"),0;
	}
	for (int i=1;i<=n;i++) fa[i]=fin[i]=i;
	for (int i=1;i<=n;i++)
	for (int j=0;j<=1;j++)
	sort(a[i][j].begin(),a[i][j].end());
	for (int i=n;i>=1;i--)
	{
//		print(i);
		if (!a[i][0].empty()&&!a[i][1].empty())
		if (find(a[i][0].back())>=find(a[i][1][0]))
		return puts("IMPOSSIBLE"),0;
		if (!a[i][0].empty())
		{
			son[i][0]=i+1,fa[i+1]=i,fin[i]=fin[i+1];
			while (find(a[i][0].back())!=i)
			{
//				for (int j=1;j<=n;j++) print(fa[j]," \n"[j==n]);
				connect(fin[i]+1,fin[i]);
			}
		}
		if (!a[i][1].empty())
		{
			if (find(find(a[i][1][0])-1)!=i&&a[i][0].empty())
			son[i][0]=i+1,fa[i+1]=i,fin[i]=fin[i+1];
			while (find(find(a[i][1][0])-1)!=i) connect(fin[i]+1,fin[i]);
			int x=find(a[i][1][0]);
			son[i][1]=x,fa[x]=i,fin[i]=fin[x];
			while (find(a[i][1].back())!=i) connect(fin[i]+1,fin[i]);
		}
	}
	while (fin[1]!=n) connect(fin[1]+1,fin[1]);
	dfs(1);
//	for (int i=1;i<=n;i++) print(son[i][0],' '),print(son[i][1]);
//	for (int i=1;i<=n;i++)
//	for (int j=0;j<=1;j++)
//	if (son[i][j]) print(i,' '),print(son[i][j]);
	
	return 0;
}