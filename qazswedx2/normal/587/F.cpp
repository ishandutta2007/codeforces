#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
typedef long long ll;
struct pt
{
	int l,r,id;
	pt(int l=0,int r=0,int id=0):l(l),r(r),id(id){}
};
struct qt
{
	int x,id,fl,qid;
	qt(int x=0,int id=0,int fl=0,int qid=0):x(x),id(id),fl(fl),qid(qid){}
	bool operator<(const qt q) const
	{
		return x<q.x;
	}
}p[500005];
struct edge
{
	int v,nxt;
}e[2000005];
int n,m,sn,ch[500005][26],fail[500005],ct=1,q[500005],head,tail,a[100005];
int vis[500005],len[100005],t,h[500005],tot,dfn[500005],sz[500005],cnt;
char *s[100005],buf[1000005],*pb=buf;
int b[500005],fir[500005],ft,lazy[500005],sum[500005];
vector<pt> val[100005];
ll qans[500005],c[100005];
void add(int u,int v)
{
	e[++tot].v=v;
	e[tot].nxt=h[u];
	h[u]=tot;
}
int ins(char *s)
{
	int p=1;
	for(int i=0;s[i];i++)
	{
		int c=s[i]-'a';
		if(!ch[p][c]) ch[p][c]=++ct;
		p=ch[p][c];
	}
	return p;
}
void build()
{
	for(int i=0;i<26;i++)
		ch[0][i]=1;
	fail[1]=0;
	head=0,tail=1;
	q[1]=1;
	while(head<tail)
	{
		head++;
		int u=q[head];
		for(int i=0;i<26;i++)
			if(ch[u][i])
			{
				fail[ch[u][i]]=ch[fail[u]][i];
				q[++tail]=ch[u][i];
			}
			else ch[u][i]=ch[fail[u]][i];
	}
}
void dfs(int u,int fa)
{
	dfn[u]=++cnt;
	sz[u]=1;
//	printf("dfs:u=%d,fa=%d,dfn=%d\n",u,fa,dfn[u]);
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		dfs(v,u);
		sz[u]+=sz[v];
	}
}
void modify(int l,int r)
{
//	printf("modify:l=%d,r=%d,b=%d,%d\n",l,r,b[l],b[r]);
	if(b[l]==b[r])
	{
		for(int i=l;i<=r;i++)
			sum[i]++;
		return;
	}
	for(int i=l;i<fir[b[l]+1];i++)
		sum[i]++;
	for(int i=fir[b[r]];i<=r;i++)
		sum[i]++;
	for(int i=b[l]+1;i<b[r];i++)
		lazy[i]++;
}
inline int query(int x)
{
	return sum[x]+lazy[b[x]];
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		s[i]=pb;
		scanf("%s",s[i]);
		len[i]=strlen(s[i]);
		pb+=len[i]+1;
		a[i]=ins(s[i]);
	}
	build();
	sn=316;
//	sn=1;
	for(int i=1;i<=m;i++)
	{
		int l,r,k;
		scanf("%d%d%d",&l,&r,&k);
		if(len[k]<sn)
		{
			p[++t]=qt(l-1,k,-1,i);
			p[++t]=qt(r,k,1,i);
		}
		else val[k].push_back(pt(l,r,i));
	}
	for(int i=1;i<=n;i++)
	{
		int len=strlen(s[i]);
		if(len>=sn)
		{
			int p=1;
			for(int j=1;j<=ct;j++)
				vis[j]=0;
			for(int j=0;s[i][j];j++)
			{
				int c=s[i][j]-'a';
				p=ch[p][c];
				vis[p]++;
			}
			for(int j=tail;j>1;j--)
				vis[fail[q[j]]]+=vis[q[j]];
			for(int j=1;j<=n;j++)
				c[j]=vis[a[j]];
			for(int j=1;j<=n;j++)
				c[j]+=c[j-1];
			int sz=val[i].size();
			for(int j=0;j<sz;j++)
			{
				pt u=val[i][j];
				qans[u.id]=c[u.r]-c[u.l-1];
			}
		}
	}
	for(int i=2;i<=ct;i++)
	{
		add(fail[i],i);
	//	printf("i=%d,fail=%d\n",i,fail[i]);
	}
	dfs(1,0);
	for(int i=1;i<=ct;i++)
	{
		b[i]=(i-1)/sn+1;
		if(!fir[b[i]]) fir[b[i]]=i,ft++;
	}
//	printf("---\n");
	fir[ft+1]=ct+1;
	sort(p+1,p+t+1);
//	printf("---\n");
	int nw=1;
	while(nw<=t&&p[nw].x==0) nw++;
	for(int i=1;i<=n;i++)
	{
	//	printf("i=%d,a=%d\n",i,a[i]);
		modify(dfn[a[i]],dfn[a[i]]+sz[a[i]]-1);
		while(nw<=t&&p[nw].x==i)
		{
			ll nans=0;
			int u=p[nw].id,x=1;
			for(int j=0;s[u][j];j++)
			{
				x=ch[x][s[u][j]-'a'];
			//	printf("i=%d,u=%d,s=%c,x=%d\n",i,u,s[u][j],x);
				nans+=query(dfn[x]);
			}
		//	printf("nans=%lld\n",nans);
			qans[p[nw].qid]+=p[nw].fl*nans;
			nw++;
		}
	}
	for(int i=1;i<=m;i++)
		printf("%lld\n",qans[i]);
	return 0;
}