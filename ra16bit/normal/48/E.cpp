#include <stdio.h>
int h,t,r,n,m,i,j,k,x,y,fi,fr,qx[222222],qy[222222],a1[444],a2[444],b1[444],b2[444],f[444][444],c[444][444];
bool q;
void rec(int x, int y) {
  if (x+y==0) { c[x][y]=1; f[x][y]=0; }
  if (x+y>r) { c[x][y]=2; f[x][y]=0; }
  if (c[x][y]==4) q=true;
  if (c[x][y]!=0) return;
  int i,j,k;
  c[x][y]=4;
  for (i=1; i<=x && i<=n; i++) {
    j=x-i+a1[i-1]; k=y+a2[i-1]; rec(j,k);
    if (c[j][k]==1) {
      if (c[x][y]!=1) {
        c[x][y]=1; f[x][y]=f[j][k]+1;
      } else if (f[j][k]+1<f[x][y]) f[x][y]=f[j][k]+1;
    } else if (c[j][k]==2 && c[x][y]==4 && f[j][k]+1>f[x][y]) f[x][y]=f[j][k]+1;
  }
  for (i=1; i<=y && i<=m; i++) {
    j=x+b1[i-1]; k=y-i+b2[i-1]; rec(j,k);
    if (c[j][k]==1) {
      if (c[x][y]!=1) {
        c[x][y]=1; f[x][y]=f[j][k]+1;
      } else if (f[j][k]+1<f[x][y]) f[x][y]=f[j][k]+1;
    } else if (c[j][k]==2 && c[x][y]==4 && f[j][k]+1>f[x][y]) f[x][y]=f[j][k]+1;
  }
  if (c[x][y]==4) c[x][y]=2;
}
int main() {
  scanf("%d%d%d%d",&h,&t,&r,&n);
  for (i=0; i<n; i++) scanf("%d%d",&a1[i],&a2[i]);
  scanf("%d",&m);
  for (i=0; i<m; i++) scanf("%d%d",&b1[i],&b2[i]);
  c[0][0]=fr=1; f[0][0]=qx[0]=qy[0]=fi=0;
  while (fi<fr) {
    x=qx[fi]; y=qy[fi++];
    if (x+y>r) continue;
    if (h==x && t==y) {
      puts("Ivan");
      printf("%d\n",f[h][t]);
      return 0;
    }
    for (i=0; i<n; i++) if (x>=a1[i] && y>=a2[i]) {
      j=x-a1[i]+i+1; k=y-a2[i];
      if (c[j][k]==0) { c[j][k]=1; f[j][k]=f[x][y]+1; qx[fr]=j; qy[fr++]=k; }
    }
    for (i=0; i<m; i++) if (x>=b1[i] && y>=b2[i]) {
      j=x-b1[i]; k=y-b2[i]+i+1;
      if (c[j][k]==0) { c[j][k]=1; f[j][k]=f[x][y]+1; qx[fr]=j; qy[fr++]=k; }
    }
  }
  rec(h,t);
  if (c[h][t]==1) {
    puts("Ivan");
    printf("%d\n",f[h][t]);
  } else if (!q) {
    puts("Zmey");
    printf("%d\n",f[h][t]);
  } else puts("Draw");
  return 0;
}