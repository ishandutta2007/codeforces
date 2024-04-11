#include<cstdio>
#include<cstring>

int n,q[200001],l,r,f[200001][19],x,y,hd[200001],la[200001],cnt,len,an[200001][3],num;
bool b[200001];
long long ans,dep[200001],dis1,dis2;

struct node
{
	int to,next;
}e[400001];

void addedge(int x,int y)
{
	e[++cnt].next=hd[x];
	hd[x]=cnt;
	e[cnt].to=y;
}

void dfs(int x)
{
	for (int i=hd[x]; i; i=e[i].next)
		if (e[i].to!=f[x][0])
		{
			f[e[i].to][0]=x; dep[e[i].to]=dep[x]+1;
			dfs(e[i].to);
		}
}

int lca(int x,int y)
{
	if (dep[x]<dep[y]) {int t=x; x=y; y=t;}
	for (int i=18; i>=0; i--)
		if (dep[f[x][i]]>=dep[y]) x=f[x][i];
	if (x==y) return x;
	for (int i=18; i>=0; i--)
		if (f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
	return f[x][0];
}

long long dis(int x,int y) {return dep[x]+dep[y]-2ll*dep[lca(x,y)];}

void Dfs(int x)
{
	for (int i=hd[x]; i; i=e[i].next)
		if (e[i].to!=f[x][0]) Dfs(e[i].to);
	if (!b[x])
	{
		dis1=dis(x,q[1]); dis2=dis(x,q[r]);
		if (dis1>dis2) an[++num][0]=x,an[num][1]=q[1],an[num][2]=x,ans+=dis1;
		else an[++num][0]=x,an[num][1]=q[r],an[num][2]=x,ans+=dis2;
	}
}

int main()
{
	scanf("%d",&n); cnt=0;
	memset(hd,0,sizeof(hd));
	for (int i=1; i<n; i++) scanf("%d%d",&x,&y),addedge(x,y),addedge(y,x);
	memset(b,0,sizeof(b));
	l=r=1; q[1]=1; b[1]=1;
	while (l<=r)
	{
		x=q[l];
		for (int i=hd[x]; i; i=e[i].next)
			if (!b[e[i].to]) q[++r]=e[i].to,b[e[i].to]=1;
		l++;
	}
	memset(b,0,sizeof(b));
	la[q[r]]=0; b[q[r]]=1; q[1]=q[r]; l=r=1; 
	while (l<=r)
	{
		x=q[l];
		for (int i=hd[x]; i; i=e[i].next)
			if (!b[e[i].to]) q[++r]=e[i].to,la[e[i].to]=x,b[e[i].to]=1;
		l++;
	}
	memset(b,0,sizeof(b));
	x=q[r]; len=0;
	while (x!=0) len++,b[x]=1,x=la[x];
	memset(f,0,sizeof(f));
	dep[q[1]]=0; dfs(q[1]);
	for (int j=1; j<=18; j++)
		for (int i=1; i<=n; i++)
			f[i][j]=f[f[i][j-1]][j-1];
	num=0; Dfs(q[1]);
	x=q[r];
	while (x!=q[1]) an[++num][0]=x,an[num][1]=q[1],an[num][2]=x,ans+=len-1,len--,x=la[x];
	printf("%I64d\n",ans);
	for (int i=1; i<=num; i++) printf("%d %d %d\n",an[i][0],an[i][1],an[i][2]);
	return 0;
}