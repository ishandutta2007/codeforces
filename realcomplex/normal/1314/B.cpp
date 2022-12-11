#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 17;
const int M = (1 << N);
const int inf = (int)1e9;
int dp[M][2][2];
int has[M];

void upd(int &a, int b){
  a = max(a, b);
}
int nw[2][2];

int main(){
  fastIO;
  int n, k;
  cin >> n >> k;
  int x;
  for(int i = 1; i <= k ; i ++ ){
    cin >> x;
    --x;
    has[x]=true;
  }
  int m = (1 << n);
  for(int i = 0 ; i < m ; i ++ ){
    for(int x = 0; x < 2; x ++ ){
      for(int j = 0 ; j < 2; j ++ )
        dp[i][x][j]=-inf;
    }
  }
  for(int i = 0; i < m ; i += 2){
    dp[i][has[i]][has[i + 1]] = (has[i] | has[i + 1]);
    dp[i][has[i + 1]][has[i]] = (has[i] | has[i + 1]);
  }
  
  int l1,l2;
  int tot;
  for(int lg = 1; lg < n; lg ++ ){
    for(int i = 0 ; i + (1 << (lg + 1)) <= m ; i += (1 << (lg + 1))){ 
      l1 = i;
      l2 = i + (1 << lg);
      for(int p = 0 ; p < 2; p ++ )
        for(int q = 0; q < 2; q ++ )
          nw[p][q]=-inf;
      for(int p = 0 ; p < 2; p ++ ){
        for(int d = 0; d < 2; d ++ ){
          for(int q = 0; q < 2; q ++ ){
            for(int e = 0; e < 2; e ++ ){
              if(dp[l1][p][d] == -inf || dp[l2][q][e] == -inf)
                continue;
              tot = (p | q) + (d | e) + dp[l1][p][d] + dp[l2][q][e];
              upd(nw[p][q],tot + (q | d));
              upd(nw[p][q],tot + (q | e));
              upd(nw[p][d],tot + (q | d));
              upd(nw[p][e],tot + (q | e));
              
              upd(nw[q][p],tot + (p | d));
              upd(nw[q][p],tot + (p | e));
              upd(nw[q][d],tot + (p | d));
              upd(nw[q][e],tot + (p | e));
            }
          }
        }
      }
      for(int p = 0 ; p < 2; p ++ )
        for(int q = 0; q < 2; q ++ )
          dp[l1][p][q] = nw[p][q];
    }
  }
  int res = 0;
  for(int i = 0 ; i < 2; i ++ )
    for(int j = 0 ; j < 2; j ++ )
      upd(res, dp[0][i][j] + (i | j));
  cout << res << "\n";
  return 0;
}