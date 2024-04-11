#include<bits/stdc++.h>
using namespace std;

pair<int,int> ans[1000010];
int lim,ansn,n,hd[100010],x,y,cnt,d[100010];
struct node{int to,next;}e[200010];

void dfs(int x,int fa,int nw)
{
	ans[++ansn]=make_pair(x,nw);
	if (d[x]==1) {ans[++ansn]=make_pair(x,nw-1); return;}
	int L=lim-d[x]; bool bo=0;
	for (int i=hd[x],j=nw+1; i; i=e[i].next) if (e[i].to!=fa)
	{
		if (j==lim+1) ans[++ansn]=make_pair(x,L),j=L+1,bo=1;
		dfs(e[i].to,x,j),ans[++ansn]=make_pair(x,j),j++;
	}
	if (!bo) ans[++ansn]=make_pair(x,nw-1);
}

int main()
{
	scanf("%d",&n);
	for (int i=1; i<n; i++)
	{
		scanf("%d%d",&x,&y);
		e[++cnt]=(node){y,hd[x]},hd[x]=cnt;
		e[++cnt]=(node){x,hd[y]},hd[y]=cnt;
		d[x]++,d[y]++;
	}
	lim=0;
	for (int i=1; i<=n; i++) lim=max(lim,d[i]);
	ans[ansn=1]=make_pair(1,0);
	for (int i=hd[1],j=1; i; i=e[i].next,j++) dfs(e[i].to,1,j),ans[++ansn]=make_pair(1,j);
	printf("%d\n",ansn);
	for (int i=1; i<=ansn; i++) printf("%d %d\n",ans[i].first,ans[i].second);
	return 0;
}