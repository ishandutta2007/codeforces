#include<bits/stdc++.h>
using namespace std;

const int mod=998244353;
int n,x,y,hd[200010],f[200010][4],cnt,fi,tn,t[200010],pre[3][200010],suf[3][200010];
struct node{int to,next;}e[400010];

//0:not taken 1:taken by son and earlier than father 2:taken by son and later than father 3:taken by father

void dfs(int x,int fa,int fi)
{
	for (int i=hd[x]; i; i=e[i].next)
		if (e[i].to!=fa) dfs(e[i].to,x,i);
	tn=0;
	for (int i=hd[x]; i; i=e[i].next)
		if (e[i].to!=fa) t[++tn]=i;
	sort(t+1,t+1+tn);
	pre[0][0]=pre[1][0]=pre[2][0]=1;
	for (int y,i=1; i<=tn; i++)
	{
		y=e[t[i]].to;
		pre[0][i]=1ll*pre[0][i-1]*(f[y][1]+f[y][3])%mod;
		pre[1][i]=1ll*pre[1][i-1]*(f[y][0]+f[y][2])%mod;
		pre[2][i]=1ll*pre[2][i-1]*(f[y][0]+1ll*f[y][1]+f[y][2])%mod;
	}
	suf[0][tn+1]=suf[1][tn+1]=suf[2][tn+1]=1;
	for (int i=tn,y; i; i--)
	{
		y=e[t[i]].to;
		suf[0][i]=1ll*suf[0][i+1]*(f[y][1]+f[y][3])%mod;
		suf[1][i]=1ll*suf[1][i+1]*(f[y][0]+f[y][2])%mod;
		suf[2][i]=1ll*suf[2][i+1]*(f[y][0]+1ll*f[y][1]+f[y][2])%mod;
	}
	f[x][0]=pre[0][tn],f[x][1]=f[x][2]=0;
	for (int i=1; i<=tn; i++)
		f[x][1+(t[i]>fi)]=(f[x][1+(t[i]>fi)]+1ll*(f[e[t[i]].to][0]+f[e[t[i]].to][2])*pre[0][i-1]%mod*suf[2][i+1])%mod;
	t[0]=-1,t[tn+1]=11451411;
	for (int i=0; i<=tn; i++)
		if (t[i]<fi&&t[i+1]>fi) f[x][3]=1ll*pre[0][i]*suf[2][i+1]%mod;
}

//f[x][0]=Pi f[son][3]+f[son][1]
//f[x][1]=(f[son][0]+f[son][2])*(f[early][1]+f[early][3])*(f[later][0]+f[later][1]+f[later][2])
//f[x][2]=(f[son][0]+f[son][2])*(f[early][1]+f[early][3])*(f[later][0]+f[later][1]+f[later][2])
//f[x][3]=(f[early][1]+f[early][3])*(f[later][0]+f[later][1]+f[later][2])

int main()
{
	scanf("%d",&n);
	for (int i=1; i<n; i++)
	{
		scanf("%d%d",&x,&y);
		e[++cnt]=(node){y,hd[x]},hd[x]=cnt;
		e[++cnt]=(node){x,hd[y]},hd[y]=cnt;
	}
	dfs(1,0,0),printf("%d\n",(f[1][0]+1ll*f[1][1]+f[1][2])%mod);
	return 0;
}