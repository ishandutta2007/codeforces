#include<cstdio>
#include<cstring>
	
struct node
{
	int to,next;
}e[400001];

int n,m,k,a[200001],ans,cnt,head[200001],tot,max,c[200001];
bool b[200001],bb[200001];

int read() 
{
	int pjy=0; char ch=getchar(); 
	while (ch<'0'||ch>'9') ch=getchar(); 
	while (ch>='0'&&ch<='9') pjy=pjy*10+ch-48,ch=getchar(); 
	return pjy;
}

void addedge(int x,int y)
{
	e[++cnt].to=y; 
	e[cnt].next=head[x];
	head[x]=cnt;
}

void dfs(int x)
{
	b[x]=1; c[a[x]]++; 
	if (c[a[x]]>max) max=c[a[x]]; 
	tot++;
	for (int i=head[x]; i; i=e[i].next)
		if (!b[e[i].to]) dfs(e[i].to);
}

void dfss(int x)
{
	bb[x]=1; c[a[x]]--;
	for (int i=head[x]; i; i=e[i].next)
		if (!bb[e[i].to]) dfss(e[i].to);
}

int main()
{
	n=read(); m=read(); k=read();
	for (int i=1; i<=n; i++) a[i]=read();
	int x,y;
	for (int i=1; i<=m; i++) 
	{
		x=read(),y=read();
		addedge(x,y),addedge(y,x);
	}
	for (int i=1; i<=n; i++)
		if (!b[i])
		{
			tot=max=0;
			dfs(i); dfss(i);
			ans+=tot-max;
		}
	printf("%d",ans);
	return 0;
}