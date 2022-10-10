#include <bits/stdc++.h>
using namespace std;
const int MX=1000100;
int n,i,mn,mx,b[MX],e[MX];
int main() {
  scanf("%d",&n);
  if (n<=3) { printf("%d\n",int(n!=3)); return 0; }
  for (i=1; i<=n; i++) b[i]=b[i/2]+1;
  mn=(1<<(b[n]-2));
  mx=(1<<(b[n]-1))-1;
  for (i=1; i<mn; i++) if (i&1) ++mx; else {
    e[i]=e[i/2]+1;
    if (e[i]%2==0) ++mx;
  }
  printf("%d\n",int(n==mx || n==mx+1));
  return 0;
}