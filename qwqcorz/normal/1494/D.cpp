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
int cnt,val[N],fa[N],a[N][N];
vector<int>son[N],tmp[N];
int find(int x)
{
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
int dfs(vector<int>id)
{
	if ((int)id.size()==1)
	{
		val[id[0]]=a[id[0]][id[0]];
		return id[0];
	}
	int now=++cnt;
	int Max=0;
	for (int i:id)
	for (int j:id) Max=max(Max,a[i][j]);
	val[now]=Max;
	for (int i:id) tmp[i].clear();
	for (int i:id) fa[i]=i;
	for (int i:id)
	for (int j:id) if (a[i][j]<Max) fa[find(i)]=find(j);
	for (int i:id) tmp[find(i)].push_back(i);
	for (int i:id) if (!tmp[i].empty()) son[now].push_back(dfs(tmp[i]));
	return now;
}

signed main(signed Recall,char *_902_[])
{
	(void)Recall,(void)_902_;
	int n=cnt=read();
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++) a[i][j]=read();
	for (int i=1;i<=n;i++) tmp[0].push_back(i);
	dfs(tmp[0]);
	print(cnt);
	for (int i=1;i<=cnt;i++) print(val[i],' ');
	puts("");
	print(n+1);
	for (int i=1;i<=cnt;i++)
	for (int j:son[i]) print(j,' '),print(i);
	
	return 0;
}