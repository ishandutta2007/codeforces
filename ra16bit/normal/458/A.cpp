#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m,i,j,x;
long double a[100100];
char s[100100],t[100100];
int main() {
  scanf("%s",s); n=strlen(s);
  reverse(s,s+n);
  for (i=0; i<n; i++) a[i]+=s[i]-'0';
  scanf("%s",t); m=strlen(t);
  reverse(t,t+m);
  for (i=0; i<m; i++) a[i]-=t[i]-'0';
  n=max(n,m);
  for (i=n; i>1; i--) if (a[i]!=0) {
    a[i-1]+=a[i];
    a[i-2]+=a[i];
    a[i]=0;
  }
  if (fabs(a[0])<1e-5 && fabs(a[1])<1e-5) puts("="); else
    puts((a[1]*(sqrt(5)+1)>-2*a[0])?">":"<");
  return 0;
}