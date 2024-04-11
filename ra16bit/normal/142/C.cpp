#include <stdio.h>
int n,m,i,j,k,p,x,a[5],l[5],r[5],c[5],res,mx,rk,e,g[10][10][(1<<19)+5];
char f[10][10][(1<<19)+5],s[11][11],ch;
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<n; i++) for (j=0; j<m; j++) s[i][j]='.';
  if (n<3 || m<3) {
    puts("0");
    for (i=0; i<n; i++) puts(s[i]);
    return 0;
  }
  mx=1<<(m+m+1);
  a[0]=(1<<0)+(1<<1)+(1<<2)+(1<<(m+1)); l[0]=1; r[0]=m-2; c[0]=1;
  a[1]=(1<<1)+(1<<(m+1))+(1<<m)+(1<<(m-1)); l[1]=2; r[1]=m-1; c[1]=1;
  a[2]=(1<<(m+m))+(1<<(m+m-1))+(1<<m)+(1<<0); l[2]=2; r[2]=m-1; c[2]=1;
  a[3]=(1<<1)+(1<<(m+1))+(1<<(m+2))+(1<<(m+3)); l[3]=0; r[3]=m-3; c[3]=1;
  a[4]=0; l[4]=0; r[4]=m-1; c[4]=0;
  f[0][0][mx-1]=1;
  for (i=0; i<n; i++) for (j=0; j<m; j++) for (k=0; k<mx; k++) if (f[i][j][k]) {
    for (p=0; p<5; p++) if (j>=l[p] && j<=r[p] && (k&a[p])==0) {
      if (j==m-1) {
        x=(((k|a[p]|(mx*c[p]))>>1)|1);
        if (f[i][j][k]+c[p]>f[i+1][0][x]) {
          f[i+1][0][x]=f[i][j][k]+c[p];
          g[i+1][0][x]=(k<<3)+p;
        }
      } else {
        x=(k|a[p]|(mx*c[p]))>>1;
        if (f[i][j][k]+c[p]>f[i][j+1][x]) {
          f[i][j+1][x]=f[i][j][k]+c[p];
          g[i][j+1][x]=(k<<3)+p;
        }
      }
    }
  }
  for (k=0; k<mx; k++) if (f[n][0][k]>res) { res=f[n][0][k]; rk=k; }
  printf("%d\n",res-1);
  ch='A'+res-2;
  for (i=n, j=0, k=rk; f[i][j][k]>1; k=rk) {
    e=(g[i][j][k]&7);
    rk=g[i][j][k]>>3;
    if (--j<0) { j=m-1; i--; }
    if (e==0) s[i][j]=s[i-1][j]=s[i-2][j]=s[i-2][j-1]=s[i-2][j+1]=ch--; else
    if (e==1) s[i][j]=s[i-1][j]=s[i-2][j]=s[i-1][j-1]=s[i-1][j-2]=ch--; else
    if (e==2) s[i][j]=s[i][j-1]=s[i][j-2]=s[i-1][j-1]=s[i-2][j-1]=ch--; else
    if (e==3) s[i][j]=s[i-1][j]=s[i-2][j]=s[i-1][j+2]=s[i-1][j+1]=ch--;
  }
  for (i=0; i<n; i++) puts(s[i]);
  return 0;
}