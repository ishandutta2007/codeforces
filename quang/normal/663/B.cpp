#include <bits/stdc++.h>

using namespace std;

int n;
char s[100];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%s", s);
    int sz = strlen(s);
    int low = 1988;
    int p = 1;
    int curVal = 0;
    for (int i = sz - 1; i >= 4; i--) {
      curVal += (s[i] - '0') * p;
      p *= 10;
      int cur = curVal;
      while (cur <= low) {
        cur += p;
      }
      low = cur;
    }
    cout << low << endl;
  }
  return 0;
}