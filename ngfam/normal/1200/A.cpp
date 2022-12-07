#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); 
  cin.tie(NULL); cout.tie(NULL); 

  int n; cin >> n;
  string s; cin >> s;
  vector < bool > rooms(10);

  for(auto &c : s) {
    if(c == 'L') {
      for(int i = 0; i < 10; ++i) if(!rooms[i]) {
        rooms[i] = 1;
        break;
      }
    }
    else if(c == 'R') {
      for(int i = 9; i >= 0; --i) if(!rooms[i]) {
        rooms[i] = 1;
        break;
      }
    }
    else {
      rooms[c - '0'] = 0;
    }
  }

  for(int i = 0; i < 10; ++i) cout << rooms[i];

  return 0;
}