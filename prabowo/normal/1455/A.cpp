#include <bits/stdc++.h>
using namespace std;
 
const int N = 100005;
 
char s[N];

int solve() {
  scanf("%s", s);
  printf("%d\n", strlen(s));
  return 0;
}
 
int main() {
  int t = 1;
  scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc+1);
    solve();
  }
  return 0;
}