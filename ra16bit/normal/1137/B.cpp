#include <bits/stdc++.h>
using namespace std;
int n,m,i,j,z,st,c[2],d[2],p[500500];
char s[500500],t[500500];
int main() {
  scanf("%s",s); n=strlen(s);
  scanf("%s",t); m=strlen(t);
  for (i=0; i<n; i++) c[s[i]-'0']++;
  for (i=0; i<m; i++) c[t[i]-'0']--;
  if (m>n || c[0]<0 || c[1]<0) { puts(s); return 0; }
  for (i=1; i<m; i++) {
    while (j>0 && t[i]!=t[j]) j=p[j-1];
    if (t[i]==t[j]) j++;
    p[i]=j;
  }
  st=p[m-1]; z=m-st;
  for (i=st; i<m; i++) d[t[i]-'0']++;
  while (m<n) {
    if (m+z<=n && d[0]<=c[0] && d[1]<=c[1]) {
      c[0]-=d[0];
      c[1]-=d[1];
      for (i=0; i<z; i++) t[m+i]=t[st+i];
      m+=z;
    } else for (j=0; j<2; j++) {
      for (i=0; i<c[j]; i++) t[m+i]='0'+j;
      m+=c[j];
    }
  }
  puts(t);
  return 0;
}