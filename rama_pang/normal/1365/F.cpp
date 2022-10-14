#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
      cin >> b[i];
    }

    {
      vector<int> pa = a, pb = b;
      sort(begin(pa), end(pa));
      sort(begin(pb), end(pb));
      if (pa != pb) {
        cout << "NO\n";
        continue;
      }
      if (n & 1) {
        if (a[n / 2] != b[n / 2]) {
          cout << "NO\n";
          continue;
        } else {
          a.erase(begin(a) + n / 2);
          b.erase(begin(b) + n / 2);
          n--;
        }
      }
    }

    int half = n / 2;
    int valid = 1;

    vector<int> placed(n, 0);
    for (int i = 0; i < half; i++) {
      int p = 0;
      for (int j = 0; j < n; j++) {
        if (placed[j]) continue;
        if (a[i] == b[j] && a[n - i - 1] == b[n - j - 1]) {
          placed[j] = placed[n - j - 1] = 1;
          p = 1;
          break;
        }
      }
      if (!p) valid = 0;
    }
    
    if (valid) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  } 
}