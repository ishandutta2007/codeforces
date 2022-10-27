#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
int t, n, p[101], lt[101];
bool ok[101][101];
inline bool cmp(int i, int j) {
  cout << 1 << ' ' << i << ' ' << j << endl, cout.flush();
  int tp;
  cin >> tp;
  return tp;
}
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; i++)
      p[i] = i;
    stable_sort(p, p + n, cmp);
    memset(ok, 0, sizeof ok);
    for (int i = 0; i < n; i++) {
      lt[i] = i;
      for (int j; lt[i] > 0;) {
        j = lt[i] - 1;
        cout << 2 << ' ' << p[i] << ' ' << j + 1;
        for (int k = 0; k <= j; k++)
          cout << ' ' << p[k];
        cout << endl, cout.flush();
        int tp;
        cin >> tp;
        if (tp) {
          for (int k = j + 1; k <= i; k++)
            lt[k] = lt[j];
        } else
          break;
      }
    }
    for (int i = 0; i < n; i++)
      for (int j = lt[i]; j < n; j++)
        ok[p[i]][p[j]] = 1;
    cout << 3 << endl;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++)
        cout<<(char)(ok[i][j] + '0');
      cout<<endl;
    }
    int tp;
    cin>>tp,cout.flush();
  }
}