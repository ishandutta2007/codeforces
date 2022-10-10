#include <bits/stdc++.h>
using namespace std;
const int MX=300300;
int t,n,i,x,l,r,cnt[MX],w[MX];
char res[MX];
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n);
    for (i=1; i<=n; i++) { cnt[i]=0; res[i]='0'; }
    res[n+1]=0;
    for (i=1; i<=n; i++) {
      scanf("%d",&x);
      ++cnt[x];
      w[x]=i;
    }
    if (cnt[1]>0) res[n]='1';
    for (i=1; i<=n; i++) if (cnt[i]!=1) break;
    if (i>n) res[1]='1';
    l=1; r=n;
    for (i=1; i+1<n; i++) {
      if (cnt[i]!=1) break;
      if (w[i]==l) ++l; else if (w[i]==r) --r; else break;
      if (cnt[i+1]>0) res[n-i]='1'; else break;
    }
    puts(res+1);
  }
  return 0;
}