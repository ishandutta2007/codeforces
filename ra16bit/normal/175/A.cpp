#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int a,b,c,i,j,k,n,r=-1;
char s[33];
int main() {
  scanf("%s",s);
  n=strlen(s);
  for (i=0; i<n-2 && i<7; i++) {
    a=a*10+s[i]-'0'; b=0;
    if (a<=1000000) for (j=i+1; j<n-1 && j<i+8; j++) {
      b=b*10+s[j]-'0'; c=0;
      if (b<=1000000) {
        for (k=j+1; ; k++) {
          c=c*10+s[k]-'0';
          if (k==n-1 || c>=1000000 || s[j+1]=='0') break;
        }
        if (k==n-1 && c<=1000000) r=max(r,a+b+c);
      }
      if (s[i+1]=='0') break;
    }
    if (s[0]=='0') break;
  }
  printf("%d\n",r);
  return 0;
}