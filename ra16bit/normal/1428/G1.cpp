#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("unroll-loops")
using namespace std;
int k,k9,i,n,q,c[6];
long long fc[6],f[6][100100],d[6][9][2];
bool u[6][100100];
long long solve(int l, int n) {
  if (l) {
    if (u[l][n]) return f[l][n];
    u[l][n]=true;
  }
  long long res=0;
  int nxt=(l<5)?n/10:0,cur;
  cur=n-nxt*10;
  for (; nxt>=0 && cur<=k9; nxt--, cur+=10) {
    long long cost=(cur/3LL)*c[l];
    if (l<5) cost+=solve(l+1,nxt);
    res=max(res,cost);
  }
  for (; nxt>=0 && cur<=k9+9; nxt--, cur+=10) {
    int full=cur/9;
    int ost=cur-full*9;
    long long cost=full*fc[l]+d[l][ost][int(k>full+1)];
    if (l<5) cost+=solve(l+1,nxt);
    res=max(res,cost);
  }
  if (l) f[l][n]=res;
  return res;
}
int main() {
  scanf("%d",&k);
  k9=(k-1)*9;
  for (i=0; i<6; i++) {
    scanf("%d",&c[i]);
    d[i][8][1]=2LL*c[i];
    d[i][7][1]=2LL*c[i];
    d[i][6][1]=2LL*c[i];
    d[i][6][0]=2LL*c[i];
    d[i][4][1]=c[i];
    d[i][4][1]=c[i];
    d[i][3][1]=c[i];
    d[i][3][0]=c[i];
    fc[i]=3LL*c[i];
  }
  scanf("%d",&q);
  while (q--) {
    scanf("%d",&n);
    printf("%I64d\n",solve(0,n));
  }
  return 0;
}