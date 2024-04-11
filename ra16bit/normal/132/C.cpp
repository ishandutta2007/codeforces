#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char s[102];
int i,j,k,n,m,fi,fr,r,d,z,q[220*102*52*2];
bool p[220][102][52][2];
inline void add(int i, int j, int k, int d) {
  if (p[k][i][j][d]) return;
  p[k][i][j][d]=true;
  q[fr++]=(k<<17)+(j<<9)+(i<<1)+d;
}
int main() {
  gets(s);
  n=strlen(s);
  scanf("%d",&m);
  p[102][0][0][0]=true; q[0]=102<<17; fi=0; fr=1;
  while (fi<fr) {
    d=q[fi]&1;   q[fi]>>=1;
    i=q[fi]&255; q[fi]>>=8;
    j=q[fi]&255; q[fi]>>=8;
    k=q[fi]&255; fi++;
    if (i==n) {
      if ((j&1)==(m&1)) r=max(r,abs(k-102));
      continue;
    }
    if (s[i]=='F') {
      add(i+1,j,k+(d==1?1:-1),d);
      if (j<m) add(i+1,j+1,k,1-d);
    } else {
      if (j<m) add(i+1,j+1,k+(d==1?1:-1),d);
      add(i+1,j,k,1-d);
    }
  }
  printf("%d\n",r);
  return 0;
}