#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
struct BUN_T{
  int a,b,c,d;
};
int main(){
  int n,m,c,d,mat[12][1001],i,j,k;
  BUN_T bun[11];
  cin>>n>>m>>c>>d;
  bun[0].a=1;
  bun[0].b=0;
  bun[0].c=c;
  bun[0].d=d;
  for(i=1;i<=m;i++){
    cin>>bun[i].a>>bun[i].b>>bun[i].c>>bun[i].d;
  }
  memset(mat,0,sizeof(mat));
  for(j=0;j<m+1;j++){
    for(i=0;i<=n;i++){
      if(bun[j].b*i>bun[j].a)break;
      for(k=bun[j].c*i;k<=n;k++){
	mat[j+1][k]=max(max(mat[j][k],mat[j][k-bun[j].c*i]+bun[j].d*i),mat[j+1][k]);
      }
    }
  }
  cout<<mat[m+1][n]<<endl;
  return 0;
}