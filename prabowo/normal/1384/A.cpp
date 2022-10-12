#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n;
int a[N];

int solve() {
  scanf("%d", &n);
  string s;
  for (int j = 0; j < 50; ++j) {
    s += 'a';
  }
  cout << s << endl;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    for (int j = a[i]; j < 50; ++j) {
      s[j] = (s[j] + 1);
      if (s[j] > 'z') s[j] = 'a';
    }

    cout << s << endl;
  }

  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}