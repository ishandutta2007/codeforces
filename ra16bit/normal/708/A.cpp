#include <bits/stdc++.h>
using namespace std;
char s[100100];
int i;
int main() {
  scanf("%s",s);
  for (i=0; s[i]; i++) if (s[i]!='a') break;
  if (s[i]) for (; s[i]!=0 && s[i]!='a'; i++) s[i]--; else s[i-1]='z';
  puts(s);
  return 0;
}