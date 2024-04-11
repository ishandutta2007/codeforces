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
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
vector<int>son[N];
int deep[N];

signed main(signed bangumi,char *ss969[])
{
	(void)bangumi,(void)ss969;
	int T=read();
	while (T--)
	{
		int n=read(),m=read();
		for (int i=1;i<=n;i++) son[i].clear();
		for (int i=1;i<=m;i++)
		{
			int u=read(),v=read();
			son[v].push_back(u);
		}
		for (int i=1;i<=n;i++)
		if (son[i].empty()) deep[i]=0;
		else
		{
			int vis[3]={0,0,0};
			for (int j:son[i]) vis[deep[j]]=1;
			if (vis[1]) deep[i]=2;
			else if (vis[0]) deep[i]=1;
			else deep[i]=0;
		}
		vector<int>ans;
		for (int i=1;i<=n;i++) if (deep[i]==2) ans.push_back(i);
		print(ans.size());
		for (int i:ans) print(i,' ');
		puts("");
	}
	
	return 0;
}