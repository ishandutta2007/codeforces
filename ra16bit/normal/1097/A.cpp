#include <bits/stdc++.h>
using namespace std;
int i,j;
char s[7][7];
int main() {
  for (i=0; i<6; i++) scanf("%s",s[i]);
  for (i=0; i<2; i++) for (j=1; j<6; j++) if (s[j][i]==s[0][i]) {
    puts("YES");
    return 0;
  }
  puts("NO");
  return 0;
}