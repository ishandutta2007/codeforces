#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct edge
{
	int v,nxt;
}e[2000005];
int n,fail[400005],rt[400005],sum[10000005],ls[10000005],rs[10000005],ct;
int cnt=1,las=1,ch[400005][26],len[400005],h[400005],f[400005];
int mn[10000005],dp[400005],t,g[400005];
char s[400005];
void pushup(int x)
{
	sum[x]=sum[ls[x]]+sum[rs[x]];
	mn[x]=min(mn[ls[x]],mn[rs[x]]);
}
int merge(int x,int y)
{
	if(!x||!y) return x+y;
	int z=++ct;
	sum[z]=sum[x]+sum[y];
	mn[z]=min(mn[x],mn[y]);
	ls[z]=merge(ls[x],ls[y]);
	rs[z]=merge(rs[x],rs[y]);
	return z;
}
int modify(int x,int l,int r,int qx)
{
	if(l>qx||r<qx) return x;
	if(!x) x=++ct;
	if(l==r)
	{
		sum[x]=1;
		mn[x]=l;
		return x;
	}
	int mid=(l+r)/2;
	ls[x]=modify(ls[x],l,mid,qx);
	rs[x]=modify(rs[x],mid+1,r,qx);
	pushup(x);
	return x;
}
int query(int x,int l,int r,int ql,int qr)
{
	if(l>qr||r<ql) return 0;
	if(ql<=l&&r<=qr) return sum[x];
	int mid=(l+r)/2;
	return query(ls[x],l,mid,ql,qr)+query(rs[x],mid+1,r,ql,qr);
}
void add(int u,int v)
{
	e[++t].v=v;
	e[t].nxt=h[u];
	h[u]=t;
}
void ins(int c,int id)
{
	int p=las,np=++cnt;
	las=cnt;
	len[np]=len[p]+1;
	f[np]=id;
	while(p&&!ch[p][c]) ch[p][c]=np,p=fail[p];
	if(!p) fail[np]=1;
	else
	{
		int q=ch[p][c];
		if(len[p]+1==len[q]) fail[np]=q;
		else
		{
			int nq=++cnt;
			for(int i=0;i<26;i++)
				ch[nq][i]=ch[q][i];
			fail[nq]=fail[q];
			fail[q]=fail[np]=nq;
			len[nq]=len[p]+1;
			while(p&&ch[p][c]==q) ch[p][c]=nq,p=fail[p];
		}
	}
}
bool check(int u,int v)
{
	int p=mn[rt[v]];
	int q=query(rt[u],1,n,p+len[u]-len[v],p);
	//printf("u=%d,v=%d,p=%d,q=%d\n",u,v,p,q);
	return q>=2;
}
int a[400005];
void dfs(int u,int fa,int dep)
{
	int l=1,r=dep-1,mid;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(check(a[mid],u)) l=mid+1;
		else r=mid-1;
	}
	g[u]=a[r];
//	printf("u=%d,l=%d,r=%d,g=%d\n",u,l,r,g[u]);
	a[dep]=u;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs(v,u,dep+1);
	}
}
void dfs2(int u,int fa)
{
	if(f[u])
	{
		rt[u]=modify(rt[u],1,n,f[u]);
	}
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs2(v,u);
		rt[u]=merge(rt[u],rt[v]);
	}
//	printf("u=%d,mn=%d\n",u,mn[rt[u]]);
}
int getdp(int x)
{
	if(!x||x==1) return 0;
	if(dp[x]!=-1) return dp[x];
	//if(x%10000==0) printf("x=%d\n",x);
	return dp[x]=getdp(g[x])+1;
}
int main()
{
	//freopen("CF700E.in","r",stdin);
	memset(dp,-1,sizeof(dp));
	mn[0]=1e9;
	scanf("%d%s",&n,s+1);
	for(int i=1;i<=n;i++)
	{
		ins(s[i]-'a',i);
	//	for(int j=1;j<=cnt;j++)
	//		printf("j=%d,fail=%d\n",j,fail[j]);
	}
	for(int i=2;i<=cnt;i++)
	{
		add(i,fail[i]),add(fail[i],i);
	//	printf("i=%d,fail=%d,len=%d\n",i,fail[i],len[i]);
	}
	dfs2(1,0);
	//printf("cnt=%d,ct=%d\n",cnt,ct);
	dfs(1,0,1);
	int ans=0;
//	printf("---");
	for(int i=1;i<=cnt;i++)
	{
		
		ans=max(ans,getdp(i));
	}
//	printf("---");
	printf("%d",ans);
	return 0;
}