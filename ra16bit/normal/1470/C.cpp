#include <bits/stdc++.h>
using namespace std;
int n,m,st,i,v,ls,gr,h;
int gcd(int a, int b) { return b?gcd(b,a%b):a; }
int ask(int pos) {
  printf("? %d\n",pos);
  fflush(stdout);
  int ans;
  scanf("%d",&ans);
  return ans;
}
int main() {
  scanf("%d%d",&n,&m);
  for (st=301; ; st--) if (gcd(n,st)==1) break;
  for (i=0; ls==0 || gr==0; i=(i+st)%n) {
    v=ask(i+1);
    if (v<m && ls==0) ls=i+1; 
    if (v>m && gr==0) gr=i+1; 
  }
  if (gr<ls) gr+=n;
  while (ls<gr) {
    h=(ls+gr)/2;
    i=(h-1)%n+1;
    v=ask(i);
    if (v==m) {
      printf("! %d\n",i);
      fflush(stdout);
      return 0;
    }
    if (v<m) ls=h+1; else gr=h;
  }
  printf("! %d\n",gr);
  fflush(stdout);
  return 0;
}