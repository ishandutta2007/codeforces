#include <stdio.h>
#include <string.h>
const int MX=1000010;
int n,i,p;
bool z[MX],e[MX],f[MX][2][2];
char s[MX];
int solve() {
  int j,k,l;
  if (s[i]=='0') {
    f[++p][0][0]=true;
	z[p]=false;
	e[p]=false;
    i++;
	return p;
  }
  if (s[i]=='1') {
    f[++p][1][1]=true;
	z[p]=true;
	e[p]=true;
    i++;
	return p;
  }
  if (s[i]=='?') {
    p++;
	f[p][0][1]=true;
	f[p][1][0]=true;
	z[p]=false;
	e[p]=true;
    i++;
	return p;
  }
  i++;
  int fi,se,x,y;
  fi=solve();
  char ch=s[i++];
  se=solve();
  p++;
  if (ch=='&') {
    z[p]=z[fi]&z[se];
	e[p]=e[fi]&e[se];
    for (j=0; j<2; j++) for (k=0; k<2; k++) if (f[fi][j][k])
	  for (x=0; x<2; x++) for (y=0; y<2; y++) if (f[se][x][y]) f[p][j&x][k&y]=true;
  } else if (ch=='|') {
    z[p]=z[fi]|z[se];
	e[p]=e[fi]|e[se];
    for (j=0; j<2; j++) for (k=0; k<2; k++) if (f[fi][j][k])
	  for (x=0; x<2; x++) for (y=0; y<2; y++) if (f[se][x][y]) f[p][j|x][k|y]=true;
  } else {
    z[p]=z[fi]^z[se];
	e[p]=e[fi]^e[se];
    for (j=0; j<2; j++) for (k=0; k<2; k++) if (f[fi][j][k])
	  for (x=0; x<2; x++) for (y=0; y<2; y++) if (f[se][x][y]) f[p][j^x][k^y]=true;
  }
  i++;
  return p;
}
int main() {
  scanf("%d",&n);
  scanf("%s",s);
  n=strlen(s);
  solve();
  puts(((z[p]!=e[p])|f[p][0][1]|f[p][1][0])?"YES":"NO");
  return 0;
}