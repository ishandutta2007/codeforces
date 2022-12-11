#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = (int)2e5 + 1;
const int M = 201;

int cnt[N][M];
vector<int> pos[M];

void solve(){
  int n;
  cin >> n;
  int x;
  for(int i = 1; i < M ;i ++ ) pos[i].clear();
  int ans = 1;
  for(int i = 1; i <= n; i ++ ){
    cin >> x;
    pos[x].push_back(i);
    for(int j = 1; j < M ;j ++ )
      cnt[i][j] = cnt[i-1][j];
    cnt[i][x] ++ ;
    ans = max(ans, cnt[i][x]);
  }
  int k;
  for(int i = 1; i < M ; i ++ ){
    for(int j = 1; j < M; j ++ ){
      k = pos[i].size();
      for(int x = 1; x <= k/2; x ++ ){
        ans = max(ans, 2 * x - cnt[pos[i][x - 1]][j] + cnt[pos[i][k - x] - 1][j]);
      }
    }
  }
  cout << ans << "\n";
}

int main(){
  fastIO;
  int tc;
  cin >> tc;
  for(int t = 0 ;t < tc; t ++ ){
    solve();
  }
  return 0;
}