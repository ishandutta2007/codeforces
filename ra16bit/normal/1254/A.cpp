#include <bits/stdc++.h>
using namespace std;
int t,n,m,k,cnt,b,fi,chid,cur,nd,i,j;
char ch,s[111][111],r[111][111];
void process() {
  if (s[i][j]=='R') cur++;
  if (cur>nd) {
    if (ch=='9') ch='a'; else if (ch=='z') ch='A'; else ch++;
    cur=1; chid++;
    nd=b+int(fi>chid);
  }
  r[i][j]=ch;
}
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d%d%d",&n,&m,&k);
    for (cnt=i=0; i<n; i++) {
      scanf("%s",s[i]);
      for (j=0; j<m; j++) if (s[i][j]=='R') cnt++;
    }
    b=cnt/k; fi=cnt%k; ch='0';
    nd=b+int(fi>0);
    for (chid=cur=i=0; i<n; i++) if (i&1) {
      for (j=m-1; j>=0; j--) process();
      r[i][m]=0;
    } else {
      for (j=0; j<m; j++) process();
      r[i][m]=0;
    }
    for (i=0; i<n; i++) puts(r[i]);
  }
  return 0;
}