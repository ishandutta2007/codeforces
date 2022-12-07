#include<bits/stdc++.h>

using namespace std;

map < string, int > ask(int l, int r) {
  cout << "? " << l << " " << r << endl;
  map < string, int > res;
  int len = r - l + 1, tot = (len * (len + 1)) / 2;
  for(int i = 0; i < tot; ++i) {
    string s; cin >> s;
    sort(s.begin(), s.end());
    ++res[s];
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int n; cin >> n;
  map < string, int > a, b;

  if(n == 1) {
    a = ask(1, 1);
    cout << "! " << a.begin() -> first << endl;
    return 0;
  }

  a = ask(1, n); b = ask(2, n);
  for(auto &p : b) {
    a[p.first] -= p.second;
  }

  vector < string > vec(n + 5);
  for(auto &p : a) {
    if(p.second > 0) vec[p.first.size()] = p.first;
  }

  cout << "! ";
  for(int i = 1; i <= n; ++i) {
    for(char c = 'a'; c <= 'z'; ++c) {
      string w = vec[i - 1];
      w += c;
      sort(w.begin(), w.end());
      if(w == vec[i]) cout << c;
    }
  }

  cout << endl;

  return 0;
}