#include <cstdio>
#include <cstring>
#include <memory.h>
using namespace std;
int a,n,i,r;
char s[110];
int main() {
  while (gets(s)) {
    n=strlen(s);
    if (n==0) break;
    if (s[0]=='+') a++; else if (s[0]=='-') a--; else {
      for (i=0; i<n; i++) if (s[i]==':') { r+=(n-i-1)*a; break; }
    }
    memset(s,0,sizeof(s));
  }
  printf("%d\n",r);
  return 0;
}