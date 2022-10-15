#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cassert>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int a[555], b[555], cn[555];

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  string s, t;
  cin >> s >> t;
  int n = s.size();
  for (int i = 0; i < n; i++) {
    a[(int) s[i] - 'A']++;
    b[(int) t[i] - 'A']++;
  }
  int ansc = 0;
  for (int i = 0; i < 26; i++) {
    if (a[i] > b[i]) ansc += a[i] - b[i];
  }
  string ans = "";
  int already = 0;
  for (int i = 0; i < n; i++) {
    int letter = -1;
    a[s[i] - 'A']--;
    for (int j = 0; j < 26; j++) {
      if (b[j] == 0) continue;
      b[j]--;
      int cur = already;
      if (j != s[i] - 'A') ++cur;
      for (int k = 0; k < 26; k++) if (a[k] > b[k]) cur += a[k] - b[k];
      if (cur == ansc) {
        letter = j;
        break;
      }
      b[j]++;
    }
    assert(letter >= 0);
    ans += (char) (letter + 'A');
    if (ans[i] != s[i]) already++;
  }
  cout << ansc << "\n" << ans << "\n";
}