#include <bits/stdc++.h>

using namespace std;

void work(string &s, int k) {
  string tmp;
  for(int i = 0; i < k; ++i) tmp += s[s.size() - i - 1];
  for(int i = 0; i < s.size() - k; ++i) tmp += s[i];
  s = tmp;
}

string s, t;
vector < int > answers;

void solve(int x) {
  if(x == 0) return;
  answers.push_back(x);
  work(s, x);
}

int main(){

  int n; cin >> n;
  cin >> s >> t;

  int l, r;
  int pos = -1;
  for(int i = 0; i < n; ++i) if(s[i] == t[n / 2]) {
    pos = i;
  }

  if(pos == -1) {
    cout << -1;
    exit(0);
  }

  if(pos != n - 1) {
    solve(n - pos - 1);
  }
  solve(1);

  l = n / 2; r = n / 2;

  bool flag = true;
  for(int i = 1; i < n; ++i) {
    int len = r - l + 1;
    int req = flag ? l - 1 : r + 1;

    int pos = -1;
    for(int i = len; i < s.size(); ++i) {
      if(s[i] == t[req]) pos = i;
    }
    if(pos == -1) {
      cout << -1;
      exit(0);
    }

    solve(n - pos);
    solve(n - (len + (n - pos)));
    solve(len + 1);

    if(flag) l--;
    else r++;
    flag = 1 - flag;
  }

  if(s != t) solve(n);

  cerr << s << " " << t << endl;
  cout << answers.size() << endl;
  for(int x : answers) cout << x << " ";

  return 0;
}