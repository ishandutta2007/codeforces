#include<bits/stdc++.h>
#define mk make_pair
using namespace std;
const int N=233;
const int p=998244353;

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
void add(int &x,int y){x+=y;if (x>=p) x-=p;}
int cnt,id[50][50],vis[50][50];
struct Matrix{int a[N][N];}tr;
struct Vector{int a[N];}f;
Matrix operator *(const Matrix &a,const Matrix &b)
{
	Matrix ret;
	memset(ret.a,0,sizeof(ret.a));
	for (int i=1;i<=cnt;i++)
	for (int k=1;k<=cnt;k++)
	for (int j=1;j<=cnt;j++)
	add(ret.a[i][j],1LL*a.a[i][k]*b.a[k][j]%p);
	return ret;
}
Vector operator *(const Vector &a,const Matrix &b)
{
	Vector ret;
	memset(ret.a,0,sizeof(ret.a));
	for (int i=1;i<=cnt;i++)
	for (int j=1;j<=cnt;j++)
	add(ret.a[j],1LL*a.a[i]*b.a[i][j]%p);
	return ret;
}
char a[10];
struct trie
{
	int cnt;
	struct node
	{
		int son[26],end,down;
	}t[50];
	void insert(char *a,int len)
	{
		int now=0;
		#define to t[now].son[a[i]-'a']
		for (int i=1;i<=len;i++)
		{
			if (!to) to=++cnt;
			now=to;
		}
		t[now].end=1;
		#undef to
	}
	void ysgs()
	{
		for (int i=0;i<=cnt;i++)
		for (int j=0;j<26;j++) t[i].down|=!!t[i].son[j];
	}
	void dfs(int u,int v)
	{
		if (vis[u][v]) return;
		vis[u][v]=1;
		for (int k=0;k<26;k++)
		if (t[u].son[k]&&t[v].son[k])
		{
			int nu=t[u].son[k],nv=t[v].son[k];
			for (int i=!t[nu].down;i<=t[nu].end;i++)
			for (int j=!t[nv].down;j<=t[nv].end;j++)
			{
				if (i) nu=0; if (j) nv=0;
				dfs(nu,nv);
				nu=t[u].son[k],nv=t[v].son[k];
			}
		}
	}
	void build()
	{
		for (int u=0;u<=cnt;u++)
		for (int v=u;v<=cnt;v++)
		if (id[u][v])
		for (int k=0;k<26;k++)
		if (t[u].son[k]&&t[v].son[k])
		{
			int nu=t[u].son[k],nv=t[v].son[k];
			for (int i=!t[nu].down;i<=t[nu].end;i++)
			for (int j=!t[nv].down;j<=t[nv].end;j++)
			{
				if (i) nu=0; if (j) nv=0;
				tr.a[id[u][v]][id[nu][nv]]+=1+(!nu&&!nv&&u!=v)-(u==v&&i!=j?tr.a[id[u][v]][id[nu][nv]]:0);
//				print(id[u][v],' ');
//				print(id[nu][nv],':');
//				print(tr.a[id[u][v]][id[nu][nv]]);
				nu=t[u].son[k],nv=t[v].son[k];
			}
		}
	}
}t;

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	int n=read(),m=read();
	for (int i=1;i<=n;i++)
	{
		scanf("%s",a+1);
		t.insert(a,strlen(a+1));
	}
	t.ysgs();
	t.dfs(0,0);
	for (int i=0;i<=t.cnt;i++)
	for (int j=i;j<=t.cnt;j++)
	if (vis[i][j]) id[i][j]=id[j][i]=++cnt;
	t.build();
	f.a[1]=1;
	while (m)
	{
		if (m&1) f=f*tr;
		tr=tr*tr;
		m/=2;
	}
	print(f.a[1]);
	
	return 0;
}