#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct edge
{
	int v,nxt;
}e[2000005];
int n,m,f[1000005],len[1000005],ch[1000005][26],rt[1000005],h[1000005],t;
int sum[10000005],ls[10000005],rs[10000005],las=1,cnt=1,ct,sl,tp;
char s[100005],ss[100005],st[100005];
void add(int u,int v)
{
	//printf("u=%d,v=%d\n",u,v);
	e[++t].v=v;
	e[t].nxt=h[u];
	h[u]=t;
}
void pushup(int x)
{
	sum[x]=sum[ls[x]]+sum[rs[x]];
}
int merge(int x,int y)
{
	if(!x||!y) return x+y;
	int nw=++ct;
	sum[nw]=sum[x]+sum[y];
	ls[nw]=merge(ls[x],ls[y]);
	rs[nw]=merge(rs[x],rs[y]);
	return nw;
}
int query(int x,int l,int r,int ql,int qr)
{
	if(!x) return 0;
	if(l>qr||r<ql) return 0;
	if(l==r) return l;
	int mid=(l+r)/2,q2;
	q2=query(rs[x],mid+1,r,ql,qr);
	if(q2) return q2;
	return query(ls[x],l,mid,ql,qr); 
}
int modify(int x,int l,int r,int qx)
{
	if(l>qx||r<qx) return x;
	if(!x) x=++ct;
	if(l==r)
	{
		sum[x]=1;
		return x;
	}
	int mid=(l+r)/2;
	ls[x]=modify(ls[x],l,mid,qx);
	rs[x]=modify(rs[x],mid+1,r,qx);
	pushup(x);
	return x;
}
void ins(int c)
{
	c-='a';
	int p=las,np=++cnt;
	las=np;
	len[np]=len[p]+1;
	while(p&&!ch[p][c]) ch[p][c]=np,p=f[p];
	if(!p) f[np]=1;
	else
	{
		int q=ch[p][c];
		if(len[q]==len[p]+1) f[np]=q;
		else
		{
			int nq=++cnt;
			for(int i=0;i<26;i++)
				ch[nq][i]=ch[q][i];
			len[nq]=len[p]+1;
			f[nq]=f[q];
			f[q]=f[np]=nq;
			while(p&&ch[p][c]==q) ch[p][c]=nq,p=f[p];
		}
	}
}
void dfs(int u,int fa)
{
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs(v,u);
		rt[u]=merge(rt[u],rt[v]);
	}
}
int getans(int u,int dep,int l,int r,int fl)
{
	//printf("u=%d,dep=%d,l=%d,r=%d,fl=%d\n",u,dep,l,r,fl);
	if(fl) return 1;
	for(int i=max(ss[dep]-'a',0);i<26;i++)
	{
		int v=ch[u][i],qq=query(rt[v],1,n,l,r);
		if(v&&qq&&qq-dep+1>=l)
		{
			//printf("v=%d,i=%d\n",v,i);
			if(getans(v,dep+1,l,r,i>ss[dep]-'a'))
			{
				//printf("i=%d\n",i);
				st[++tp]=i+'a';
				return 1;
			}
		}
	}
	return 0;
}
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++)
	{
		ins(s[i]);
		//printf("i=%d,cnt=%d\n",i,cnt); 
		rt[las]=modify(rt[las],1,n,i);
	}
	for(int i=2;i<=cnt;i++)
		add(i,f[i]),add(f[i],i);
	dfs(1,0);
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		int l,r;
		tp=0;
		scanf("%d%d%s",&l,&r,ss+1);
		sl=strlen(ss+1);
		if(!getans(1,1,l,r,0)) printf("-1\n");
		else
		{
			for(int j=tp;j>0;j--)
				printf("%c",st[j]);
			printf("\n");
		}
	}
	return 0;
}