#include <bits/stdc++.h>
using namespace std;
int t,n,i,j,x,y,cur,res,a[5],b[5];
char s[444][444];
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n);
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    for (i=0; i<n; i++) {
      scanf("%s",s[i]);
      for (j=0; j<n; j++) {
        if (s[i][j]=='X') ++a[(i+j)%3];
        if (s[i][j]=='O') ++b[(i+j)%3];
      }
    }
    res=a[0]+b[1];
    x=0; y=1;
    for (i=0; i<3; i++) for (j=0; j<3; j++) if (i!=j) {
      cur=a[i]+b[j];
      if (cur<res) { res=cur; x=i; y=j; }
    }
    for (i=0; i<n; i++) for (j=0; j<n; j++) {
      if ((i+j)%3==x && s[i][j]=='X') s[i][j]='O';
      if ((i+j)%3==y && s[i][j]=='O') s[i][j]='X';
    }
    for (i=0; i<n; i++) puts(s[i]);
  }
  return 0;
}