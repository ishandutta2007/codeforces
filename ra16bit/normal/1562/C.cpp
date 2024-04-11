#include <bits/stdc++.h>
using namespace std;
int t,n,i;
char s[100100];
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n);
    scanf("%s",s);
    for (i=n-1; i>=0; i--) if (s[i]=='0') break;
    if (i<0) printf("%d %d %d %d\n",1,n-1,2,n);
     else if (i<n/2) printf("%d %d %d %d\n",i+1,n,i+2,n);
     else printf("%d %d %d %d\n",1,i+1,1,i);
  }
  return 0;
}