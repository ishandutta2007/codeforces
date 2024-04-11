#include <bits/stdc++.h>
using namespace std;
int a[4],i,j,s;
int main() {
  for (i=0; i<4; i++) {
    scanf("%d",&a[i]);
    s+=a[i];
  }
  for (i=0; i<4; i++) {
    if (a[i]==s-a[i]) { puts("YES"); return 0; }
    for (j=i+1; j<4; j++) if (a[i]+a[j]==s-a[i]-a[j]) { puts("YES"); return 0; }
  }
  puts("NO");
  return 0;
}