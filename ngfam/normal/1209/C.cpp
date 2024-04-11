#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); 
  cin.tie(NULL); cout.tie(NULL); 

  int T; cin >> T;
  while(T--) {
    int n; cin >> n;
    string s; cin >> s;

    bool found = false;

    for(int bound = 1; bound < 9; ++bound){
      vector < int > color(n, 0);
      int cnt = 0;

      int last = 0, first = n - 1;

      int mxchar[2] = {-1, -1};

      for(int i = 0; i < n; ++i) { 
        char c = s[i];
        if(c - '0' < bound) {
          last = i;
          cnt++;
          color[i] = 1;

          if(c < mxchar[0]) {
            --cnt;
          }
          mxchar[0] = c;
        }
        else if(c - '0' > bound) {
          if(first == n - 1) first = i;
          cnt++;
          color[i] = 2;
          if(c < mxchar[1]) --cnt;
          mxchar[1] = c;
        }
      }

      for(int i = last; i < n; ++i) {
        if(s[i] - '0' == bound && !color[i]) {
          ++cnt;
          color[i] = 1;
        } 
      }

      for(int i = first; i >= 0; --i) {
        if(s[i] - '0' == bound && !color[i]) {
          ++cnt;
          color[i] = 2;
        } 
      }
    

      if(cnt == n) {
        for(auto x : color) cout << x;
        found = true; 
        break;
      }
    }

    if(!found) cout << "-";
    cout << endl;
  }

  return 0;
}