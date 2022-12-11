#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)3e5 + 9;
ll dp[N][3];
ll a[N], b[N];
const ll inf = (ll)1e18;

void solve(){
  int n;
  cin >> n;
  for(int i = 1; i <= n; i ++ ){
    for(int j = 0 ; j < 3; j ++ ){
      dp[i][j] = inf;
    }
  }
  for(int i = 1; i <= n; i ++ ){
    cin >> a[i] >> b[i];
  }
  for(int j = 0; j < 3; j ++ ){
    dp[1][j] = b[1] * j;
  }
  for(int i = 2; i <= n; i ++ ){
    for(int j = 0 ; j < 3; j ++ ){
      for(int z =0; z < 3; z ++ ){
        if(a[i - 1] + j != a[i] + z){
          dp[i][z] = min(dp[i][z], dp[i-1][j] + b[i] * z);
        }
      }
    }
  }
  cout << min({dp[n][0], dp[n][1], dp[n][2]}) << "\n";
}

int main(){
  fastIO;
  int testc;
  cin >> testc;
  for(int t =0 ; t < testc; t ++ ){
    solve();
  }
  return 0;
}