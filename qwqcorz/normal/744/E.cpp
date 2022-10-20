#include<bits/stdc++.h>
using namespace std;
const int N=35;
const int M=1e5+5;
const int mod=1919810111;

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
struct edge
{
	int to,nxt;
}e[M*N];
int head[M],cnte,siz[M];
void add_edge(int u,int v)
{
//	print(u,' ');
//	print(v);
	siz[v]++;
	e[++cnte].to=v;
	e[cnte].nxt=head[u];
	head[u]=cnte;
}
int len[N],cnt=0,pw[M];
string a[N];
vector<int>h[N],id[N];
void clear()
{
	cnte=0;
	for (int i=0;i<=cnt;i++) head[i]=siz[i]=0;
}
int get_hash(int i,int l,int r)
{
	return (h[i][r]-1LL*h[i][l-1]*pw[r-l+1]%mod+mod)%mod;
}
int q[M];
bool check(int l,int r)
{
//	puts("");
//	print(l,':');
//	print(r);
	clear();
	for (int i=l;i<=r;i++) add_edge(0,id[i][1]);
	for (int i=l;i<=r;i++)
	for (int j=1;j<=len[i];j++)
	for (int k=l;k<=r;k++)
	{
		if (len[i]-j+1==len[k])
		{
			if (j==1) continue;
			if (h[k][len[k]]==get_hash(i,j,len[i])) add_edge(id[i][j],0);
		}
		else if (len[i]-j+1>len[k])
		{
			if (h[k][len[k]]==get_hash(i,j,j+len[k]-1)) add_edge(id[i][j],id[i][j+len[k]]);
		}
		else if (h[k][len[i]-j+1]==get_hash(i,j,len[i])) add_edge(id[i][j],id[k][len[i]-j+2]);
	}
	int h=1,t=0;
	for (int i=0;i<=cnt;i++) if (!siz[i]) q[++t]=i;
	while (h<=t)
	{
		int now=q[h++];
		for (int i=head[now];i;i=e[i].nxt)
		{
			int to=e[i].to;
			if (!--siz[to]) q[++t]=to;
		}
	}
	return t==cnt+1;
}

signed main()
{
	int n=read();
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		len[i]=a[i].length();
		h[i].resize(len[i]+1);
		id[i].resize(len[i]+1);
		a[i]=' '+a[i];
		h[i][0]=id[i][0]=0;
		for (int j=1;j<=len[i];j++)
		{
			h[i][j]=(h[i][j-1]*26LL+a[i][j]-'a')%mod;
			id[i][j]=++cnt;
		}
	}
	for (int i=pw[0]=1;i<=cnt;i++) pw[i]=pw[i-1]*26LL%mod;
	int ans=0;
	for (int i=1,j=1;i<=n;i++)
	{
		while (j<=i&&!check(j,i)) j++;
		ans+=i-j+1;
//		print(j,','),print(i);
	}
	print(ans);
	
	return 0;
}