#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct edge
{
	int v,nxt;
}e[500005];
int len,n,m,h[100005],t,g[100005],gt,low[100005],dfn[100005],ct;
int nxt[105][2],st[100005],tp,vis[100005],a[100005],b[100005];
char s[105],str[100005],tans[100005];
void add(int u,int v)
{
//	printf("u=%d,v=%d\n",u,v);
	e[++t].v=v;
	e[t].nxt=h[u];
	h[u]=t;
}
inline int F(char ch)
{
	return ch=='C'?1:0;
}
void dfs(int u)
{
	dfn[u]=low[u]=++ct;
	st[++tp]=u;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(!dfn[v])
		{
			dfs(v);
			low[u]=min(low[u],low[v]);
		}
		else if(!vis[v]) low[u]=min(low[u],dfn[v]);
	}
	if(low[u]==dfn[u])
	{
		gt++;
		st[tp+1]=0;
		while(st[tp+1]!=u)
		{
			g[st[tp]]=gt;
			vis[st[tp]]=1;
			tp--;
		}
	}
}
void dfs2(int u)
{
	if(a[u]) return;
	a[u]=1;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		dfs2(v);
	}
}
bool check(int x)
{
	for(int i=1;i<=2*n;i++)
		b[i]=a[i];
	dfs2(x);
	int fl=1;
	for(int i=1;i<=n;i++)
		if(a[i]&&a[n+i])
			fl=0;
	for(int i=1;i<=2*n;i++)
		a[i]=b[i];
	//printf("check:x=%d,fl=%d\n",x,fl);
	return fl;
}
int main()
{
	scanf("%s",s);
	len=strlen(s);
	nxt[len][0]=nxt[len][1]=1e9;
	for(int i=len-1;i>=0;i--)
	{
		int q=F(s[i]);
		nxt[i][q]=i;
		nxt[i][q^1]=nxt[i+1][q^1];
	}
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		char chx,chy;
		int x,y,xx,yy;
		scanf("%d %c%d %c",&x,&chx,&y,&chy);
		xx=F(chx),yy=F(chy);
		add(xx*n+x,yy*n+y);
		add((yy^1)*n+y,(xx^1)*n+x);
	}
	scanf("%s",str+1);
	for(int i=1;i<=2*n;i++)
		if(!dfn[i])
			dfs(i);
	for(int i=1;i<=n;i++)
		if(g[i]==g[i+n])
		{
			printf("-1\n");
			return 0;
		}
	int nw=-1;
	for(int i=1;i<=n+1;i++)
	{
		if(i==n+1)
		{
			printf("%s",str+1);
			return 0;
		}
		int ch=str[i]-'a';
		if(nxt[ch+1][0]!=1e9&&check(i)||nxt[ch+1][1]!=1e9&&check(i+n))
			nw=i-1;
		if(!check(i+n*F(s[ch]))) break;
		dfs2(i+n*F(s[ch]));
	}
	memset(a,0,sizeof(a));
	for(int i=1;i<=nw;i++)
		dfs2(i+n*F(s[str[i]-'a']));
//	printf("nw=%d\n",nw);
	if(nw==-1)
	{
		printf("-1\n");
		return 0;
	}
	/*int nw=0;
	while(nw<n&&check(nw+1+n*F(s[str[nw+1]-'a'])))
	{
		dfs2(nw+1+n*F(s[str[nw+1]-'a']));
		nw++;
		tans[nw]=str[nw];
	}*/
	for(int i=1;i<=nw;i++)
		tans[i]=str[i];
	for(int i=nw+1;i<=n;i++)
	{
		int ch;
		if(i==nw+1) ch=str[i]-'a'+1;
		else ch=0;
		//printf("i=%d,nxt=%d,%d\n",i,nxt[ch][0],nxt[ch][1]);
		if(nxt[ch][0]<nxt[ch][1])
		{
			if(check(i))
			{
				dfs2(i);
				tans[i]=nxt[ch][0]+'a';
			}
			else
			{
				if(nxt[ch][1]==1e9)
				{
					printf("-1\n");
					return 0;
				}
				dfs2(i+n);
				tans[i]=nxt[ch][1]+'a';
			//	printf("tans=%c\n",tans[i]);
			}
		}
		else
		{
			if(check(i+n))
			{
				dfs2(i+n);
				tans[i]=nxt[ch][1]+'a';
			}
			else
			{
				if(nxt[ch][0]==1e9)
				{
					printf("-1\n");
					return 0;
				}
				dfs2(i);
				tans[i]=nxt[ch][0]+'a';
			}
		}
	}
	printf("%s\n",tans+1);
	return 0;
}