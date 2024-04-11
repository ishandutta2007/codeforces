#include<cstdio>
#include<cstring>

int n,m,hd[1000001],cnt,x,y,d[1000001],fi,Hd[1000001],ans[1000001],t[21],tn;
int bo[1000001];
bool b[1000001];

struct node
{
	int to,next;
}e[2000001];

void addedge(int x,int y)
{
	e[++cnt].next=hd[x];
	hd[x]=cnt;
	e[cnt].to=y;
}

int read()
{
	int p=0; char c=getchar();
	while (c>'9'||c<'0') c=getchar();
	while (c>='0'&&c<='9') p=p*10+c-48,c=getchar();
	return p;
}

void work()
{
	while (bo[fi]&&fi<=n) fi++;
	if (fi>n) return;
	int x=fi; bo[x]++; b[x]=1;
	for (int i=hd[x]; i; i=e[i].next) bo[e[i].to]++;
	work();
	if (bo[x]!=1) 
	{
		b[x]=0,bo[x]--;
		for (int i=hd[x]; i; i=e[i].next) bo[e[i].to]--;
	}
}

void print(int x)
{
	tn=0;
	while (x) t[++tn]=x%10,x/=10;
	for (int i=tn; i; i--) putchar(t[i]+48);
	putchar(' ');
}

int main()
{
	n=read(); m=read();
	for (int i=1; i<=m; i++) x=read(),y=read(),addedge(x,y),d[y]++;
	memset(bo,0,sizeof(bo));
	memset(b,0,sizeof(b));
	fi=1; work(); ans[0]=0;
	for (int i=1; i<=n; i++)
		if (b[i]) ans[++ans[0]]=i;
	printf("%d\n",ans[0]);
	for (int i=1; i<=ans[0]; i++) print(ans[i]);
	printf("\n");
	return 0;
}