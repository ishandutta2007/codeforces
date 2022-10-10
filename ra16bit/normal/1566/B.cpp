#include <bits/stdc++.h>
using namespace std;
int t,r,n,i,j;
char s[100100];
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%s",s);
    n=strlen(s);
    for (r=i=0; i<n; i++) if (s[i]=='0') {
      for (j=i; j<n && s[j]=='0'; j++);
      i=j;
      ++r;
    }
    printf("%d\n",min(r,2));
  }
  return 0;
}