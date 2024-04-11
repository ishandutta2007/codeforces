#include <bits/stdc++.h> 
using namespace std;

int main() {
      int n;
      cin >> n;
      if (n > 26) {cout << -1; return 0;}
      string s;
      cin >> s;
      vector<int> freq(26, 0); 
      for (int i = 0; i < s.size(); i++) {
            freq[s[i] - 'a']++;
      }
      int ans = 0;
      for (int i = 0; i < 26; i++) {
            if (freq[i]) ans += freq[i] - 1;
      }
      cout << ans;
}