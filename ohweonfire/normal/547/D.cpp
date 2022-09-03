#include <bits/stdc++.h>
using namespace std;
const int maxn=400005,maxm=1200100;
int head[maxn],nxt[maxm],to[maxm],cnt;
bool ans[maxm],use[maxm],cur;
void addedge(int x,int y)
{
	nxt[cnt]=head[x];
	head[x]=cnt;
	to[cnt]=y;
	cnt++;
	nxt[cnt]=head[y];
	head[y]=cnt;
	to[cnt]=x;
	cnt++;
}
void dfs(int x)
{
	for(int &i=head[x];i!=-1;i=nxt[i])
		if(use[i]==false)
		{
			cur^=1;
			ans[i>>1]=cur;
			use[i]=use[i^1]=true;
			dfs(to[i]);
		}
}
int n,dgr[maxn];
int main()
{
	memset(head,-1,sizeof(head));
	scanf("%d",&n);
	for(int i=1,x,y;i<=n;i++)
	{
		scanf("%d%d",&x,&y);
		addedge(x,y+200000);
		dgr[x]++;
		dgr[y+200000]++;
	}
	for(int i=1;i<=200000;++i)
	{
		if(dgr[i]&1)
		{
			addedge(i,400001);
			dgr[400001]++;
		}
		if(dgr[i+200000]&1)
			addedge(i+200000,400002);
	}
	if(dgr[400001]&1)
		addedge(400001,400002);
	for(int i=1;i<=400002;i++)if(dgr[i]!=0)
	{
		cur=0;
		dfs(i);
	}
	for(int i=0;i<n;i++)putchar("br"[ans[i]]);
	return 0;
}