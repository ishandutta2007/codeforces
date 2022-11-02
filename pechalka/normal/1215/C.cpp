#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <deque>
#include <set>

using namespace std;

int main(){
  int n;
  cin >> n;
  string s;
  string t;
  cin >> s >> t;
  vector<int> ab;
  vector<int> ba;
  for (int i = 0; i < n; ++i){
    if (s[i] != t[i] && s[i] == 'a')
      ab.emplace_back(i);
    if (s[i] != t[i] && s[i] == 'b')
      ba.emplace_back(i);
  }
  if ((ab.size() + ba.size()) % 2 == 1)
    cout << -1;
  else {
    cout << (ab.size() + ba.size()) / 2 + (ab.size() % 2) << '\n';
    for (int i = 0; i + 1 < ab.size(); i += 2)
      cout << ab[i] + 1 << ' ' << ab[i + 1] + 1 << '\n';
    for (int i = 0; i + 1 < ba.size(); i += 2)
      cout << ba[i] + 1 << ' ' << ba[i + 1] + 1 << '\n';
    if (ab.size() % 2 == 1){
      cout << ab[ab.size() / 2 * 2] + 1 << ' ' << ab[ab.size() / 2 * 2] + 1 << '\n';
      cout << ab[ab.size() / 2 * 2] + 1 << ' ' << ba[ba.size() / 2 * 2] + 1 << '\n';
    }
  }
  return 0;
}