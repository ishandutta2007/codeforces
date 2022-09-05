#include<bits/stdc++.h>
using namespace std;

int n,m,x,y,cnt,hd[400010],sta[400010],tp,ans[200010],d[400010];
struct node{int to,next,la;}e[400010];

void addedge(int x,int y)
{
	e[++cnt]=(node){y,hd[x],0},e[hd[x]].la=cnt,hd[x]=cnt;
	e[++cnt]=(node){x,hd[y],0},e[hd[y]].la=cnt,hd[y]=cnt;
	d[x]++,d[y]++;
}

int rev(int i) {return (i&1)?(i+1):(i-1);}

void del(int x,int i)
{
	d[x]--;
	if (hd[x]==i) hd[x]=e[i].next,e[hd[x]].la=0;
	else e[e[i].next].la=e[i].la,e[e[i].la].next=e[i].next;
}

void dfs(int x,int col)
{
	if (!(d[x]&1)) return;
	int y=e[hd[x]].to;
	ans[hd[x]+1>>1]=col;
	del(y,rev(hd[x])),del(x,hd[x]);
	dfs(y,col^1);
}

void work(int x)
{
	for (int i=hd[x]; i; i=hd[x])
	{
		del(x,i),del(e[i].to,rev(i));
		work(e[i].to),sta[++tp]=i;
	}
}

int main()
{
	n=200000,scanf("%d",&m);
	for (int i=1; i<=m; i++) scanf("%d%d",&x,&y),addedge(x,n+y);
	for (int i=1; i<=(n<<1); i++) if (d[i]&1) dfs(i,0);
	for (int i=1; i<=(n<<1); i++) 
	{
		tp=0,work(i);
		for (int j=1; j<=tp; j++) ans[sta[j]+1>>1]=(j&1);
	}
	for (int i=1; i<=m; i++) putchar(ans[i]?'b':'r');
	return puts(""),0;
}