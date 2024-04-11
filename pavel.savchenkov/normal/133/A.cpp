#include <cstdio>
#include <cstring>
using namespace std;

int main() {
 char s[10000];
 gets(s);
 for (int i=0;i<(int)strlen(s);i++)
  if (s[i]=='H'||s[i]=='Q'||s[i]=='9') {puts("YES");return 0;}
 puts("NO");
 return 0;
 }