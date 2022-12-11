#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main(){
  fastIO;
  int tc;
  cin >> tc;
  for(int t = 1; t <= tc; t ++ ){
    char cur[9][9];
    for(int i = 0; i < 9 ; i ++ ){
      for(int j = 0; j < 9 ; j ++ ){
        cin >> cur[i][j];
      }
    }
    int x, y;
    for(int t = 0 ;t < 3; t ++ ){
      x = 3 * t;
      y = t;
      for(int j = 0 ; j < 3; j ++ ){
        if(cur[x + j][y] == '1') cur[x + j][y] = '2';
        else cur[x + j][y] = '1';
        y += 3;
        y %= 9;
      }
    }
    for(int i = 0 ; i < 9 ; i ++ ){
      for(int j = 0 ; j < 9 ; j ++ ){
        cout << cur[i][j];
      }
      cout << "\n";
    }
  }
  return 0;
}