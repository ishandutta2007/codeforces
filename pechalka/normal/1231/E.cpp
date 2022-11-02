#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <deque>
#include <set>

using namespace std;

int main(){
  int q;
  cin >> q;
  for (int query = 0; query < q; ++query){
    int n;
    cin >> n;
    string s;
    string t;
    cin >> s >> t;
    vector<int> cnt(26);
    for (int i = 0; i < n; ++i)
      ++cnt[s[i] - 'a'];
    for (int i = 0; i < n; ++i)
      --cnt[t[i] - 'a'];
    bool ok = true;
    for (int i = 0; i < 26; ++i)
      ok = ok && (cnt[i] == 0);
    if (!ok){
      cout << -1 << '\n';
      continue;
    }
    int ans = n;
    for (int i = 0; i < n; ++i){
      for (int j = i; j < n; ++j){
        int mxpref = 0;
        for (int k = 0; k < n; ++k){
          if (mxpref < (j - i + 1) && s[k] == t[i + mxpref])
            ++mxpref;
        }
        if (mxpref == (j - i + 1))
          ans = min(ans, i + n - j - 1);
      }
    }
    cout << ans << '\n';
  }
  return 0;
}