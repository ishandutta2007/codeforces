#include <bits/stdc++.h>

using namespace std;

int main(){
  int testc;
  cin >> testc;
  for(int i = 1; i <= testc; i ++ ){
    int n, x;
    cin >> n >> x;
    int big = 0;
    int mb = 0;
    int d, h;
    int res = 0;
    for(int j = 0 ; j < n ; j ++ ){
      cin >> d >> h;
      big = max(big, d);
      mb = max(mb, d - h);
    }
    x -= big;
    res = 1;
    if(x > 0){
      if(mb <= 0){
        cout << -1 << "\n";
        continue;
      }
      res += (x + mb - 1) / mb;
    }
    cout << res << "\n";
  }
  return 0;
}