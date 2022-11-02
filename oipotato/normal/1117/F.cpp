#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<iostream>
#include<cassert>
#include<set>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
bool ban[20][20][1<<17],bad[1<<17],vis[1<<17];
int lk[20][20],n,p,a[100010],cnt[20],q[(1<<17)+10],ful;
char s[100010];
int main()
{
	scanf("%d%d",&n,&p);ful=(1<<p)-1;
	scanf("%s",s+1);
	rep(i,n)a[i]=s[i]-'a'+1,cnt[a[i]]++;
	rep(i,p)rep(j,p)scanf("%d",&lk[i][j]);
	rep(i,p)
	{
		int now=0;
		bool flag=0;
		rep(j,n)
		{
			if(flag&&!lk[i][a[j]])ban[i][a[j]][(ful^now)|(1<<(a[j]-1))]=1;
			now|=1<<(a[j]-1);
			if(a[j]==i)now=0,flag=1;
		}
	}
	rep(i,p)rep(j,p)if(!lk[i][j])
	for(int k=ful;k;k--)if(ban[i][j][k])
	for(int x=k,y=x&(-x);x;x-=y,y=x&(-x))if(y!=(1<<(i-1))&&y!=(1<<(j-1)))ban[i][j][k^y]=1;
	rep(i,p)rep(j,p)if(!lk[i][j])rep(k,ful+1)if(ban[i][j][k-1])bad[k-1]=1;
	int w;q[w=1]=ful;vis[ful]=1;
	rep(i,w)
	{
		int u=q[i];
		for(int x=u,y=x&(-x);x;x-=y,y=x&(-x))if(!vis[u^y]&&!bad[u^y])vis[q[++w]=u^y]=1;
	}
	int ans=n;
	rep(i,ful+1)
	if(vis[i-1])
	{
		int tans=0;
		rep(j,p)if((i-1)&(1<<(j-1)))tans+=cnt[j];
		ans=min(ans,tans);
	}
	printf("%d\n",ans);
	return 0;
}