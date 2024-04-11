#include <stdio.h>
#include <string.h>
const int z[4]={0,1,10,11};
int i,n,a,b,x,y;
char s[100100];
bool u[4];
int main() {
  gets(s); n=strlen(s);
  for (i=0; i<n; i++) if (s[i]=='1') a++; else if (s[i]=='0') b++;
  y=(n-2)/2; x=n-2-y;
  if (x>=a) u[0]=true;
  if (y>=b) u[3]=true;
  if (a<=x+1 && b<=y+1) {
    if (s[n-1]=='1' || (s[n-1]=='?' && a<=x)) u[1]=true;
    if (s[n-1]=='0' || (s[n-1]=='?' && b<=y)) u[2]=true;
  }
  for (i=0; i<4; i++) if (u[i]) printf("%02d\n",z[i]);
  return 0;
}