#include<bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int n; string s;
  cin >> n >> s;

  if(n == 1) {
    cout << "Yes\n";
    return 0;
  }

  map<char, int> w;
  for(auto c : s) ++w[c];

  int cnt = 0;
  for(auto &p : w) cnt += (p.second > 1);

  if(cnt) cout << "Yes";
  else cout << "No";

  return 0;
}