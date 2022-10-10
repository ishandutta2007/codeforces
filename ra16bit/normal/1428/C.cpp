#include <bits/stdc++.h>
using namespace std;
int t,n,i,top;
char s[200200];
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%s",s);
    n=strlen(s);
    for (top=i=0; i<n; i++) {
      if (s[i]=='B' && top>0) --top; else ++top;
    }
    printf("%d\n",top);
  }
  return 0;
}