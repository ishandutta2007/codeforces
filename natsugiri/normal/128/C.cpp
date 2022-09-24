#include<cstdio>

typedef long long LL;

#define MOD 1000000007

int C[1010][1010];
int n,m,k;

LL calc(int x){
  if(x<0)return 0;
  if(x<k*2-1)return 0;
  if(x<k*2)return C[x][k*2-1];
  return ((LL)C[x][k*2]+C[x][k*2-1])%MOD;
}

int main(){
  C[0][0]=1;
  for(int i=1;i<1010;i++){
    C[i][0]=1;
    for(int j=1;j<=i;j++)
      C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD;
  }
  
  scanf("%d%d%d",&n,&m,&k);
  printf("%d\n",(int)(calc(n-2)*calc(m-2)%MOD));
  return 0;
}