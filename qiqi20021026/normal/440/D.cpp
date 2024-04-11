#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

#define N 600
#define INF 0x3f3f3f3f

int n,m,x,y,ans,tot,ans1,ans2,f[N][N],g[N][N],h[N][N],head[N],size[N],DP[N][N],zy[N][N],ss[N][N],edg[N][N];
struct edge{int v,nxt,i;}e[N];

void add(int x,int y,int i){e[++tot].v=y; e[tot].i=i; e[tot].nxt=head[x]; head[x]=tot;}

void dp(int u,int fa,int ID){
	size[u]=1; memset(f[u],INF,sizeof f[u]); f[u][1]=0;
	for (int i=head[u],v;i;i=e[i].nxt)
		if ((v=e[i].v)!=fa){
			dp(v,u,i); size[u]+=size[v];
			for (int j=size[u];j>=1;j--){
				int mn=f[u][j]+1;
				for (int k=1;k<=size[v] && k<j;k++)
					mn=min(mn,f[u][j-k]+f[v][k]);
				f[u][j]=mn;
			}
		}
	f[u][0]=1;
	if (size[u]>=m && ans>(u==1?f[u][m]:f[u][m]+1)){
		ans=u==1?f[u][m]:f[u][m]+1;
		ans1=u; ans2=ID;
	}
}

void out(int u,int w,int fa){
	memset(DP,INF,sizeof DP); DP[0][1]=0;
	int j=0;
	for (int i=head[u],v;i;i=e[i].nxt)
		if ((v=e[i].v)!=fa){
			j++;
			for (int k=0;k<=size[v];k++)
				for (int l=w;l-k>=1;l--)
					if (DP[j][l]>DP[j-1][l-k]+f[v][k]){
						DP[j][l]=DP[j-1][l-k]+f[v][k];
						zy[j][l]=k; edg[u][j]=i;
					}
		}
	for (int i=j;i>=1;i--){
		ss[u][i]=zy[i][w];
		w-=zy[i][w];
	}
	for (int i=1;i<=j;i++)
		if (ss[u][i]==0) printf("%d ",e[edg[u][i]].i);
		else out(e[edg[u][i]].v,ss[u][i],u);
}

int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<n;i++){scanf("%d%d",&x,&y); add(x,y,i); add(y,x,i);}
	ans=INF; dp(1,0,0);
	printf("%d\n",ans);
	if (ans2!=0) printf("%d ",e[ans2].i);
	out(ans1,m,e[((ans2-1)^1)+1].v);
}