#include <bits/stdc++.h>
using namespace std;
const int MX=150150;
int t,it,n,i,r,u[MX];
char s[MX];
int main() {
  scanf("%d",&t);
  for (it=1; it<=t; it++) {
    scanf("%s",s);
    n=strlen(s); r=0;
    for (i=2; i<n; i++) if (u[i-1]!=it && u[i-2]!=it) {
      if (s[i]=='o' && s[i-1]=='w' && s[i-2]=='t' && s[i+1]=='n') { u[i]=it; r++; } else
      if ((s[i]=='e' && s[i-1]=='n' && s[i-2]=='o') || (s[i]=='o' && s[i-1]=='w' && s[i-2]=='t')) {
        u[i-1]=it; r++;
      }
    }
    printf("%d\n",r);
    for (i=0; i<n; i++) if (u[i]==it) printf("%d ",i+1);
    puts("");
  }
  return 0;
}