#include <bits/stdc++.h>
using namespace std;

char c[1005];
int n;

int main() {
  scanf("%s",c);
  n = strlen(c);
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      string s = "";
      for (int k = 0; k < n; k++) {
        if (k < i || k > j) {
          s.append(1, c[k]);
        }
      }
      if (s == "CODEFORCES") {
        printf("YES\n");
        return 0;
      }
    }
  }
  printf("NO\n");
}