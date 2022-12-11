#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 105;
ll h[N][N];
ll cost[N][N];

void solve(){
  int n, m;
  cin >> n >> m;
  for(int i = 0; i <= n; i ++ ){
    for(int j = 0 ; j <= m ; j ++ ){
      h[i][j]=(ll)1e18;
    }
  }
  for(int i = 1; i <= n; i ++ ){
    for(int j = 1; j <= m; j ++ ){
      cin >> h[i][j];
    }
  }
  vector<ll> cand;
  for(int i = 1; i <= n; i ++ ){
    for(int j = 1; j <= m ; j ++ ){
      if(h[i][j]-(i+j-2)<=h[1][1]){
        cand.push_back(h[i][j]-(i + j - 2));
      }
    }
  }
  sort(cand.begin(),cand.end());
  cand.resize(unique(cand.begin(),cand.end()) - cand.begin());
  int li = 0, ri = cand.size();
  int mid;
  ll ans = (ll)1e18;
  ll des;
  for(auto x : cand){
    des=x;
    for(int i = 0 ; i <= n; i ++ ){
      for(int j = 0 ; j <= m ; j ++ ){
        cost[i][j]=(ll)1e18;
      }
    }
    cost[1][0]=cost[0][1]=0;
    ll low;
    for(int i = 1; i <= n; i ++ ){
      for(int j =1; j <= m ; j ++ ){
        low=min(cost[i-1][j],cost[i][j-1]);
        if(low==(ll)1e18)continue;
        if(h[i][j] >= des + (i + j-2)){
          low+=h[i][j]-(des+(i+j-2));
          cost[i][j]=low;
        }
        else{
          continue;
        }
      }
    }
    if(cost[n][m]==(ll)1e18)
      break;
    else{
      ans=min(ans,cost[n][m]);
    }
  }
  cout << ans << "\n";
}

int main(){
  fastIO;
  int tc;
  cin >> tc;
  for(int t = 0 ;t < tc;t ++ )
    solve();
  return 0;
}