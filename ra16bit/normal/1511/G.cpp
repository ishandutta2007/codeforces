#include <bits/stdc++.h>
using namespace std;
const int MP=7,MX=200200;
int n,m,q,i,j,x,y,pw,cur,tot,id[MP][(1<<MP)+1],c[MX],s[MX],sc[144][MX];
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<n; i++) {
    scanf("%d",&x);
    c[x]^=1;
  }
  for (i=1; i<=m; i++) s[i]=s[i-1]+c[i];
  for (i=0; i<MP; i++) {
    pw=(1<<i);
    for (j=0; j<pw; j++, cur++) {
      id[i][j]=cur;
      for (x=1; x<=m; x++) sc[cur][x]=sc[cur][x-1]+int((x+2*pw-j)%(2*pw)>=pw)*c[x];
    }
  }
  scanf("%d",&q);
  while (q--) {
    scanf("%d%d",&x,&y);
    bool ok=true;
    tot=s[y]-s[x-1];
    for (i=0; i<MP && ok; i++) {
      pw=(1<<i);
      j=id[i][x%pw];
      cur=sc[j][y]-sc[j][x-1];
      if (x%(2*pw)>=pw) cur=tot-cur;
      if (cur%2) ok=false;
    }
    for (i=MP; ok; i++) {
      pw=(1<<i);
      cur=0;
      j=x-1+pw;
      if (j>y) break;
      while (j<=y) {
        cur-=s[j];        j+=pw;
        cur+=s[min(j,y)]; j+=pw;
      }
      if (cur%2) ok=false;
    }
    putchar(ok?'B':'A');
  }
  return 0;
}