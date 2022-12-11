#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include<bits/stdc++.h>
using namespace std;

int n, a[101000], b[101000], f[101000][4], pre[101000][4], ans[101000];

void dfs(int x,int y){
  if (x) dfs(x-1,pre[x][y]);
  printf("%d ",y);
}

int main(){
  cin>>n;
  for (int i=1;i<n;++i) scanf("%d",&a[i]);
  for (int i=1;i<n;++i) scanf("%d",&b[i]);
  f[0][0]=f[0][1]=f[0][2]=f[0][3]=1;
  for (int i=1;i<n;++i){
    for (int u=0;u<=3;++u)
      for (int v=0;v<=3;++v)
        if (f[i-1][u]&&(u|v)==a[i]&&(u&v)==b[i]){
          f[i][v]=1; pre[i][v]=u;
        }
  }
  for (int i=0;i<=3;++i)
    if (f[n-1][i]){
      puts("YES");
      dfs(n-1,i);
      return 0;
    }
  puts("NO");
}