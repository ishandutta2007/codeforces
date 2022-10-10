#include <stdio.h>
#include <string.h>
#include <memory.h>
int i,j,i1,i2,k,n,m,a,b,c,r,f[2][55][55][55][8],md=51123987;
char s[200];
int abs(int x) { return (x<0)?(-x):x; }
int main() {
  scanf("%d",&n); gets(s);
  gets(s); m=0;
  for (i=1; i<n; i++) if (s[i]!=s[m]) s[++m]=s[i];
  f[0][0][0][0][0]=1;
  for (i=0; i<=m; i++) {
    i1=(i&1); i2=1-i1;
    for (a=0; a<=n; a++) {
      if ((a-1)*3>n) break;
      for (b=0; a+b<=n; b++) {
        if ((b-1)*3>n) break;
        for (c=0; a+b+c<=n; c++) if ((c-1)*3<=n) for (k=0; k<8; k++) {
          if (k==0) for (int l=0; l<8; l++) f[i2][a][b][c][l]=0;
          if (f[i1][a][b][c][k]==0) continue;
          int kk=k|(1<<(s[i]-'a'));
          f[i2][a][b][c][kk]+=f[i1][a][b][c][k];
          if (f[i2][a][b][c][kk]>md) f[i2][a][b][c][kk]-=md;
          if (a+b+c<n && (k&(1<<(s[i]-'a')))==0) {
            if (s[i]=='a') {
              f[i1][a+1][b][c][0]+=f[i1][a][b][c][k];
              if (f[i1][a+1][b][c][0]>md) f[i1][a+1][b][c][0]-=md;
            } else if (s[i]=='b') {
              f[i1][a][b+1][c][0]+=f[i1][a][b][c][k];
              if (f[i1][a][b+1][c][0]>md) f[i1][a][b+1][c][0]-=md;
            } else {
              f[i1][a][b][c+1][0]+=f[i1][a][b][c][k];
              if (f[i1][a][b][c+1][0]>md) f[i1][a][b][c+1][0]-=md;
            }
          }
        }
      }
    }
  }
  i2=((m+1)&1); r=0;
  for (a=0; a<=n; a++) for (b=0; a+b<=n; b++) if (abs(a-b)<2) {
    c=n-a-b;
    if (abs(a-c)<2 && abs(b-c)<2) for (k=0; k<8; k++) {
      r+=f[i2][a][b][c][k];
      if (r>md) r-=md;
    }
  }
  printf("%d\n",r);
  return 0;
}