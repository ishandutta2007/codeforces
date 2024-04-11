#include <stdio.h>
const int dx[9]={0,-1,-1,1,1,-2,-2,2,2};
const int dy[9]={0,2,-2,2,-2,1,-1,1,-1};
int t,n;
bool a[22][22];
int rec(int l) {
  int i,j,k,x,y,z=1;
  for (i=0; i<n && z==1; i++) for (j=0; j<n && z==1; j++) {
    for (k=0; k<9; k++) {
      x=i+dx[k];
      y=j+dy[k];
      if (x<0 || y<0 || x>=n || y>=n) continue;
      if (a[x][y]) break;
    }
    if (k==9) {
      a[i][j]=true;
      if (rec(l+1)==1) z=0;
      a[i][j]=false;
    }
  }
  return z;
}
int main() {
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n);
    printf("%d\n",1-(n&1));
  }
  return 0;
}