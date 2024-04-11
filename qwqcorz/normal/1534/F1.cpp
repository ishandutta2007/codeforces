#include<bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
using namespace std;
const int N=4e5+5;

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
int u[N*4],v[N*4],n,m,siz[N];
int id(int x,int y){return x*m+y;}
struct edge
{
	int to,nxt;
}e[N*4];
int head[N],cnte=0;
void add_edge(int u,int v)
{
	e[++cnte].to=v;
	e[cnte].nxt=head[u];
	head[u]=cnte;
}
void add(int x,int y)
{
	add_edge(x,y);
	u[cnte]=x;
	v[cnte]=y;
}
vector<bool>a[N];
vector<int>down[N],s[N];
int p[N],val[N],S[N],cov[N];
int st[N],top=0,dfn[N],low[N],cntdfn=0,vis[N],col[N],cntcol=0,l[N],r[N];
void tarjan(int now)
{
	vis[st[++top]=now]=1;
	dfn[now]=low[now]=++cntdfn;
	for (int i=head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if (!dfn[to]) tarjan(to),low[now]=min(low[now],low[to]);
		else if (vis[to]) low[now]=min(low[now],dfn[to]);
	}
	if (low[now]==dfn[now])
	{
		int x=0,c=++cntcol;
		l[c]=m+1,r[c]=0;
		do
		{
			x=st[top--];
			vis[x]=0;
			col[x]=c;
		}while (x!=now);
	}
}
void dfs(int now)
{
	vis[now]=1;
	for (int i=head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if (!vis[to]) dfs(to);
		l[now]=min(l[now],l[to]);
		r[now]=max(r[now],r[to]);
	}
}
void cover(int now)
{
	if (!cov[now]) return;
	for (int i=head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if (cov[to]>1) continue;
		cov[to]=min(cov[to]+cov[now],2);
		cover(to);
	}
}
struct segment
{
	int l,r;
	bool operator <(const segment &a)const
	{
		return l<a.l;
	}
}seg[N];

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	n=read(),m=read();
	for (int i=0;i<n;i++)
	for (int j=0;j<m;j++)
	{
		char c=getchar();
		while (c!='.'&&c!='#') c=getchar();
		a[i].push_back(c=='#');
		if (c=='#') s[j].push_back(i);
	}
	int cnts=0;
	for (int i=0;i<m;i++)
	{
		int t=read(),x=t?s[i][(int)s[i].size()-t]:-1;
		if (~x) S[++cnts]=id(x,i);
	}
	for (int j=0;j<m;j++)
	{
		down[j].resize(n+1);
		down[j][n]=n;
		for (int i=n-1;i>=0;i--)
		if (a[i][j]) down[j][i]=i;
				else down[j][i]=down[j][i+1];
	}
	for (int i=0;i<n;i++)
	for (int j=0;j<m;j++)
	if (a[i][j])
	{
		if (i&&a[i-1][j]) add(id(i,j),id(i-1,j));
		if (down[j][i+1]<n) add(id(i,j),id(down[j][i+1],j));
		if (j&&down[j-1][i]<n) add(id(i,j),id(down[j-1][i],j-1));
		if (j+1<m&&down[j+1][i]<n) add(id(i,j),id(down[j+1][i],j+1));
	}
	for (int i=0;i<n*m;i++) if (!dfn[i]&&a[i/m][i%m]) tarjan(i);
	memset(head,0,sizeof(head));
	int tmp=cnte; cnte=0;
	for (int i=1;i<=tmp;i++)
	if (col[u[i]]!=col[v[i]])
	add_edge(col[u[i]],col[v[i]]),siz[col[v[i]]]++;
	for (int i=1;i<=cnts;i++) cov[col[S[i]]]=1;
	for (int i=1;i<=cntcol;i++) cover(i);
	tmp=cnts; cnts=0;
	for (int i=1;i<=tmp;i++) if (cov[col[S[i]]]<=1) S[++cnts]=S[i];
	for (int i=1;i<=cnts;i++)
	{
		int c=col[S[i]];
		l[c]=min(l[c],i);
		r[c]=max(r[c],i);
	}
	int cnt=0;
	memset(vis,0,sizeof(vis));
	for (int i=1;i<=cntcol;i++)
	{
		if (!vis[i]) dfs(i);
		if (!siz[i]&&r[i]) seg[++cnt]=(segment){l[i],r[i]};
	}
//	for (int i=0;i<n*m;i++) if (col[i]) print(col[i],':'),print(siz[col[i]],'.'),print(l[col[i]],' '),print(r[col[i]]);
//	puts("");
	int ans=0;
	sort(seg+1,seg+1+cnt);
//	for (int j=1;j<=cnt;j++) print(seg[j].l,' '),print(seg[j].r);
	for (int j=1,ri=0;ri<cnts;)
	{
		int tmp=0;
		while (j<=cnt&&seg[j].l<=ri+1) tmp=max(tmp,seg[j++].r);
		assert(tmp>=ri);
		ri=tmp;
		ans++;
	}
	print(ans);
	
	return 0;
}