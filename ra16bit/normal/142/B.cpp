#include <stdio.h>
#include <memory.h>
const int dx[8]={-1,1,-2,2,-1,1,-2,2};
const int dy[8]={-2,-2,-1,-1,2,2,1,1};
int n,m,r,it,i,j,k,x,y,bx[1010][1010],by[1010][1010],u[1010][1010];
bool v[1010][1010];
bool kuhn(int i, int j) {
  if (i==-1) return true;
  if (u[i][j]==it) return false; else u[i][j]=it;
  int x,y,k;
  for (k=0; k<8; k++) {
    x=i+dx[k];
    y=j+dy[k];
    if (x>=0 && x<n && y>=0 && y<m && kuhn(bx[x][y],by[x][y])) {
      bx[x][y]=i;
      by[x][y]=j;
      return true;
    }
  }
  return false;
}
int main() {
  scanf("%d%d",&n,&m);
  if (n>m) { x=n; n=m; m=x; }
  if (n==1) printf("%d\n",m); else if (n>=3 && m>=3) printf("%d\n",(n*m+1)/2); else {
    memset(bx,255,sizeof(bx));
    for (i=0; i<n; i++) for (j=0; j<m; j++) if ((i+j)&1) for (k=0; k<8; k++) {
      x=i+dx[k];
      y=j+dy[k];
      if (x>=0 && x<n && y>=0 && y<m && bx[x][y]==-1) {
        bx[x][y]=i;
        by[x][y]=j;
        v[i][j]=true;
        r++;
        break;
      }
    }
    for (i=0; i<n; i++) for (j=0; j<m; j++) if (((i+j)&1) && !v[i][j]) {
      it++;
      if (kuhn(i,j)) r++;
    } 
    printf("%d\n",n*m-r);
  }
  return 0;
}