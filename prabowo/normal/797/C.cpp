#include <bits/stdc++.h>
using namespace std;

int main() {
  string s; cin >> s;
  string mini = s;
  
  for (int i=(int)mini.size() - 2; i>=0; i--) mini[i] = min(mini[i], mini[i+1]);
  
  stack<int> st;
  for (int i=0; i<s.size(); i++) {
    if (st.size() && st.top() <= mini[i]) {
      printf("%c", st.top());
      st.pop();
      --i;
    } else if (s[i] == mini[i]) printf("%c", s[i]);
    else {
      st.push(s[i]);
    }
  }
  while (st.size()) printf("%c", st.top()), st.pop();;
  
  printf("\n");
  return 0; 
}