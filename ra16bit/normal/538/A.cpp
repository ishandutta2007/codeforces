#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
const string st="CODEFORCES";
int n,m,i,j;
char s[111];
int main() {
  scanf("%s",s);
  n=strlen(s);
  m=st.length();
  if (n<m) { puts("NO"); return 0; }
  for (i=0; i<m; i++) if (s[i]!=st[i]) break;
  for (j=0; j<m; j++) if (s[n-j-1]!=st[m-j-1]) break;
  puts((i+j>=m)?"YES":"NO");
  return 0;
}