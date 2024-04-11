#include <bits/stdc++.h>
using namespace std;
int t,n,i,j,k,r;
char s[700700];
bool a,b;
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n);
    scanf("%s",s);
    a=b=false;
    for (i=0; i<n; i++) if (s[i]=='>') a=true; else if (s[i]=='<') b=true;
    if (!a || !b) { printf("%d\n",n); continue; }
    for (i=0; i<n; i++) s[n+i]=s[i];
    for (i=0; i<n; i++) if (s[i]!='-') break;
    for (r=j=0; j<n; j=k) {
      for (k=j; k<n && s[i+j]==s[i+k]; k++);
      if (s[i+j]=='-') r+=k-j+1;
    }
    printf("%d\n",r);
  }
  return 0;
}