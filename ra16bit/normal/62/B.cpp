#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m,k,i,j,c,d,l[111111][26],r[111111][26];
char s[111111],t[222222];
long long z;
int main() {
  scanf("%d%d",&k,&n);
  scanf("%s",t);
  for (i=0; i<n; i++) {
    for (j=0; j<26; j++) l[i][j]=(i==0)?-1:l[i-1][j];
    l[i][t[i]-'a']=i;
  }
  for (i=n-1; i>=0; i--) {
    for (j=0; j<26; j++) r[i][j]=(i==n-1)?n:r[i+1][j];
    r[i][t[i]-'a']=i;
  }
  for (i=0; i<k; i++) {
    scanf("%s",s); m=strlen(s);
    for (z=j=0; j<m; j++) {
      c=s[j]-'a';
      d=1000000000;
      if (l[min(n-1,j)][c]>=0) d=abs(j-l[min(n-1,j)][c]);
      if (r[min(n-1,j)][c]<n) d=min(d,abs(r[min(n-1,j)][c]-j));
      if (d==1000000000) d=m;
      z+=d;
    }
    printf("%I64d\n",z);
  }
  return 0;
}