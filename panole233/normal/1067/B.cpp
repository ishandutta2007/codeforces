#include<cstdio>
#include<cstring>
#include<cstdlib>

int n,k,dep[100001],sd[100001],x,y,hd[100001],cnt,fa[100001],q[100001],la[100001],l,r,Q[100001],Qn,rt;

struct node
{
	int to,next;
}e[200001];

void addedge(int x,int y)
{
	e[++cnt].next=hd[x];
	hd[x]=cnt;
	e[cnt].to=y;
}

void dfs(int x)
{
	sd[x]=0;
	for (int i=hd[x]; i; i=e[i].next)
		if (e[i].to!=fa[x]) fa[e[i].to]=x,sd[x]++,dep[e[i].to]=dep[x]+1,dfs(e[i].to);
	if (!sd[x]) {if (dep[x]!=k) {puts("No"); exit(0);}}
	else {if (sd[x]<3) {puts("No"); exit(0);}}
}

int main()
{
	scanf("%d%d",&n,&k); cnt=0;
	memset(hd,0,sizeof(hd));
	for (int i=1; i<n; i++) scanf("%d%d",&x,&y),addedge(x,y),addedge(y,x);
	l=r=1; q[1]=1;
	memset(la,0,sizeof(la));
	while (l<=r)
	{
		x=q[l];
		for (int i=hd[x]; i; i=e[i].next)
			if (e[i].to!=la[x]) la[e[i].to]=x,q[++r]=e[i].to;
		l++;
	}
	q[1]=q[n]; l=r=1;
	memset(la,0,sizeof(la));
	while (l<=r)
	{
		x=q[l];
		for (int i=hd[x]; i; i=e[i].next)
			if (e[i].to!=la[x]) la[e[i].to]=x,q[++r]=e[i].to;
		l++;
	}
	x=q[n]; Q[++Qn]=x;
	while (x!=q[1]) x=la[x],Q[++Qn]=x;
	rt=Q[Qn+1>>1];
	memset(fa,0,sizeof(fa));
	dep[rt]=0; dfs(rt); puts("Yes");
	return 0;
}