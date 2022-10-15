#include <cstdio>
#include <string>

using namespace std;

void read(string &s) {
  s = "";
  int c = getchar();
  while (c <= 32) c = getchar();
  s = "";
  while (c > 32) s += (char) c, c = getchar();
}
#define pair skjkj
int pair[42];
bool ok;
int ans[42];

void make(int c, int d) {
  c -= 'a';
  d -= 'a';
  if (pair[c] >= 0 && pair[c] != d) {
    ok = false;
  } else {
    pair[c] = d;
  }
}

int main() {
  string s, t;
  read(s);
  read(t);
  int n = (int) s.length();
  ok = true;
  for (int i = 0; i < 26; i++) pair[i] = -1;
  for (int i = 0; i < n; i++) {
    make(s[i], t[i]);
    make(t[i], s[i]);
  }
  if (!ok) {
    puts("-1");
    return 0;
  }
  int ac = 0;
  for (int i = 0; i < 26; i++) {
    if (pair[i] >= 0 && pair[i] > i) {
      ans[ac++] = i;
    }
  }
  printf("%d\n", ac);
  for (int i = 0; i < ac; i++) {
    printf("%c %c\n", (char) (ans[i] + 'a'), (char) (pair[ans[i]] + 'a'));
  }
}