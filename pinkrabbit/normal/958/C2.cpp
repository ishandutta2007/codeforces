#include<cstdio>
#include<cstring>
#include<algorithm>
#define MN 20005
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
int n,K,p,f[2][55][105],ans,now=1,lst,i;
ll sum[MN];
int main(){
	scanf("%d%d%d",&n,&K,&p);int x;
	for(i=1;i<=n;i++)scanf("%d",&x),sum[i]=sum[i-1]+x;for(i=0;i<=K;i++)for(int j=0;j<p;j++)f[0][i][j]=-inf;f[0][0][0]=0;
	for(now=1,lst=0,i=1;i<n;i++,now^=1,lst^=1){
		for(int j=0;j<=K;j++)for(int k=0;k<p;k++)f[now][j][k]=f[lst][j][k];f[now][0][0]=0;
		for(int j=1;j<=K;j++)
			for(int k=0;k<p;k++)if(f[lst][j-1][k]!=-inf)f[now][j][sum[i]%p]=max(f[now][j][sum[i]%p],f[lst][j-1][k]+(int)(((sum[i]-k)%p+p)%p));
	}for(int i=0;i<p;i++)if(f[lst][K-1][i])ans=max(ans,f[lst][K-1][i]+(int)(((sum[n]-i)%p+p)%p));printf("%d\n",ans);
}