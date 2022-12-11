#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef long double db;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define TEST freopen("in.txt","r",stdin);
#define ones(a) __builtin_popcount(a);
#define pq priority_queue

const ll MOD = 998244353;

const int N = 1005;
ll dp[N];
ll fac[N];

ll kap(ll x, ll k){
  if(k == 0)
    return 1ll;
  ll pr = kap(x, k/2);
  pr *= pr;
  pr %= MOD;
  if(k % 2){
    pr *= x;
    pr %= MOD;
  }
  return pr;
}

ll inv(ll x){
  return kap(x, MOD-2);
}

ll calc(ll n, ll k){
  return (((fac[n] * inv(fac[k])) % MOD) * inv(fac[n-k])) % MOD;
}

bool ok[N];

int main(){
  fastIO;
  fac[0] = 1ll;
  for(int i = 1;i < N; i ++ ){
    fac[i] = (fac[i - 1] * 1ll * i) % MOD;
  }
  int n;
  cin >> n;
  int a[n];
  for(int i = 0;i < n;i ++ ){
    cin >> a[i];
  }
  int tot;
  int rq = 0;
  int tq;
  ll ans = 0ll;
  for(int i = n - 1;i >= 0; i -- ){
    if(a[i] > 0 and i + a[i] < n){
      dp[i] = calc(rq, a[i]);
      tq = 0;

      for(int j = i + 1;j < n;j ++ ){
        ++ tq;
        if(tq > a[i]){
          dp[i] += dp[j] * calc(tq - 1 , a[i]);
          dp[i] %= MOD;
        }
      }
      
      ans += dp[i];
      ans %= MOD;
    }
    ++ rq;
  }
  cout << ans << "\n";
  return 0;
}