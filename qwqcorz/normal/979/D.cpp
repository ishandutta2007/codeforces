#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int m=1e5;

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
inline void up(int &x,int y){if (x>y) x=y;}
int vis[N];
vector<int>fac[N];
int cnt=0;
struct node
{
	int son[2],val;
	node(){val=1<<30;}
}t[N*20*20];
struct trie
{
	#define to(x) t[now].son[x]
	int rt;
	void insert(int x)
	{
		if (!rt) rt=++cnt;
		int now=rt;
		up(t[rt].val,x);
		for (int i=17;i>=0;i--)
		{
			if (!to(x>>i&1)) to(x>>i&1)=++cnt;
			now=to(x>>i&1);
			up(t[now].val,x);
		}
	}
	int query(int x,int up)
	{
		int now=rt;
		if (t[rt].val>up) return -1;
		for (int i=17;i>=0;i--)
		if (t[to(~x>>i&1)].val<=up) now=to(~x>>i&1);
							   else now=to(x>>i&1);
		return t[now].val;
	}
	#undef to
}tr[N];

signed main(signed bangumi,char *ss969[])
{
	(void)bangumi,(void)ss969;
	for (int i=1;i<=m;i++)
	for (int j=i;j<=m;j+=i) fac[j].push_back(i);
	int Q=read();
	while (Q--)
	{
		int opt=read(),x=read();
		if (opt==1)
		{
			if (vis[x]) continue;
			vis[x]=1;
			for (int i:fac[x]) tr[i].insert(x);
		}
		else
		{
			int k=read(),s=read();
			if (x%k){puts("-1");continue;}
			print(tr[k].query(x,s-x));
		}
	}
	
	return 0;
}