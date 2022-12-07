#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  string s; cin >> s;

  char minchar = 'z';
  for(auto &c : s) {
    if(minchar < c) {
      cout << "Ann\n";
    }
    else {
      cout << "Mike\n";
    }
    minchar = min(minchar, c);
  }

  return 0;
}