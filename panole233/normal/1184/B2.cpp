#include<bits/stdc++.h>
using namespace std;

namespace PiPei
{
const int MAXN=1005, INF=0x3f3f3f3f;
int nl, nr, M, now, dis, ans;
int ml[MAXN],mr[MAXN],dl[MAXN],dr[MAXN],vis[MAXN],q[MAXN];
int E[MAXN*MAXN],*hd[MAXN],*tl[MAXN];
int bfs(){
	memset(dl,-1,sizeof(int)*(nl+1));
	memset(dr,-1,sizeof(int)*(nr+1));
	int *ff=q, *rr=q; dis=INF;
	for(int i=1; i<=nl; ++i) if(!ml[i]) dl[i]=0, *rr++=i;
	while(ff<rr){
		int u=*ff++; if(dl[u]>dis) continue;
		for(int *e=hd[u]; e<tl[u]; ++e){
			int v=*e;
			if(dr[v]==-1){
				dr[v]=dl[u]+1;
				if(mr[v])dl[mr[v]]=dr[v]+1,*rr++=mr[v];
				else dis=dr[v];
			}
		}
	}
	return dis<INF;
}
int dfs(int u){
	for(int *e=hd[u]; e<tl[u]; ++e){
		int v=*e;
		if(vis[v]!=now&&dr[v]==dl[u]+1){
			vis[v]=now;
			if(!mr[v]||dfs(mr[v])) return mr[v]=u, ml[u]=v, 1;
		}
	}
	return 0;
}
void addedge(int u,int v)
{
	*tl[u]++=v;
	if(__builtin_expect(ml[u]||mr[v],1));
	else ml[u]=v,mr[v]=u,ans++;
}
void init(int A,int B,int C)
{
	nl=A,nr=B,M=C;
	for(int i=1; i<=nl; ++i) hd[i]=tl[i]=E+(i-1)*nr;
}
int main()
{
	int n=nl<nr?nl:nr;
	while(ans<n&&bfs()){now++;for(int i=1; i<=nl; ++i)if(!ml[i])__builtin_prefetch(E),ans+=dfs(i);}
	return ans;
}
}

int n,m,f[101][101],x,y,S,B,K,H;
struct spaceship{int x,a,f;}s[1010];
struct base{int x,d;}b[1010];

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1; i<=n; i++) 
		for (int j=1; j<=n; j++) f[i][j]=1000000;
	for (int i=1 ;i<=m; i++) scanf("%d%d",&x,&y),f[x][y]=f[y][x]=1;
	for (int k=1; k<=n; k++)
		for (int i=1; i<=n; i++)
			for (int j=1; j<=n; j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	scanf("%d%d%d%d",&S,&B,&K,&H);
	for (int i=1; i<=S; i++) scanf("%d%d%d",&s[i].x,&s[i].a,&s[i].f);
	for (int i=1; i<=B; i++) scanf("%d%d",&b[i].x,&b[i].d);
	int cnt=0;
	for (int i=1; i<=S; i++)
		for (int j=1; j<=B; j++) if (s[i].a>=b[j].d&&f[s[i].x][b[j].x]<=s[i].f) cnt++;
	PiPei::init(S,B,cnt);
	for (int i=1; i<=S; i++)
		for (int j=1; j<=B; j++)
			if (s[i].a>=b[j].d&&f[s[i].x][b[j].x]<=s[i].f) PiPei::addedge(i,j);
	int ans=PiPei::main();
	long long Ans=1ll*ans*K;
	for (int i=1; i<=S; i++)
		Ans=min(1ll*i*H+1ll*min(S-i,ans)*K,Ans);
	printf("%I64d\n",Ans);
	return 0;
}