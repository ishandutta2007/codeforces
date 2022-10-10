#include <bits/stdc++.h>
using namespace std;
int n,m,a,b,c,i,j,r[100100];
int ask(string q, int x, int y) {
  printf("%s %d %d\n",q.c_str(),x,y);
  fflush(stdout);
  int r;
  scanf("%d",&r);
  return r;
}
int main() {
  scanf("%d%d",&n,&m);
  a=ask("and",1,2);
  b=ask("or",1,2);
  r[1]|=a;
  r[2]|=a;
  b^=a;
  a=ask("and",2,3);
  c=ask("or",2,3);
  for (j=0; j<30; j++) if ((b>>j)&1) {
    if ((a>>j)&1) b^=(1<<j);
    if (((c>>j)&1)==0) {
      r[1]|=(1<<j);
      b^=(1<<j);
    }
  } else if ((c>>j)&1) {
    if (((r[2]>>j)&1)==0) r[3]|=(1<<j);
  }
  r[2]|=a;
  r[3]|=a;
  a=ask("and",1,3);
  c=ask("or",1,3);
  for (j=0; j<30; j++) if (((b>>j)&1) && ((c>>j)&1)==0) r[2]|=(1<<j);
  r[1]|=a;
  r[3]|=a;
  for (i=4; i<=n; i++) {
    r[i]=ask("and",1,i);
    b=ask("or",1,i);
    for (j=0; j<30; j++) if (((b>>j)&1) && ((r[1]>>j)&1)==0) r[i]|=(1<<j);
  }
  sort(r+1,r+n+1);
  printf("finish %d\n",r[m]);
  fflush(stdout);
  return 0;
}