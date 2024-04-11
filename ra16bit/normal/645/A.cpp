#include <cstdio>
#include <string>
using namespace std;
int i;
string s[2],t[2];
char st[4];
int main() {
  for (i=0; i<2; i++) { scanf("%s",st); s[i]=st; }
  for (i=0; i<2; i++) { scanf("%s",st); t[i]=st; }
  for (i=0; i<100; i++) {
    if (s[0]==t[0] && s[1]==t[1]) break;
    if (s[0][0]=='X') swap(s[0][0],s[0][1]); else if (s[0][1]=='X') swap(s[0][1],s[1][1]);
      else if (s[1][0]=='X') swap(s[1][0],s[0][0]); else swap(s[1][1],s[1][0]);
  }
  puts((i<100)?"YES":"NO");
  return 0;
}