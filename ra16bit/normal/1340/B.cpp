#include <bits/stdc++.h>
using namespace std;
const string d[10]={"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
int n,m,i,j,k,cur,c[2020][11];
bool f[2020][2020];
char s[11];
int main() {
  scanf("%d%d",&n,&m);
  for (i=1; i<=n; i++) {
    scanf("%s",&s);
    for (j=0; j<10; j++) for (k=0; k<7; k++) {
      if (s[k]=='1' && d[j][k]=='0') { c[i][j]=-1; break; }
      c[i][j]+=int(s[k]=='0' && d[j][k]=='1');
    }
  }
  f[n][0]=true;
  for (i=n; i>0; i--) for (j=0; j<10; j++) if (c[i][j]!=-1) {
    cur=m-c[i][j];
    for (k=0; k<=cur; k++) if (f[i][k]) f[i-1][k+c[i][j]]=true;
  }
  if (f[0][m]) {
    for (i=0; i<n; i++) for (j=9; j>=0; j--) {
      cur=c[i+1][j];
      if (cur!=-1 && m>=cur && f[i+1][m-cur]) {
        printf("%d",j);
        m-=cur;
        break;
      }
    }
  } else puts("-1");
  return 0;
}