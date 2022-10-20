#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;

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
vector<int>e[N];
int fa[N],col[N],deep[N],cnt[2];
pair<int,int>mn(N,N);
void dfs(int now,int father,int c)
{
	cnt[col[now]=c]++;
	deep[now]=deep[fa[now]=father]+1;
	for (int to:e[now])
	{
		if (to==father) continue;
		if (col[to]<0) dfs(to,now,!c);
		else if (deep[now]>deep[to]) mn=min(mn,make_pair(deep[now]-deep[to]+1,now));
	}
}

signed main()
{
	memset(col,-1,sizeof(col));
	int n=read(),m=read(),k=read(),tot=(k+1)/2;
	for (int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1,0,0);
	if (m==n-1)
	{
		puts("1");
		for (int i=1;i<=n;i++) if (col[i]==(cnt[1]>cnt[0]))
		{
			print(i," \n"[!--tot]);
			if (!tot) break;
		}
	}
	else
	if (mn.first<=k)
	{
		puts("2");
		print(mn.first);
		for (int now=mn.second,i=1;i<=mn.first;i++,now=fa[now]) print(now," \n"[i==mn.first]);
	}
	else
	{
		puts("1");
		for (int now=mn.second,i=1;i<=tot;i++,now=fa[fa[now]]) print(now," \n"[i==tot]);
	}
	
	return 0;
}