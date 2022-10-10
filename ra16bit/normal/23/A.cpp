#include <cstdio>
#include <string.h>
using namespace std;
int n,i,l,j,d;
char s[110];
bool q;
int main() {
  gets(s); n=strlen(s);
  for (l=n-1; l>=1; l--) {
    for (i=0; i+l<=n; i++) for (j=i+1; j+l<=n; j++) {
      q=true;
      for (d=0; d<l; d++) if (s[i+d]!=s[j+d]) { q=false; break; }
      if (q) {
        printf("%d\n",d);
        return 0;
      }
    }
  }
  puts("0");
  return 0;
}