#include <stdio.h>
const int dx[8]={-1,1,-2,2,-1,1,-2,2};
const int dy[8]={2,2,-1,-1,-2,-2,1,1};
int m,x,y,i,j,k,fi,fr,qx[3100000],qy[3100000],p[2200][2200],md=1000000007;
long long n,w[1100];
int main() {
  scanf("%I64d%d",&n,&m);
  for (i=0; i<m; i++) {
    scanf("%d%d",&x,&y);
    p[x+1100][y+1100]=-1;
  }
  qx[0]=qy[0]=1100;
  p[1100][1100]=fr=1;
  while (fi<fr) {
    x=qx[fi]; y=qy[fi++];
    if (p[x][y]>401) break; else w[p[x][y]]++;
    for (k=0; k<8; k++) {
      i=x+dx[k];
      j=y+dy[k];
      if (p[i][j]==0) {
        p[i][j]=p[x][y]+1;
        qx[fr]=i; qy[fr++]=j;
      }
    }
  }
  for (i=1; i<=401; i++) w[i]+=w[i-1];
  if (n<400) printf("%I64d\n",w[n+1]); else if (w[400]==w[100]) printf("%I64d\n",w[400]); 
    else printf("%I64d\n",(w[400]+((14*((n-400)%md)+(w[401]-w[400])%md)%md)*((n-399)%md))%md);
  return 0;
}