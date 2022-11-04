#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  
  #ifdef LOCAL
  freopen("input.txt", "r", stdin);
  #endif
  
  int n;
  cin >> n;
  
  priority_queue<int> q;
  vector<string> ops;
  
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    
    if (s[0] == 'i') { // insert
      int x;
      cin >> x;
      q.push(-x);
      ops.push_back(s + " " + to_string(x));
    } else if (s[0] == 'r') { // remove
      if (q.empty()) {
        ops.push_back("insert 0");
      } else q.pop();
      ops.push_back(s);
    } else { // get
      int x;
      cin >> x;
      
      if (q.empty()) {
        q.push(-x);
        ops.push_back("insert " + to_string(x));
      } else if (-q.top() !=  x) {
        while (!q.empty() && -q.top() < x) {
          ops.push_back("removeMin");
          q.pop();
        }
        
        if (q.empty() || -q.top() > x) {
          q.push(-x);
          ops.push_back("insert " + to_string(x));
        }
      }
      
      ops.push_back(s + " " + to_string(x));
    }
  }
  
  cout << ops.size() << "\n";
  for (string &s : ops) cout << s << "\n";
  
  return 0;
}