#include <cstdio>
using namespace std;
long long f[40][40];
long long rec(int i, int j) {
  if (j==0) return 0;
  if (i<=1) f[i][j]=1;
  if (f[i][j]!=0) return f[i][j];
  for (int k=0; k<i; k++) f[i][j]+=rec(k,j-1)*rec(i-k-1,j-1);
  return f[i][j];
}
int main() {
  int n,m;
  scanf("%d%d",&n,&m);
  printf("%I64d\n",rec(n,n)-rec(n,m-1));
  return 0;
}