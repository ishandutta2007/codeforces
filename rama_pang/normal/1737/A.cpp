#include <bits/stdc++.h>
using namespace std;

void Main() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<int> cnt(26);
  for (auto i : s) cnt[i - 'a']++;
  string ans;
  for (int r = 0; r < k; r++) {
    int first = n / k;
    for (int i = 0; i < 26 && i < n / k; i++) {
      if (cnt[i] == 0) {
        first = i;
        break;
      } else {
        cnt[i]--;
      }
    }
    if (first == -1) {

    }
    ans.push_back(first + 'a');    
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T =1 ;
  cin >> T;
  while (T--) Main();
}