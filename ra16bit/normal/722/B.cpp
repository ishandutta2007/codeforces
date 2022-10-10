#include <bits/stdc++.h>
using namespace std;
int n,i,a[111];
char c;
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) scanf("%d",&a[i]);
  
  for (i=0; i<n; i++) {
    while (c!=10 && c!=13) c=getchar();
    while (true) {
      c=getchar();
      if (c==13 || c==10) break;
      if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='y') a[i]--;
    }
    if (a[i]!=0) { puts("NO"); return 0; }
  }
  puts("YES");
  return 0;
}