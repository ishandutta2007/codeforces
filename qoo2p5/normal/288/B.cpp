#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int INF = 1e9;
const int MOD = 1e9 + 7;

ll power(ll a, ll p) {
  if (p == 0) return 1;
  
  if (p & 1) {
    return (a * power(a, p - 1)) % MOD;
  } else {
    ll tmp = power(a, p / 2);
    return (tmp * tmp) % MOD;
  }
}

ll fact(int x) {
  ll res = 1;
  for (int i = 1; i <= x; i++) res = (res * i) % MOD;
  return res;
}

ll tree[10];
ll precalc[10][10];

void solve(int cur = 0, vector<int> state = vector<int>()) {
  for (int j = 0; j < 10; j++) {
    ll t = 1;
    for (int i : state) {
      t = (t * tree[i]) % MOD;
      t = (t * j) % MOD;
    }
    precalc[cur][j] += t;
    if (precalc[cur][j] >= MOD) precalc[cur][j] -= MOD;
  }
  
  if (cur == 8) {
    return;
  }
  
  for (int i = 0; i < state.size(); i++) {
    vector<int> nstate = state;
    nstate[i]++;
    solve(cur + 1, nstate);
  }
  
  {
    vector<int> nstate = state;
    nstate.push_back(1);
    solve(cur + 1, nstate);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  
  #ifdef LOCAL
  freopen("input.txt", "r", stdin);
  #endif
  
  int n, k;
  cin >> n >> k;
  
  tree[1] = 1;
  for (int i = 2; i < 10; i++) tree[i] = power(i, i - 1);
  
  solve();
  
  ll left = 0;
  ll right = power(n - k, n - k);
  
  for (int mask = 0; mask < (1 << k); mask++) {
    if (!(mask & 1)) continue;
    
    int cnt = 0;
    for (int j = 0; j < k; j++) {
      if (mask & (1 << j)) cnt++;
    }
            
    left += (fact(cnt - 1) * precalc[k - cnt][cnt]) % MOD;
    if (left >= MOD) left -= MOD;
  }
  
  cout << (left * right) % MOD << "\n";
  
  return 0;
}