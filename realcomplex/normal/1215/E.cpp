#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int K = 20;
const ll inf = (ll)1e18;
const int N = (int)4e5 + 9;
int a[N];
vector<int> p[N];

ll opt[K][K];
ll ff[K][K];
ll cost[K];
ll dp[1<<K];
ll cnt[K][K];

int main(){
  fastIO;
  int n;
  cin >> n;
  for(int i = 0 ; i < n; i ++ ){
    cin >> a[i];
    a[i] -- ;
    p[a[i]].push_back(i);
  }
  vector<int> pp;
  for(int i = 0 ; i < K; i ++ ){
    if(p[i].size() > 0)
      pp.push_back(i);
  }
  int k = pp.size();
  ll pf;
  int total;
  for(int i = 0 ;i < k ; i ++ ){
    pf = 0;
    for(int j = 1; j < p[pp[i]].size(); j ++ ){
      pf += p[pp[i]][j] - p[pp[i]][j-1] - 1;
      cost[pp[i]] += pf;
    }
    total = p[pp[i]].size();
    for(int j = 0 ;j  < n ; j ++ ){
      if(a[j] == pp[i]) total --;
      else if(total < (int)p[pp[i]].size()) opt[pp[i]][a[j]] += total;
    }
    for(int j = 0 ; j < n ; j ++ ){
      if(a[j] != pp[i]){
        if(j > p[pp[i]][0]){
          cnt[pp[i]][a[j]] ++ ;
        }
      }
    }
  }
  for(int i = 0 ;i < (1 << K) ; i ++ ){
    dp[i] = inf;
  }
  dp[0] = 0;
  for(int i = 0 ; i < k ; i ++ ){
    dp[(1<<i)] = cost[pp[i]] + ((ll)p[pp[i]][0] * (ll)p[pp[i]].size());
  }
  ll cur;
  ll nx;
  ll shf;
  ll tot;
  for(int i = 1 ; i < (1 << k) ; i ++ ){
    if(i + 1 == (1 << k)){
      cout << dp[i] << "\n";
      return 0;
    }
    for(int j = 0 ; j < k; j ++ ){
      if(!(i & (1 << j))){
        cur = cost[pp[j]];
        nx = 0;
        shf = p[pp[j]][0];
        tot = 0;
        for(int t = 0;t < k ;t ++ ){
          if(i & (1 << t)){
            cur -= opt[pp[j]][pp[t]];
            shf += cnt[pp[j]][pp[t]];
            tot += p[pp[t]].size();
          }
        }
        dp[i | (1 << j)] = min(dp[i | (1 << j)], dp[i] + cur + (shf - tot) * (ll)p[pp[j]].size());
      }
    }
  }
  return 0;
}