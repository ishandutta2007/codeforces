#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); 
  cin.tie(NULL); cout.tie(NULL); 

  int nTest; cin >> nTest;

  while(nTest--) {
    string s, t;
    cin >> s >> t;

    int pter = 0;
    char last = '&';
    for(auto &c : s) {
      if(pter == t.size()) {
        pter = -1;
        break;
      }
      while(t[pter] != c) {
        if(t[pter] != last) {
          pter = -1;
          break;
        }
        ++pter;
        if(pter == t.size()) {
          pter = -1;
          break;
        }
      }
      if(pter == -1) break;
      ++pter;
      last = c;
    }

    while(pter != -1 && pter < t.size()) {
      if(t[pter] != last) {
        pter = -1;
        break;
      }
      ++pter;
    }

    cout << (pter == -1 ? "NO" : "YES") << "\n";
  }

  return 0;
}