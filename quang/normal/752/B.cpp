#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

char s[N], t[N];
int n;
char used[N];

int main() {
  scanf("%s", s + 1);
  scanf("%s", t + 1);
  n = strlen(s + 1);
  for (int i = 1; i <= n; i++) {
    if (!used[s[i]] && !used[t[i]]) {
      used[s[i]] = t[i];
      used[t[i]] = s[i];
    } else {
      if (used[s[i]] != t[i] || used[t[i]] != s[i]) {
        cout << -1;
        return 0;
      }
    }
  }
  int res = 0;
  for (char i = 'a'; i <= 'z'; i++) {
    if (used[i] && used[i] != i) {
      res++;
    }
  }
  res /= 2;
  cout << res << endl;
  for (char i = 'a'; i <= 'z'; i++) {
    if (used[i] && used[i] != i) {
      cout << i << " " << used[i] << endl;
      used[used[i]] = 0;
    }
  }
  return 0;
}