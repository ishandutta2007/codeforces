#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int ntest; cin >> ntest;
  while(ntest--) {
    int n, k; cin >> n >> k;
    string s; cin >> s;

    int h = k;
    h = min(h, 20);
    while((1 << (h)) > n * 2) h--;  

    string ans;
    for(int i = 0; i < k - h; ++i) ans += '1';

    int cntone = 0;
    for(int i = 0; i < k - h; ++i) if(s[i] == '1') cntone += 1;

    set<int> mex;
    for(int i = 0; i + k <= n; ++i) {
      if(i > 0) {
        if(s[i - 1] == '1') cntone--;
        if(s[i + k - h - 1] == '1') cntone++;
      }

      if (cntone != k - h) continue;

      int r = i + k - 1, val = 0;
      for(int j = 0; j < h; ++j) {
        if(s[r - j] == '1') val |= (1 << j);
      }
      mex.insert(val);
    }

    int res = (1 << h) - 1;
    while(res >= 0 && mex.count(res)) res--;

    if(res < 0) {
      cout << "NO\n";
      continue;
    }

    for(int i = h - 1; i >= 0; --i) if (res & (1 << i)) ans += '1';
    else ans += '0';
    cout << "YES\n";

    for(int i = 0; i < ans.size(); ++i) if (ans[i] == '1') ans[i] = '0';
    else ans[i] = '1';

    cout << ans << "\n";
  }

  return 0;
}