#include <bits/stdc++.h>
using namespace std;
int n,md,i,ii,i1,j,k,lst,cur,sc[2],s[2][405][405][2],step2[405][405],r;
long long lft,rgh;
void add(int& f, int x) {
  f+=x;
  if (f>=md) f-=md;
}
int main() {
  scanf("%d%d",&n,&md);
  for (i=1; i<=n; i++) {
    ii=(i&1); i1=1-ii;
    memset(s[i1],0,sizeof(s[i1]));
    for (j=1; j<=i; j++) {
      sc[0]=0;
      sc[1]=step2[i][j];
      for (lst=1; lst<=j; lst++) for (k=0; k<2; k++) {
        add(sc[k],s[ii][j][lst][k]);
        if (i>1) cur=sc[k]; else cur=int(j==1 && lst==1 && k==1);
        if (cur==0) continue;
        if (i<n) {
          add(step2[i+2][j+1],cur);
          add(s[i1][j+1][lst+1][0],cur);
          if (k==1) {
            add(s[i1][j+1][1][1],cur);
            add(s[i1][j+1][lst+1][1],(md-cur)%md);
          }
        } else add(r,cur);
      }
    }
  }
  printf("%d\n",r);
  return 0;
}