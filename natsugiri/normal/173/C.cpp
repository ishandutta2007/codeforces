#include<cstdio>

int max(int a,int b){return a<b?b:a;}

int f[501][501];
int g[501][501],h[501][501];
int n,m;


int main(){

  scanf("%d%d",&n,&m);
  for(int j=0;j<n;j++)
    for(int i=0;i<m;i++)
      scanf("%d",&f[j][i]),h[j][i]=f[j][i];

  for(int j=1;j<=n;j++)
    for(int i=1;i<=m;i++)
      g[j][i]=g[j-1][i]+g[j][i-1]-g[j-1][i-1]+f[j-1][i-1];
  

  int ans=-(1<<20);
  for(int k=3; k<=n && k<=m; k+=2)
    for(int j=0;j<=n-k;j++)
      for(int i=0;i<=m-k;i++)
	ans=max(ans,
		h[j][i]=
		g[j+k][i+k]-g[j][i+k]-g[j+k][i]+g[j][i]-h[j+1][i+1]-f[j+1][i]);


	
  printf("%d\n",ans);
  return 0;
}