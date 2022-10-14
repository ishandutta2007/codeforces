#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> st;
    for (int i = 0; i < n; i++) {
      if (s[i] == ')' && !st.empty() && s[st.back()] == '(') {
        st.pop_back();
      } else {
        st.emplace_back(i);
      }
    }
    cout << st.size() / 2 << "\n";
  }  
}