#include <bits/stdc++.h>
using namespace std;
int t,n,m,i,j,x,y,ins,rst,w,best,cur,r,p[222],pos[222];
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d%d",&n,&m);
    for (i=1; i<=2*n; i++) p[i]=0;
    for (i=0; i<m; i++) {
      scanf("%d%d",&x,&y);
      p[x]=y;
      p[y]=x;
    }
    rst=0;
    for (i=1; i<=2*n; i++) if (p[i]==0) pos[rst++]=i;
    rst/=2;
    for (i=0; i<rst; i++) {
      p[pos[i]]=pos[i+rst];
      p[pos[i+rst]]=pos[i];
    }
    r=0;
    for (i=1; i<=2*n; i++) if (p[i]>i) {
      cur=0;
      for (j=i+1; j<p[i]; j++) if (p[j]!=0 && (p[j]<i || p[j]>p[i])) ++cur;
      r+=cur;
    }
    printf("%d\n",r/2);
  }
  return 0;
}