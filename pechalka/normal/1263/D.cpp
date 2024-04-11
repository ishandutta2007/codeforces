#include <set>
#include <deque>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> p;

int get(int v){
  if (v == p[v])
    return v;
  return p[v] = get(p[v]);
}

int merge(int u, int v){
  u = get(u);
  v = get(v);
  if (u == v)
    return 0;
  p[u] = v;
  return 1;
}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int was[26];
  for (int i = 0; i < 26; ++i)
    was[i] = 0;
  int n;
  cin >> n;
  int ans = n;
  p.resize(26 + n);
  for (int i = 0; i < n + 26; ++i)
    p[i] = i;
  for (int i = 0; i < n; ++i){
    string s;
    cin >> s;
    for (int j = 0; j < s.size(); ++j){
      ans -= merge(s[j] - 'a', i + 26);
      ++was[s[j] - 'a'];
    }
  }
  for (int i = 0; i < 26; ++i)
    ans += (was[i] > 0);
  cout << ans;
  return 0;
}