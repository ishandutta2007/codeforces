#include <bits/stdc++.h>

using namespace std;

const int N = 100500;
const int M = 510;

int n;
int f[N];
int done[N];
int ok[M];
int sxor[N];

int main(){
  #ifdef pts
    //freopen("1.inp", "r", stdin);
  #endif // pts
  scanf("%d", &n);
  int answer = n;
  for(int x = 3; x <= n; ++x){
    memset(ok, 0, sizeof ok);
    for(int sz = 2; sz * (sz - 1) <= x * 2; ++sz){
      int curr = x - (sz * (sz - 1)) / 2;
      if(curr <= 0){
        continue;
      }
      if(curr % sz != 0){
        continue;
      }
      int slv = curr / sz;
      int nw = sxor[slv + sz - 1] ^ sxor[slv - 1];
      if(x == n && nw == 0){
        answer = min(answer, sz);
      }
      ok[nw] = 1;
    }
    for(int i = 0; i <= 500; ++i){
      if(ok[i] == 0){
        f[x] = i;
        break;
      }
    }
    sxor[x] = sxor[x - 1] ^ f[x];
  }
  if(answer == n){
    answer = -1;
  }
  cout << answer;
  return 0;
}