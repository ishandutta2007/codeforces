#include <bits/stdc++.h>

#define Task "C"
#define fi freopen(Task".inp", "r", stdin)
#define fo freopen(Task".out", "w", stdout)

using namespace std;

const int N = 1000;

int n;
int l[N], r[N], p[N];
stack <int> st;
string s;

int main() {
  //fi, fo;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", l + i, r + i);
  }
  for (int i = 0; i < n; i++) {
    p[i] = s.size();
    s += '(';
    st.push(i);
    while (!st.empty() && p[st.top()] + l[st.top()] <= s.size()) {
      if (p[st.top()] + r[st.top()] < s.size()) {
        puts("IMPOSSIBLE");
        return 0;
      }
      s += ')';
      st.pop();
    }
  }
  if (!st.empty()) {
    puts("IMPOSSIBLE");
  } else {
    cout << s;
  }
  return 0;
}