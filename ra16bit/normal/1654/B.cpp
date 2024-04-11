#include <bits/stdc++.h>
using namespace std;
const int MX=200100;
int t,n,i,r,lst[277];
char s[MX];
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%s",s);
    n=strlen(s);
    for (i=0; i<26; i++) lst[i]=-1;
    for (i=0; i<n; i++) lst[s[i]-'a']=i;
    r=n;
    for (i=0; i<26; i++) if (lst[i]!=-1) r=min(r,lst[i]);
    puts(s+r);
  }
  return 0;
}