#include<bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  string s; cin >> s;

  long long ans = 0;
  for(char x = 'a'; x <= 'z'; ++x){
    for(char y = 'a'; y <= 'z'; ++y) {
      long long cntx = 0;
      long long all = 0;
      for(char c : s) {
        if(c == y) all += cntx;
        if(c == x) cntx++;
      }
      ans = max(ans, all);
      ans = max(ans, cntx);
    }
  }

  cout << ans << endl;

  return 0;
}