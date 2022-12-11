#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 9;
const ll inf = (ll)1e18;
ll dp[N];

int main(){
  fastIO;
  int n, k;
  cin >> n >> k;
  for(int i = 0 ; i <= n; i ++ )
    dp[i] = inf;
  dp[0] = 0;
  char t;
  deque<pii> pos;
  deque<pii> ask;
  ask.push_back(mp(0,0));
  ll ad;
  int nx;
  for(int i = 1; i <= n; i ++ ){
    cin >> t;
    while(!pos.empty() && pos.front().se < i)
      pos.pop_front();
    while(!ask.empty() && ask.front().se < i - k - 1){
      ask.pop_front();
    }
    
    dp[i] = dp[i - 1] + i;
    if(!pos.empty()){
      dp[i] = min(dp[i], pos.front().fi);
    }
    if(t == '1'){
      ad = dp[ask.front().se] + i;
      nx = i + k;
      while(!pos.empty() && pos.back().fi > ad){
        pos.pop_back();
      }
      dp[i] = min(dp[i], ad);
      pos.push_back(mp(ad, nx));
    }
    while(!ask.empty() && ask.back().fi > dp[i])
      ask.pop_back();
    ask.push_back(mp(dp[i], i));
  }
  cout << dp[n] << "\n";
  return 0;
}