#include <stdio.h>
const int MX=2000020;
int n,i,j,k,x,a,s[MX];
int main() {
  scanf("%d%d",&n,&k);
  for (i=0; i<n; i++) { scanf("%d",&a); s[a]++; }
  for (i=1; i<MX; i++) s[i]+=s[i-1];
  for (i=MX-1; i>=1; i--) {
    for (x=0, j=i; j+k<MX && j+i<MX; j+=i) {
      if (k<i) x+=s[j+k]; else x+=s[j+i-1];
      x-=s[j-1];
    }
    if (x==n) { printf("%d\n",i); break; }
  }
  return 0;
}