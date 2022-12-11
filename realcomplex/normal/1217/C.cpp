#include <bits/stdc++.h>

using namespace std;

const int N = (int)2e5 + 9;
int nx[N];

int main(){
  int testc;
  cin >> testc;
  for(int tt = 1; tt <= testc; tt ++ ){
    string t;
    cin >> t;
    int n = t.size();
    nx[0] = -1;
    int j;
    if(t[0] == '1')
      nx[0]=0;
    for(int i = 1; i < n; i ++ ){
      if(t[i] == '1')
        nx[i] = i;
      else
        nx[i] = nx[i - 1];
    }
    int res = 0;
    int base;
    int sum;
    int rl;
    for(int i = 0 ; i < n; i ++ ){
      base = 1;
      j = i;
      sum = 0;
      for(int tt = 0 ; tt < 20; tt ++ ){
        sum += (t[j] - '0') * base;
        if(sum == (i - j + 1)){
          res ++ ;
        }
        --j;
        if(j < 0)
          break;
        base *= 2ll;
      }
      if(j >= 0){
        if(sum <= i + 1){
          rl = i - sum + 1;
          if(nx[j] < rl && rl <= j){
            res ++ ;
          }
        }
      }
    }
    cout << res << "\n";
  }
  return 0;
}