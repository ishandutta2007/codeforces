#include <bits/stdc++.h>
using namespace std;
const int MX=1010;
int t,n,m,i,fi,fr,q[MX],dst[MX],cnt[MX];
char s[MX];
void upd(int i, int d) {
  if (d<dst[i]) {
    q[fr++]=i;
    dst[i]=d;
    cnt[i]=1;
  } else if (d==dst[i]) ++cnt[i];
}
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d%d",&n,&m);
    scanf("%s",s);
    for (fi=fr=i=0; i<n; i++) if (s[i]=='1') {
      q[fr++]=i;
      dst[i]=0;
      cnt[i]=1;
    } else {
      dst[i]=m+1;
      cnt[i]=0;
    }
    while (fi<fr) {
      i=q[fi++];
      if (cnt[i]!=1) continue;
      if (i>0) upd(i-1,dst[i]+1);
      if (i+1<n) upd(i+1,dst[i]+1);
    }
    for (i=0; i<n; i++) if (dst[i]<=m && cnt[i]==1) putchar('1'); else putchar('0');
    putchar('\n');
  }
  return 0;
}