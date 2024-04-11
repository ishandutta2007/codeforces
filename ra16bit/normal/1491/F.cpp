#include <bits/stdc++.h>
using namespace std;
int t,n,m,i,j,x,y,pos[2020];
int solve(int i) {
  int le=1,ri=i-1;
  while (le<ri) {
    int h=(le+ri)/2;
    printf("? %d %d\n",h-le+1,1);
    for (int j=le; j<=h; j++) printf("%d%c",j,(j==h)?'\n':' ');
    printf("%d\n",i);
    fflush(stdout);
    int ans;
    scanf("%d",&ans);
    if (ans==0) le=h+1; else ri=h;
  }
  return ri;
}
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n);
    for (i=2; i<=n; i++) {
      printf("? %d %d\n",i-1,1);
      for (j=1; j<i; j++) printf("%d%c",j,(j+1==i)?'\n':' ');
      printf("%d\n",i);
      fflush(stdout);
      scanf("%d",&x);
      if (x!=0) break;
    }
    y=solve(i);
    for (m=0, j=i+1; j<=n; j++) {
      printf("? %d %d\n",1,1);
      printf("%d\n",i);
      printf("%d\n",j);
      fflush(stdout);
      scanf("%d",&x);
      if (x==0) pos[m++]=j;
    }
    printf("! %d",m+i-2);
    for (j=1; j<i; j++) if (j!=y) printf(" %d",j);
    for (j=0; j<m; j++) printf(" %d",pos[j]);
    putchar('\n');
    fflush(stdout);
  }
  return 0;
}