#include <stdio.h>
const int CP=310;
int x,y,n,m,q,p,X[101004][14],Y[101004][14];
char s[100004][14],t[4];
void fill(int p) {
  for (int i=p; i<p+CP && i<=n; i++) {
    if (s[i][1]=='<') {
      X[i][1]=i;
      Y[i][1]=0;
    }
    if (s[i][m]=='>') {
      X[i][m]=i;
      Y[i][m]=m+1;
    }
    for (int j=1; j<=m; j++) {
      if (s[i][j]=='^') {
        if (i==p) {
          X[i][j]=i-1;
          Y[i][j]=j;
        } else {
          X[i][j]=X[i-1][j];
          Y[i][j]=Y[i-1][j];
        }
      } else if (j>1 && s[i][j]=='<') {
        if (s[i][j-1]=='>') {
          X[i][j-1]=-1; X[i][j]=-1;
          Y[i][j-1]=-1; Y[i][j]=-1;
        } else {
          X[i][j]=X[i][j-1];
          Y[i][j]=Y[i][j-1];
        }
      }
    }
    for (int j=m-1; j>0; j--) if (s[i][j]=='>' && s[i][j+1]!='<') {
      X[i][j]=X[i][j+1];
      Y[i][j]=Y[i][j+1];
    }
  }
}
int main() {
  scanf("%d%d%d",&n,&m,&q);
  for (int i=1; i<=n; i++) scanf("%s",s[i]+1);
  for (p=1; p<=n; p+=CP) fill(p);
  while (q--) {
    scanf("%s",t);
    scanf("%d%d",&x,&y);
    if (t[0]=='A') {
      while (x>0 && y>0 && x<=n && y<=m && (X[x][y]!=x || Y[x][y]!=y)) {
        p=x;
        x=X[x][y];
        y=Y[p][y];
      }
      printf("%d %d\n",x,y);
    } else {
      scanf("%s",t);
      s[x][y]=t[0];
      p=((x-1)/CP)*CP+1;
      for (int i=0; i<CP; i++) for (int j=1; j<=m; j++) {
        X[p+i][j]=0;
        Y[p+i][j]=0;
      }
      fill(p);
    }
  }
  return 0;
}