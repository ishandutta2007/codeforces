#include <bits/stdc++.h>
using namespace std;
int n,m,i,j,c,ans,l[500100],r[500100];
char s[500100];
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%s",s);
    m=strlen(s);
    for (j=c=0; j<m; j++) {
      if (s[j]=='(') c++; else c--;
      if (c<0) break;
    }
    if (c>=0) l[c]++;
    for (j=m-1, c=0; j>=0; j--) {
      if (s[j]==')') c++; else c--;
      if (c<0) break;
    }
    if (c>=0) r[c]++;
  }
  ans=l[0]/2;
  for (i=1; i<500100; i++) ans+=min(l[i],r[i]);
  printf("%d\n",ans);
  return 0;
}