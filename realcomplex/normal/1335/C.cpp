#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = (int)2e5 + 9;
int cnt[N];

void solve(){ 
  int n;
  cin >> n;
  for(int i = 1; i <= n;i ++ ){
    cnt[i] = 0;
  }
  int x;
  int dis = 0;
  for(int i = 1; i <= n; i ++ ){
    cin >> x;
    dis += (cnt[x] == 0);
    cnt[x] ++ ;
  }
  int ans = 0;
  for(int i = 1; i <= n; i ++ ){
    for(int j = 1; j <= cnt[i]; j ++ ){
      if(j <= dis - (j == cnt[i])) ans = max(ans, j);
    }
  }
  cout << ans << "\n";
}

int main(){
  fastIO;
  int tc;
  cin >> tc;
  for(int t = 0 ; t < tc; t ++ )
    solve();
  return 0;
}