#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int n,d0,d1,hd[200001],cnt,fa[200001],siz[200001];
long long d,ans;

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

void Dfs(int x,int y)
{
	if (y&1) d1++; else d0++;
	d+=1ll*y; siz[x]=1;
	for (int i=hd[x]; i; i=e[i].next)
		if (e[i].to!=fa[x]) fa[e[i].to]=x,Dfs(e[i].to,y+1),siz[x]+=siz[e[i].to];
}

void dfs(int x)
{
	ans+=(d+d1)/2ll;
	for (int i=hd[x]; i; i=e[i].next)
		if (e[i].to!=fa[x]) 
		{
			swap(d0,d1);
			d+=1ll*(n-2*siz[e[i].to]);
			dfs(e[i].to);
			d-=1ll*(n-2*siz[e[i].to]);
			swap(d0,d1);
		}
}

int main()
{
	scanf("%d",&n); cnt=0;
	memset(hd,0,sizeof(hd));
	for (int i=1; i<n; i++) scanf("%d%d",&d0,&d1),addedge(d0,d1),addedge(d1,d0);
	d0=d1=0; d=0; fa[1]=0; ans=0;
	Dfs(1,0); dfs(1);
	printf("%I64d\n",ans/2ll);
	return 0;
}