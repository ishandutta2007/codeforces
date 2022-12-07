#include <bits/stdc++.h>

using namespace std;

const int N = 110;

int n;
string a[2];
int dp[N][4];

int c(char c) {
  return c == 'X';
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  cin >> a[0] >> a[1];

  int n = a[0].size();

  vector < pair < int, int > > vec[4] = {{{0, 0}, {1, 0}, {0, 1}},
                                          {{0, 0}, {0, 1}, {1, 1}},
                                          {{1, 0}, {0, 0}, {1, 1}},
                                          {{0, 1}, {1, 0}, {1, 1}}};



  int ans = 0;
  for(int i = 0; i < n - 1; ++i) {
    for(int j = 0; j < 4; ++j){
      int x = 0, y = i;
      bool flag = false;
      for(auto p : vec[j]) {
        if(a[x + p.first][y + p.second] == 'X') {
          flag = true;
        }
      }

      if(!flag) {
        ans++;
        for(auto p : vec[j]) {
          a[x + p.first][y + p.second] = 'X';
        }
      }
    }
  }

  cout << ans << endl;

  return 0;
}