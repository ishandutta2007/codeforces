#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct edge
{
	int v,nxt;
}e[2000005];
int n,ch[1000005][26],fail[1000005],len[1000005],cnt=1,las=1;
int h[1000005],t,dfn[1000005],dt,sz[1000005],sum[1000005],f[1000005];
int a[1000005],dp[1000005];
char s[1000005];
void add(int u,int v)
{
	e[++t].v=v;
	e[t].nxt=h[u];
	h[u]=t;
}
void ins(int c)
{
	int p=las,np=++cnt;
	las=cnt;
	len[np]=len[p]+1;
	while(p&&!ch[p][c]) ch[p][c]=np,p=fail[p];
	if(!p) fail[np]=1;
	else
	{
		int q=ch[p][c];
		if(len[q]==len[p]+1) fail[np]=q;
		else
		{
			int nq=++cnt;
			for(int i=0;i<26;i++)
				ch[nq][i]=ch[q][i];
			len[nq]=len[p]+1;
			fail[nq]=fail[q];
			fail[q]=fail[np]=nq;
			while(p&&ch[p][c]==q) ch[p][c]=nq,p=fail[p];
		}
	}
}
void dfs(int u,int fa)
{
	dfn[u]=++dt;
	sz[u]=1;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs(v,u);
		sz[u]+=sz[v];
	}
}
inline int lowbit(int x)
{
	return x&-x;
}
void modify(int x,int v)
{
	for(int i=x;i<=cnt;i+=lowbit(i))
		sum[i]+=v;
}
int query(int x)
{
	int ans=0;
	for(int i=x;i;i-=lowbit(i))
		ans+=sum[i];
	return ans;
}
void tmodify(int x)
{
	int u=a[x];
	f[u]=max(f[u],dp[x]);
	modify(dfn[u],1);
}
bool check(int x,int l)
{
	//printf("check:x=%d,l=%d\n",x,l);
	return f[x]>=l||query(dfn[x]+sz[x]-1)-query(dfn[x])>0;
}
int main()
{
//	freopen("fade.in","r",stdin);
//	freopen("fade.out","w",stdout);
	scanf("%d%s",&n,s+1);
	n=strlen(s+1);
	reverse(s+1,s+n+1);
	for(int i=1;i<=n;i++)
		ins(s[i]-'a');
	for(int i=2;i<=cnt;i++)
		add(fail[i],i);
	dfs(1,0);
	int nw=0,ans=0;
	a[0]=1;
	for(int i=1;i<=n;i++)
	{
		int p=a[i-1],np;
		np=ch[p][s[i]-'a'];
		int q=np;
		if(nw<=len[fail[q]]) q=fail[q];
		while(!check(p,nw)&&!check(q,nw))
		{
		//	printf("i=%d,p=%d,nw=%d\n",i,p,nw);
			tmodify(i-nw);
			nw--;
			np=q;
			if(nw<=len[fail[p]]) p=fail[p];
			if(nw<=len[fail[q]]) q=fail[q];
		}
		nw++;
		a[i]=np;
		dp[i]=nw;
		ans=max(ans,nw);
	}
	printf("%d\n",ans);
	return 0;
}