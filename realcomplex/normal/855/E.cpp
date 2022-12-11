#pragma optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);
#define TEST freopen("in.txt","r",stdin);
#define _ones(a) __builtin_popcount(a)

const int BASE = 12;
const int LEN = 70;
const int MASK = 1222;

ll dp[BASE][LEN][MASK];

void calc_dp(){ 
  for(int i = 2;i <= 10; i ++ ){
    dp[i][0][0] = 1ll;
    for(int j = 0; j < LEN - 1;j ++ ){
      for(int x = 0; x < (1 << i); x ++ ){
        for(int dig = 0; dig < i; dig ++ ){
          dp[i][j + 1][(x ^ (1 << dig))] += dp[i][j][x];
        }
      }
    }
  }
}

ll calc(ll num, int base){
  if(num == 0)
    return 0;
  vector<int> in_base;
  while(num > 0){
    in_base.push_back(num % base);
    num /= base;
  }
  ll rez = 0;
  int n = in_base.size();
  for(int j = 2;j < n;j += 2 ){
    for(int i = 1; i < base;i ++ ){
      rez += dp[base][j-1][(1 << i)];
    }
  }
  int mask = 0;
  for(int i = n - 1;i >= 0;i -- ){
    for(int j = 0; j < in_base[i];j ++ ){
      if(i == n-1 and j == 0)
        continue;
      rez += dp[base][i][(mask^(1<<j))];
    }
    mask ^= (1 << in_base[i]);
  } 
  if(mask == 0)
    rez ++ ;
  return rez;
}

int main(){
  fastIO;
  calc_dp();
  int q;
  cin >> q;
  int _base;
  ll L, R;
  for(int i = 0; i < q; i ++ ){
    cin >> _base >> L >> R;
    cout << calc(R,_base) - calc(L-1,_base) << "\n";
  }
  return 0;
}