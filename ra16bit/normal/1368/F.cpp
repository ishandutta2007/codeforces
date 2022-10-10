#include <bits/stdc++.h>
using namespace std;
int n,m,i,j,k,cnt,cur,res,w,st,nxt,it,td[1010];
bool u[1010];
int main() {
  scanf("%d",&n);
  for (w=k=1; k<=n; k++) {
    cur=(n+k-1)/k+k-1;
    if (k==1 || cur<res) { res=cur; w=k; }
  }
  while (true) {
    cnt=0; ++it;
    for (i=0; i<n; i++) if (!u[i]) ++cnt;
    if (res>=cnt) { puts("0"); break; }
    if (cnt<2) continue;
    for (cur=w, i=0; i<n && cur>0; i+=w) {
      nxt=min(n,i+w);
      st=(m+i)%n;
      for (j=i; j+1<nxt && cur>0; j++, st++) {
        if (st>=n) st=0;
        if (!u[st]) { td[st]=it; --cur; }
      }
    }
    printf("%d",w);
    for (i=0; i<n; i++) if (td[i]==it) {
      printf(" %d",i+1);
      u[i]=true;
    }
    puts("");
    fflush(stdout);
    //for (i=0; i<n; i++) printf("%d",u[i]); puts("");
    scanf("%d",&m);
    if (m==-1) break;
    --m;
    for (i=0, j=m; i<w; i++, j++) {
      if (j>=n) j=0;
      u[j]=false;
    }
    //for (i=0; i<n; i++) printf("%d",u[i]); puts("");
  }
  return 0;
}