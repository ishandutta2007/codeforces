#include <bits/stdc++.h>

using namespace std;


int const N = 123456;
string s[N], t[N], ans[N], ant[N];
int was[N];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s[i] >> t[i];
  }
  int ac = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (was[i]) continue;
    was[i] = true;
    string cur = s[i];
    for (int j = i - 1; j >= 0; j--) {
      if (cur == t[j]) {
        was[j] = true;
        cur = s[j];
      }
    }
    ans[ac] = cur;
    ant[ac++] = t[i];
  }
  cout << ac << endl;
  for (int i = 0; i < ac; i++) cout << ans[i] << ' ' << ant[i] << endl;
}