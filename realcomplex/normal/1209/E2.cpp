#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 12;
const int M = 2000;
int a[N][M];
int best[1 << N][N];
int dp[1 << N][N];
 
void solve(){
  for(int i = 0; i < (1 << N) ; i ++ )
    for(int j = 0 ; j < N ; j ++ )
      best[i][j] = 0, dp[i][j] = 0;
  int n, m ;
  cin >> n >> m;
  for(int i = 0 ; i < n ; i ++ ){
    for(int j = 0 ; j < m ; j ++ ){
      cin >> a[i][j];
    }
  }
  vector<pii> ff;
  int mx;
  for(int i = 0 ; i < m ; i ++ ){
    mx = 0;
    for(int j = 0 ; j < n ; j ++ ){
      mx = max(mx, a[j][i]);
    }
    ff.push_back(mp(mx, i));
  }
  sort(ff.begin(), ff.end());
  reverse(ff.begin(), ff.end());
  while(ff.size() > n){
    ff.pop_back();
  }
  int k = ff.size();
  int sum;
  for(int i =0 ; i < k; i ++ ){
    for(int j = 0; j < n ; j ++ ){
      for(int t = 0 ;t < (1 << n) ;t ++ ){
        sum = 0;
        for(int z =0 ; z < n ; z ++ ){
          if(t & (1 << z)){
            sum += a[(z-j+n)%n][ff[i].se];
          }
        }
        best[t][i] = max(best[t][i], sum);
      }
    }
  }
  for(int mask = 0 ; mask < (1 << n); mask ++ ){
    dp[mask][0] = best[mask][0];
  }
  int cur;
  int rem;
  for(int i = 1; i < k ; i ++ ){
    for(int j = 0 ; j < (1 << n); j ++ ){
      cur = j;
      while(1){
        rem = j ^ cur;
        dp[j][i] = max(dp[j][i], dp[cur][i-1] + best[rem][i]); 
        if(cur == 0) break;
        cur = (cur - 1) & j;
      }
    }
  }
  cout << dp[(1 << n) - 1][k - 1] << "\n";
}

int main(){
  fastIO;
  int testc;
  cin >> testc;
  for(int i = 1; i <= testc; i ++ )
    solve();
  return 0;
}