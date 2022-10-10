#include <cstdio>
#include <string>
using namespace std;
const int dx[8]={-1,-1,-1,0,0,1,1,1};
const int dy[8]={-1,0,1,-1,1,-1,0,1};
const string s[8]={"RU","R","RD","U","D","LU","L","LD"};
int i,j,x,y,k,n,fi,fr,ax,ay,bx,by,qx[70],qy[70],a[10][10],b[10][10];
int main() {
  scanf("%c%d\n",&ax,&ay);  ax=ax-'a'+1;
  scanf("%c%d",&bx,&by);    bx=bx-'a'+1;
  for (i=1; i<=8; i++) for (j=1; j<=8; j++) a[i][j]=1000000;
  qx[0]=bx; qy[0]=by; a[bx][by]=0; fi=0; fr=1;
  while (fi<fr) {
    x=qx[fi]; y=qy[fi++];
    for (k=0; k<8; k++) {
      i=x+dx[k]; j=y+dy[k];
      if (a[i][j]>a[x][y]+1) {
        a[i][j]=a[x][y]+1; b[i][j]=k;
        qx[fr]=i; qy[fr++]=j;
      }
    }
  }
  printf("%d\n",a[ax][ay]);
  while (bx!=ax || by!=ay) {
    k=b[ax][ay];
    puts(s[k].c_str());
    ax-=dx[k]; ay-=dy[k];
  }
  return 0;
}