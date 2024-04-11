#include<cstdio>
#include<cstring>

struct node
{
	int to,next;
}e[400001];

bool bo[200001];
int fa[200001],n,x,y,cnt,col[200001],l[200001],last,head[200001];

int read()
{
	int pjy=0; char ch=getchar();
	while (ch>'9'||ch<'0') ch=getchar();
	while (ch>='0'&&ch<='9') pjy=pjy*10+ch-48,ch=getchar();
	return pjy;
}

void addedge(int x,int y)
{
	e[++cnt].next=head[x]; head[x]=cnt;
	e[cnt].to=y;
}

void dfs(int x)
{
	for (int i=head[x]; i; i=e[i].next)
		if (e[i].to!=fa[x])
		{
			fa[e[i].to]=x;
			dfs(e[i].to);
		}
}

void dfs2(int x)
{
	l[0]=2;
	bo[col[x]]=1; bo[col[fa[x]]]=1;
	l[1]=col[x]; l[2]=col[fa[x]]; last=1;
	for (int i=head[x]; i; i=e[i].next)
		if (e[i].to!=fa[x])
		{
			while (bo[last]) last++;
			col[e[i].to]=last; bo[last]=1; l[++l[0]]=last;
		}
	for (int i=1; i<=l[0]; i++) bo[l[i]]=0;
	for (int i=head[x]; i; i=e[i].next)
		if (e[i].to!=fa[x]) dfs2(e[i].to);
}

int main()
{
	memset(head,0,sizeof(head));
	n=read(); cnt=0;
	for (int i=1; i<n; i++)
	{
		x=read(); y=read();
		addedge(x,y); addedge(y,x);
	}
	fa[1]=1; col[1]=1;
	dfs(1);
	dfs2(1);
	int max=0;
	for (int i=1; i<=n; i++) if (col[i]>max) max=col[i];
	printf("%d\n",max);
	for (int i=1; i<=n; i++) printf("%d ",col[i]);
	return 0;
}