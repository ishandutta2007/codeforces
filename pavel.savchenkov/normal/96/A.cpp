#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char s[1000];

int main() {
 int ma = 1;
 int cnt = 1;
 gets(s);
 for (int i = 1; s[i]; i++)
  if (s[i] == s[i - 1]) cnt++; else ma = max(ma, cnt), cnt = 1;
 ma = max(ma, cnt);

 puts((ma >= 7) ? "YES" : "NO");
 return 0;
}