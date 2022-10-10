#include <bits/stdc++.h>
using namespace std;
int t,n,m,i,j,st,pos,prvpos,ppppos;
vector<int> a[505];
char s[255255];
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d%d",&n,&m);
    for (i=0; i<n; i++) {
      pos=i*(m+1);
      scanf("%s",s+pos);
      a[i].clear();
      for (j=0; j<m; j++) if (s[pos+j]=='X') a[i].push_back(j);
    }
    st=int(n%3!=1);
    for (i=st; i<n; i+=3) {
      pos=i*(m+1);
      for (j=0; j<m; j++) s[pos+j]='X';
      if (i>st) {
        prvpos=pos-(m+1);
        ppppos=prvpos-(m+1);
        for (j=0; j<m; j++) if (s[prvpos+j]=='X' || s[ppppos+j]=='X') {
          s[prvpos+j]='X';
          s[ppppos+j]='X';
          break;
        }
        if (j>=m) {
          s[prvpos]='X';
          s[ppppos]='X';
        }
      }
    }
    for (i=0; i<n; i++) puts(s+i*(m+1));
  }
  return 0;
}