#include <cstdio>
#include <string>
using namespace std;

string dp[42], ndp[42];
int main() {
  int c = getchar();
  while (c <= 32) c = getchar();
  while (c > 32) {
    int d = c - '0';
    for (int i = 0; i < 8; i++) {
      ndp[i] = dp[i];
    }
    if (ndp[d % 8] == "")
      ndp[d % 8] += (char) (d + '0');
    for (int i = 0; i < 8; i++) {
      if (dp[i] == "") continue;
      int e = (i * 10 + d) % 8;
      if (ndp[e] == "") {
        ndp[e] = dp[i];
        ndp[e] += (char) (d + '0');
      }
    }
    for (int i = 0; i < 8; i++) {
      dp[i] = ndp[i];
      ndp[i] = "";
    }
    c = getchar();
  }
  if (dp[0] == "") {
    puts("NO");
  } else {
    puts("YES");
    puts(dp[0].c_str());
  }
}