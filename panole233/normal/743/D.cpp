#include<cstdio>
#include<cstring>

int n,head[200001],x,fa[200001],y,ma[200001][2];
long long f[200001],a[200001],max[200001][2],max2[200001],ans;
bool bo[200001],b[200001];

struct node
{
	int next,to;
}e[400001];

void dfs(int x)
{
	f[x]=a[x]; max[x][0]=max[x][1]=-(1e16); ma[x][0]=0; ma[x][1]=-1;
	for (int i=head[x]; i; i=e[i].next)
		if (fa[x]!=e[i].to)
		{
			fa[e[i].to]=x;
			dfs(e[i].to);
			f[x]+=f[e[i].to];
			if (max[e[i].to][0]>=max[x][0])
			{
				max[x][1]=max[x][0]; ma[x][1]=ma[x][0]; 
				max[x][0]=max[e[i].to][0]; ma[x][0]=e[i].to;
			}
			else if (max[e[i].to][0]>max[x][1]) max[x][1]=max[e[i].to][0],ma[x][1]=e[i].to;
			if (f[e[i].to]>max[x][0])
			{
				if (ma[x][0]!=e[i].to) max[x][1]=max[x][0],ma[x][1]=ma[x][0];
				max[x][0]=f[e[i].to]; ma[x][0]=e[i].to;
			}
			else if (f[e[i].to]>max[x][1]&&ma[x][0]!=e[i].to) max[x][1]=f[e[i].to],ma[x][1]=e[i].to; 
		}
	if (max[x][1]==-(1e16)) bo[x]=0; else bo[x]=1;
}

void dfs2(int x)
{
	if (fa[x]!=0)
	{
		if (ma[fa[x]][0]==x) max2[x]=max[fa[x]][1]; else max2[x]=max[fa[x]][0];
		b[x]=b[fa[x]];
		if (bo[fa[x]]) b[x]=1;
		if (max2[x]<max2[fa[x]]) max2[x]=max2[fa[x]];
	}
	for (int i=head[x]; i; i=e[i].next) 
		if (e[i].to!=fa[x]) dfs2(e[i].to);
}

int main()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++) scanf("%I64d",&a[i]);
	int cnt=0;
	memset(head,0,sizeof(head));
	memset(fa,0,sizeof(fa));
	for (int i=1; i<n; i++)
	{
		scanf("%d%d",&x,&y);
		e[++cnt].next=head[x]; head[x]=cnt; e[cnt].to=y;
		e[++cnt].next=head[y]; head[y]=cnt; e[cnt].to=x;
	}
	dfs(1);
	max2[1]=-(1e16);
	dfs2(1);
	ans=-(1e16);
	for (int i=2; i<=n; i++) 
		if (b[i]&&f[i]+max2[i]>ans) ans=f[i]+max2[i];
	if (ans!=-(1e16)) printf("%I64d",ans); else printf("Impossible");
	return 0;
}