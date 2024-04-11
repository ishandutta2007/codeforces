#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

void read(string &s) {
  s = "";
  int c = getchar();
  while (c <= 32) c = getchar();
  s = "";
  while (c > 32) s += (char) c, c = getchar();
}

string const DIRS = "DRUL";
int a[1234567];
int q[42];

int main() {
  string s;
  read(s);
  read(s);
  int n = (int) s.length();
  for (int i = 0; i < n; i++) a[i] = (int) DIRS.find(s[i]);
  int ans = 0;
  for (int i = 0; i < n; ) {
    int j = i;
    int have = 0;
    while (j < n) {
      if (have > 0 && q[0] != a[j] && (q[0] & 1) == (a[j] & 1)) break;
      if (have > 1 && q[1] != a[j] && (q[1] & 1) == (a[j] & 1)) break;
      if (have > 1 && q[0] != a[j] && q[1] != a[j]) break;
      if (have == 0 || (have == 1 && q[0] != a[j])) {
        q[have++] = a[j];
      }
      ++j;
    }
    ++ans;
    i = j;
  }
  printf("%d\n", ans);
}