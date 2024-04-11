#include<bits/stdc++.h>
using namespace std;

int n,m,hd[100010],x,y,cnt,sta[600010],tp,d[100010],la;
struct node{int to,next,la,fro;}e[600010];

void addedge(int x,int y)
{
	e[++cnt]=(node){y,hd[x],0,x},e[hd[x]].la=cnt,hd[x]=cnt;
	e[++cnt]=(node){x,hd[y],0,y},e[hd[y]].la=cnt,hd[y]=cnt;
	d[x]++,d[y]++;
}

int rev(int i) {return (i&1)?(i+1):(i-1);}

void del(int x,int i)
{
	if (hd[x]==i) hd[x]=e[i].next,e[hd[x]].la=0; else
	e[e[i].next].la=e[i].la,e[e[i].la].next=e[i].next;
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
	scanf("%d%d",&n,&m),cnt=0,memset(hd,0,sizeof(hd)),la=0;
	for (int i=1; i<=m; i++) scanf("%d%d",&x,&y),addedge(x,y);
	for (int x=1; x<=n; x++)
		if (d[x]&1) {if (!la) la=x; else addedge(la,x),la=0;}
	for (int x=1; x<=n; x++)
		if ((d[x]>>1)&1) {if (!la) la=x; else la=0;}
	if (la) addedge(la,la);
	work(1),la=0,printf("%d\n",tp);
	for (int i=tp; i; i--)
	{
		if ((d[e[sta[i]].fro]>>1)&1)
		{
			if (la) d[la]+=2,d[e[sta[i]].fro]+=2,la=0;
			else la=e[sta[i]].fro;
		}
		if (la) printf("%d %d\n",e[sta[i]].to,e[sta[i]].fro); 
		else printf("%d %d\n",e[sta[i]].fro,e[sta[i]].to);
	}
	return 0;
}