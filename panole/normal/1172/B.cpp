#include<bits/stdc++.h>
using namespace std;

const int mod=998244353;
struct node{int to,next;}e[400010];
int hd[200010],n,cnt,fa[200010],x,y,f[200010],jc[200010];

void addedge(int x,int y)
{
	e[++cnt]=(node){y,hd[x]},hd[x]=cnt;
	e[++cnt]=(node){x,hd[y]},hd[y]=cnt;
}

void dfs(int x)
{
	int cnt=0; f[x]=1;
	for (int i=hd[x]; i; i=e[i].next)
		if (e[i].to!=fa[x]) fa[e[i].to]=x,dfs(e[i].to),cnt++,f[x]=1ll*f[e[i].to]*f[x]%mod;
	if (x==1) f[x]=1ll*f[x]*jc[cnt]%mod*n%mod; else f[x]=1ll*f[x]*jc[cnt+1]%mod;
}

int main()
{
	jc[0]=1;
	for (int i=1; i<=200002; i++) jc[i]=1ll*jc[i-1]*i%mod;
	scanf("%d",&n),cnt=0;
	for (int i=1; i<n; i++) scanf("%d%d",&x,&y),addedge(x,y);
	dfs(1),printf("%d\n",f[1]);
	return 0;
}