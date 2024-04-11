#include <stdio.h>
const int pp=6;
const int dx[pp]={0,0,0,0,-1,1};
const int dy[pp]={1,0,-1,0,0,0};
const int dz[pp]={0,1,0,-1,0,0};
int k,n,m,i,j,p,e,x,y,z,fi,fr,qx[1111],qy[1111],qz[1111];
char s[12][12][12];
bool a[12][12][12];
int main() {
  scanf("%d%d%d",&k,&n,&m);
  for (i=1; i<=k; i++) for (j=1; j<=n; j++) scanf("%s",s[i][j]+1);
  scanf("%d%d",&qy[0],&qz[0]);
  qx[0]=fr=1;
  a[1][qy[0]][qz[0]]=true;
  while (fi<fr) {
    x=qx[fi]; y=qy[fi]; z=qz[fi++];
    for (p=0; p<pp; p++) {
      i=x+dx[p];
      j=y+dy[p];
      e=z+dz[p];
      if (s[i][j][e]=='.' && (!a[i][j][e])) {
        a[i][j][e]=true;
        qx[fr]=i; qy[fr]=j; qz[fr++]=e;
      }
    }
  }
  printf("%d\n",fr);
  return 0;
}