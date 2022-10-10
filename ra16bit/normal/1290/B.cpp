#include <bits/stdc++.h>
using namespace std;
const int MX=200200;
int n,q,i,j,x,y,se,st[MX],lst[MX];
char s[MX];
int main() {
  scanf("%s",s+1);
  n=strlen(s+1);
  for (i=1; i<=n; i++) {
    x=s[i]-'a';
    lst[x]=i;
    for (se=-1, j=0; j<26; j++) if (j!=x && (se==-1 || lst[j]>lst[se])) se=j;
    for (j=0; j<26; j++) if (j!=x && j!=se) st[i]=max(st[i],lst[j]);
  }
  scanf("%d",&q);
  while (q--) {
    scanf("%d%d",&x,&y);
    puts((x==y || s[x]!=s[y] || st[y]>=x)?"Yes":"No");
  }
  return 0;
}