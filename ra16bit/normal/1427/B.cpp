#include <bits/stdc++.h>
using namespace std;
int t,n,m,i,j,r,cur,tot,a[200200];
char s[200200];
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d%d",&n,&m);
    scanf("%s",s);
    tot=0;
    if (s[0]=='W') a[tot++]=0;
    for (r=i=0; i<n; i=j) if (s[i]=='L') {
      for (j=i; j<n && s[j]=='L'; j++);
      a[tot++]=j-i;
    } else {
      r+=1+int(i>0 && s[i-1]=='W');
      j=i+1;
    }
    if (m==0) {
      printf("%d\n",r);
      continue;
    }
    if (tot==1 && a[0]>0) {
      printf("%d\n",(r==0)?(min(m,n)-1)*2+1:(r+min(m,a[0])*2));
      continue;
    }
    if (s[n-1]=='W') a[tot++]=0;
    --tot;
    if (tot==1 && a[0]==0 && a[tot]==0) {
      printf("%d\n",r);
      continue;
    }
    if (tot>1) {
      sort(a+1,a+tot);
      for (i=1; i<tot && m>0; i++) {
        cur=min(m,a[i]);
        r+=cur*2+int(cur==a[i]);
        m-=cur;
      }
    }
    
    cur=min(m,a[0]);
    r+=cur*2;
    m-=cur;
    if (tot>0) {
      cur=min(m,a[tot]);
      r+=cur*2;
      m-=cur;
    }
    printf("%d\n",r);
  }
  return 0;
}