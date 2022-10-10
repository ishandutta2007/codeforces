#include <bits/stdc++.h>
using namespace std;
int n,i,j,c,d;
char s[1010];
int main() {
  scanf("%s",s);
  n=strlen(s);
  for (i=0; i<=n; i++) {
    for (c=j=0; j<i; j++) if (s[j]=='(') c++;
    for (d=0; j<n; j++) if (s[j]==')') d++;
    if (c==d) {
      if (c==0) { puts("0"); return 0; }
      printf("1\n%d\n",c*2);
      for (j=0; j<i; j++) if (s[j]=='(') printf("%d ",j+1);
      for (; j<n; j++) if (s[j]==')') printf("%d ",j+1);
      break;
    }
  }
  return 0;
}