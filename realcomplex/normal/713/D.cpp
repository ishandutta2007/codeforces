#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 1005;
const int lg = 10;
short dp[N][N];
short a[N][N];

short f[N][N][lg][lg];
int LOG[N];

int maxq(int il, int jl, int ir, int jr){
  int ilog = LOG[ir - il + 1];
  int jlog = LOG[jr - jl + 1];
  return max({f[il][jl][ilog][jlog], 
    f[ir - (1 << ilog) + 1][jl][ilog][jlog], 
    f[il][jr - (1 << jlog) + 1][ilog][jlog], 
    f[ir - (1 << ilog) + 1][jr - (1 << jlog) + 1][ilog][jlog]});
}

int main(){
  fastIO;
  int n, m;
  cin >> n >> m;
  for(int i = 1; i <= n; i ++ ){
    for(int j = 1; j <= m ; j ++ ){
      cin >> a[i][j];
      if(a[i][j] == 1){
        dp[i][j] = min({dp[i-1][j], dp[i-1][j-1], dp[i][j-1]}) + 1;
      }
      else{
        dp[i][j] = 0;
      }
      f[i][j][0][0] = dp[i][j];
    }
  }
  int p = 0;
  for(int i = 1; i < N ; i ++ ){
    while((1 << (p + 1)) <= i){
      p ++ ;
    }
    LOG[i] = p;
  }
  for(int p = 1; p < lg; p ++ ){
    for(int i = 1; i <= n; i ++ ){
      for(int j = 1; j <= m ; j ++ ){
        if(i + (1 << p) - 1 <= n){
          f[i][j][p][0] = max(f[i][j][p - 1][0], f[i + (1 << (p - 1))][j][p - 1][0]);
        }
        if(j + (1 << p) - 1 <= m){
          f[i][j][0][p] = max(f[i][j][0][p - 1], f[i][j + (1 << (p - 1))][0][p - 1]);
        }
      }
    }
  }
  for(int p = 1; p < lg; p ++ ){
    for(int q = 1; q < lg; q ++ ){
      for(int i = 1; i <= n; i ++ ){
        for(int j = 1; j <= m ; j ++ ){
          if(i + (1 << p) - 1 <= n && j + (1 << q) - 1 <= m){
            f[i][j][p][q] = max({f[i][j][p-1][q-1],f[i + (1 << (p - 1))][j][p - 1][q - 1], f[i][j + (1 << (q - 1))][p - 1][q - 1], f[i + (1 << (p - 1))][j + (1 << (q - 1))][p-1][q-1]});
          }
        }
      }
    }
  }
  int testc;
  cin >> testc;
  int pl, ql,  pr, qr;
  int L, R, md;
  for(int i = 0; i < testc; i ++ ){
    cin >> pl >> ql >> pr >> qr;
    L = 0, R = min(pr - pl + 1, qr - ql + 1) + 1;
    while(L + 1 < R){
      md = (L + R) >> 1;
      if(maxq(pl + md - 1, ql + md - 1, pr, qr) >= md){
        L = md;
      }
      else{
        R = md;
      }
    }
    cout << L << "\n";
  }
  return 0;
}