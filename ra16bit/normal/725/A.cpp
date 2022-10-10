#include <bits/stdc++.h>
using namespace std;
int n,i,j;
char s[200200];
int main() {
  scanf("%d",&n);
  scanf("%s",s);
  for (i=0; i<n; i++) if (s[i]=='>') break;
  for (j=n-1; j>=0; j--, i++) if (s[j]=='<') break;
  printf("%d\n",i);
  return 0;
}