#include <bits/stdc++.h>
using namespace std;
int i,j,k,n;
char s[5050],a[5050];
int main() {
  scanf("%s",s);
  n=strlen(s);
  for (i=0; i<n; i++) if (s[i]!=s[0]) break;
  if (i>=n || (n%2==1 && i==n/2)) { puts("Impossible"); return 0; }
  for (i=1; i<n; i++) {
    for (k=0, j=i; j<n; j++, k++) a[k]=s[j];
    for (j=0; j<i; j++, k++) a[k]=s[j];
    for (j=0; j<n-1-j; j++) if (a[j]!=a[n-1-j]) break;
    if (j>=n-1-j) {
      for (j=0; j<n; j++) if (a[j]!=s[j]) break;
      if (j<n) { puts("1"); return 0; }
    }
  }
  puts("2");
  return 0;
}