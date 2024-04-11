#include <bits/stdc++.h>
using namespace std;
const int md=998244353,MX=1000100;
int n,i,j,la[MX],lb[MX],c[2020][2020],f[2020][2020],ra,rb,res;
long long cur;
char s[MX];
int main() {
  scanf("%s",s+1);
  n=strlen(s+1);
  for (c[0][0]=f[0][0]=i=1; i<=n; i++) {
    la[i]=la[i-1]+int(s[i]=='(');
    lb[i]=lb[i-1]+int(s[i]=='?');
    c[i][0]=f[i][0]=1;
    for (j=i; j>=1; j--) {
      c[i][j]=(c[i-1][j-1]+c[i-1][j])%md;
      f[i][j]=(f[i][j+1]+c[i][j])%md;
    }
    f[i][0]=(f[i][1]+c[i][0])%md;
  }
  for (i=n; i>0; i--) if (s[i]=='?') {
    for (j=ra+1; j<=ra+rb+1; j++) {
      if (la[i-1]+lb[i-1]<j) break;
      cur=c[rb][j-ra-1];
      cur=(cur*f[lb[i-1]][max(0,j-la[i-1])])%md;
      res=(res+cur)%md;
    }
    rb++;
  } else if (s[i]==')') {
    ra++;
    for (j=ra; j<=ra+rb; j++) {
      if (la[i-1]+lb[i-1]<j) break;
      cur=c[rb][j-ra];
      cur=(cur*f[lb[i-1]][max(0,j-la[i-1])])%md;
      res=(res+cur)%md;
    }
  }
  printf("%d\n",res);
  return 0;
}