#include <bits/stdc++.h>
using namespace std;
int t,n,i,r;
char s[44],z[44];
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n);
    scanf("%s",s);
    for (i=0; i<n; i++) z[i]=s[i];
    sort(z,z+n);
    for (r=i=0; i<n; i++) if (s[i]!=z[i]) ++r;
    printf("%d\n",r);
  }
  return 0;
}