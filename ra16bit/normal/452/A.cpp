#include <cstdio>
#include <string>
using namespace std;
const string a[8]={"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};
int n,i,j;
char s[11];
int main() {
  scanf("%d",&n);
  scanf("%s",s);
  for (i=0; i<8; i++) {
    if (a[i].length()!=n) continue;
    for (j=0; j<n; j++) if (s[j]!='.' && s[j]!=a[i][j]) break;
    if (j>=n) { puts(a[i].c_str()); break; }
  }
  return 0;
}