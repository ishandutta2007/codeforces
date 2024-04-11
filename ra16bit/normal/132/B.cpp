#include <stdio.h>
#include <string.h>
int n,m,N,ii,i,j,k,d,x,y,p[2555][8],qi[22222],qd[22222],nx[2555],mx[2555],ny[2555],my[2555],a[55][55];
char s[55][55];
int main() {
  scanf("%d%d",&n,&N);
  for (i=0; i<n; i++) scanf("%s",s[i]);
  m=strlen(s[0]);
  for (i=0; i<n; i++) for (j=0; j<m; j++) {
    if (i>0 && s[i-1][j]==s[i][j]) a[i][j]=a[i-1][j];
    if (j>0 && s[i][j-1]==s[i][j]) a[i][j]=a[i][j-1];
    if (a[i][j]==0) {
      a[i][j]=++k;
      nx[a[i][j]]=i; ny[a[i][j]]=j;
      mx[a[i][j]]=i; my[a[i][j]]=j;
    } else {
      if (i<nx[a[i][j]]) nx[a[i][j]]=i;
      if (i>mx[a[i][j]]) mx[a[i][j]]=i;
      if (j<ny[a[i][j]]) ny[a[i][j]]=j;
      if (j>my[a[i][j]]) my[a[i][j]]=j;
    }
  }
  i=a[0][0]; d=0;
  for (ii=1; ii<=N; ii++) {
    /*if (p[i][d]>0) {
      j=(N+1)%(ii-1);
      if (j==0) j=ii-1;
      printf("%c\n",s[mx[qi[j]]][my[qi[j]]]);
      return 0;
    } else {
      p[i][d]=ii;
      qi[ii]=i;
      qd[ii]=d;
    }*/
    if (d<2) {
      y=my[i]+1;
      if (d&1) x=mx[i]; else x=nx[i];
    } else if (d<4) {
      x=mx[i]+1;
      if (d&1) y=ny[i]; else y=my[i];
    } else if (d<6) {
      y=ny[i]-1;
      if (d&1) x=nx[i]; else x=mx[i];
    } else {
      x=nx[i]-1;
      if (d&1) y=my[i]; else y=ny[i];
    }
    if (x>=0 && y>=0 && x<n && y<m && s[x][y]!='0') i=a[x][y]; else d=(d+1)&7;
  }
  printf("%c\n",s[mx[i]][my[i]]);
  return 0;
}