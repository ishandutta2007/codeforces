#include <bits/stdc++.h>

#define Task "A"
#define fi freopen(Task".inp", "r", stdin)
#define fo freopen(Task".out", "w", stdout)

using namespace std;

char s[30];
int n;

int main() {
   // fi, fo;
  scanf("%s", s);
  n = strlen(s);
  for (int i = 0; i < n; i++) {
    if (s[i] > '4' && (s[i] != '9' || i != 0)) printf("%c", 9 - s[i] + '0' + '0');
      else printf("%c", s[i]);
  }
    return 0;
}