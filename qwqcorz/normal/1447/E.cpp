#include<bits/stdc++.h>
#define ls t[now].son[0]
#define rs t[now].son[1]
using namespace std;
const int N=2e5+5;
const int LOG=31;
const int inf=N*LOG-1;

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
	if (x<0)
	{
		putchar('-');
		x=-x;
	}
	if (x<10) putchar(x+'0');
	else
	{
		write(x/10);
		putchar(x%10+'0');
	}
}
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
struct trie
{
	int son[2];
	int sum,ans;
//	int del[2];
}t[N*LOG];
void dfs(int now)
{
	if (now==inf) return;
	dfs(ls);
	dfs(rs);
	t[now].sum=t[now].sum+t[ls].sum+t[rs].sum;
	t[now].ans=max(t[ls].ans+(t[rs].sum>0),t[rs].ans+(t[ls].sum>0));
	if (ls==inf&&rs==inf) t[now].ans=1;
//	
//	t[now].del[1]=min(t[ls].del[1]+t[rs].del[0],t[ls].del[0]+t[rs].del[1]);
//	if (t[now].sum-t[now].del[1]==2) t[now].del[1]++;
//	
//	t[now].del[0]=t[ls].del[0]+t[rs].del[0];
//	t[now].del[1]=min(t[now].del[0],t[now].del[1]);
//	if (t[now].sum-t[now].del[0]==2) t[now].del[0]++;
//	
//	print(t[now].sum,':');
//	print(t[now].del[0],' ');
//	print(t[now].del[1]);
}
int cnt=0;

signed main()
{
	memset(t,0,sizeof(t));
	int n=read();
	for (int i=0;i<N*LOG;i++)
	{
		t[i].son[0]=inf;
		t[i].son[1]=inf;
	}
	for (int i=1;i<=n;i++)
	{
		int x=read(),now=0;
		for (int i=30;i>=0;i--)
		{
//			putchar((x&(1<<i))>0);
			if (t[now].son[(x&(1<<i))>0]==inf) t[now].son[(x&(1<<i))>0]=++cnt;
			now=t[now].son[(x&(1<<i))>0];
		}
//		puts("");
		t[now].sum=1;
	}
	dfs(0);
	print(n-t[0].ans);

	return 0;
}