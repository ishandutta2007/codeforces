#include <bits/stdc++.h>
using namespace std;
int fr,i,j,z,n,a[11][11],f[100100][11];
char s[100100],cur;
long long r;
int main() {
  for (z=1, fr=10; z<=11; z++) for (i=0; i<z; i++) {
    a[z%11][i]=fr%11;
    fr++;
  }
  scanf("%s",s);
  n=strlen(s);
  for (i=n-1; i>=0; i--) {
    cur=s[i]=s[i]-'0';
    if (cur==0) continue;
    for (j=i+1; j<n; j++) {
      if (s[j]>=cur) break;
      cur=a[cur][s[j]];
      if (f[j][cur]!=0) {
        f[i][s[i]]=f[j][cur];
        break;
      }
    }
    if (f[i][s[i]]==0) f[i][s[i]]=j;
    r+=f[i][s[i]]-i;
  }
  cout<<r;
  return 0;
}