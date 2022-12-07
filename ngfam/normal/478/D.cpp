#include <bits/stdc++.h>

using namespace std;

const int N = 500050;
const int mod = 1e9 + 7;

int r, g;
int f[N];

int main(){
  #ifdef pts
    freopen("1.inp", "r", stdin);
  #endif // pts
  scanf("%d%d", &r, &g);
  f[0] = 1;
  int value = 0;
  for(int x = 1; (x * (x + 1)) / 2 <= r + g; ++x){
    value = x;
    for(int i = r; i >= x; --i){
      f[i] += f[i - x];
      f[i] %= mod;
    }
  }
  int answer = 0;
  for(int i = 0; i <= r; ++i){
    if(i + g >= (value * (value + 1)) / 2){
      answer += f[i];
      answer %= mod;
    }
  }
  cout << answer;
  return 0;
}