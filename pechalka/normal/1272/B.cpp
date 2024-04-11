#include <iomanip>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
#ifdef DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#else
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
#endif

  int q;
  cin >> q;
  while (q--) {
    string s;
    cin >> s;
    int cnt[4];
    cnt[0] = 0;
    cnt[1] = 0;
    cnt[2] = 0;
    cnt[3] = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == 'L')
        ++cnt[0];
      else if (s[i] == 'U')
        ++cnt[1];
      else if (s[i] == 'R')
        ++cnt[2];
      else
        ++cnt[3];
    }
    if (min(cnt[0], cnt[2]) == 0 || min(cnt[1], cnt[3]) == 0) {
      if (min(cnt[0], cnt[2]) > 0)
        cout << "2\nLR\n";
      else if (min(cnt[1], cnt[3]) > 0)
        cout << "2\nUD\n";
      else
        cout << "0\n\n";
    } else {
      cout << 2 * (min(cnt[0], cnt[2]) + min(cnt[1], cnt[3])) << '\n';
      for (int i = 0; i < min(cnt[0], cnt[2]); ++i)
        cout << 'L';
      for (int i = 0; i < min(cnt[1], cnt[3]); ++i)
        cout << 'U';
      for (int i = 0; i < min(cnt[0], cnt[2]); ++i)
        cout << 'R';
      for (int i = 0; i < min(cnt[1], cnt[3]); ++i)
        cout << 'D';
      cout << '\n';
    }
  }
  return 0;
}