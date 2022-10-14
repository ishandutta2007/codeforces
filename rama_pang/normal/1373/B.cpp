#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.size();
    int res = 0;
    vector<char> st;
    for (auto i : s) {
      if (st.empty() || i == st.back()) {
        st.emplace_back(i);
      } else {
        res++;
        st.pop_back();
      }
    }
    if (res & 1) {
      cout << "DA\n";
    } else {
      cout << "NET\n";
    }
  }  
}