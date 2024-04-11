#include <cstdio>
#include <cstring>
using namespace std;
int j,last=-1,n;
char s[100100],i;
int main() {
  scanf("%s",&s);
  n=strlen(s);
  for (i='z'; i>='a'; i--) {
    for (j=last+1; j<n; j++) if (s[j]==i) {
      putchar(i);
      last=j;
    }
  }
  return 0;
}