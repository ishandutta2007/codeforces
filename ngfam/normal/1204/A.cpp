#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); 
  cin.tie(NULL); cout.tie(NULL); 

  string s; cin >> s;

  int ans = 0;

  string cur = "1";
  for(int t = 0; t < 200; ++t) {
    if(cur.size() < s.size() || (cur.size() == s.size() && cur < s)) ++ans;
    cur += "00";
  }

  cout << ans;

  return 0;
}