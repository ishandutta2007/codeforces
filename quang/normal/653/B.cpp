#include <bits/stdc++.h>

using namespace std;

set<string> x;
queue< string> q;
int res = 0;
int n, m;
string a[110];
char b[110];

string findPos(const string &u, int id) {
  int pos = -1;
  for (int i = 0; i < u.size(); i++) {
    if (u[i] == b[id]) {
      pos = i;
      break;
    }
  }
  if (pos == -1 || pos != 0) {
    return "";
  }
  string res = "";
  for (int i = 0; i < u.size(); i++) {
    if (i == pos) {
      res += a[id];
    } else {
      res += u[i];
    }
  }
  return res;
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> a[i] >> b[i];
  }
  q.push("a");
  x.insert("a");
  while (!q.empty()) {
    string now = q.front();
    q.pop();
    if (now.size() == n) {
      res++;
      continue;
    }
    for (int i = 1; i <= m; i++) {
      string nxt = findPos(now, i);
      if (nxt == "") {
        continue;
      }
      if (x.find(nxt) != x.end()) {
        continue;
      }
      q.push(nxt);
      x.insert(nxt);
    }
  }
  cout << res << endl;
//for (string u : x) {
//  cout << u << endl;;
//}
  return 0;
}