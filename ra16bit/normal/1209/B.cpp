#include <bits/stdc++.h>
using namespace std;
int n,i,j,c,r,a[111],b[111];
char s[111];
int main() {
  scanf("%d",&n);
  scanf("%s",s);
  for (j=0; j<n; j++) {
    scanf("%d%d",&a[j],&b[j]);
    s[j]-='0';
  }
  for (i=0; i<200; i++) {
    for (c=j=0; j<n; j++) {
      if (i>=b[j] && i%a[j]==b[j]%a[j]) s[j]^=1;
      c+=s[j];
    }
    r=max(r,c);
  }
  printf("%d\n",r);
  return 0;
}