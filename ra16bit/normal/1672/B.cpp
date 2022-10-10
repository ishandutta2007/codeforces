#include <bits/stdc++.h>
using namespace std;
const int MX=200100;
int t,n,i,cnt;
char s[MX];
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%s",s);
    n=strlen(s);
    if (s[n-1]!='B') { puts("NO"); continue; }
    for (cnt=i=0; i<n; i++) if (s[i]=='A') ++cnt; else {
      if (cnt<=0) break;
      --cnt;
    }
    if (i<n) puts("NO"); else puts("YES");
  }
  return 0;
}