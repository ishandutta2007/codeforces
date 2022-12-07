#include <bits/stdc++.h>

using namespace std;

int n, m;
long long k;

int main(){
  #ifdef pts
    freopen("1.inp", "r", stdin);
  #endif // pts
  cin >> n >> m >> k;
  long long low = 1, high = 1LL * n * m, answer = 1;
  while(low <= high){
    long long val = (low + high) >> 1;
    long long cnt = 0;
    for(int i = 1; i <= n; ++i){
      cnt += min(1LL * m, val / i);
      if(val <= 1LL * i * m && val % i == 0){
        --cnt;
      }
    }
    if(cnt < k){
      answer = val;
      low = val + 1;
    }
    else{
      high = val - 1;
    }
  }
  cout << answer;
  return 0;
}