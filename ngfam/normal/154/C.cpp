#include <bits/stdc++.h>

using namespace std;

const int N = 1000100;
const long long mod = 1000037299;
const long long mod2 = 1000000007;

int n, m;
long long Hash[N];
long long Hash2[N];
pair < long long, long long > mask[N];
pair < long long, long long > old[N];

long long powmd(int u, int v, long long modun){
  if(modun == mod){
    return Hash[v];
  }
  else{
    return Hash2[v];
  }
}

int main(){
  #ifdef pts
    freopen("1.inp", "r", stdin);
  #endif
  scanf("%d%d", &n, &m);
  Hash[0] = Hash2[0] = 1;
  for(int i = 1; i <= n; ++i){
    Hash[i] = (Hash[i - 1] * 2) % mod;
    Hash2[i] = (Hash2[i - 1] * 2) % mod2;
  }
  for(int i = 1; i <= n; ++i){
    mask[i] = make_pair(powmd(2, i, mod), powmd(2, i, mod2));
  }
  for(int i = 1; i <= m; ++i){
    int u, v;
    scanf("%d%d", &u, &v);
    mask[u].first += powmd(2, v, mod);
    mask[u].second += powmd(2, v, mod2);
    mask[v].first += powmd(2, u, mod);
    mask[v].second += powmd(2, u, mod2);
    mask[u].first %= mod;
    mask[u].second %= mod2;
    mask[v].first %= mod;
    mask[v].second %= mod2;
  }
  for(int i = 1; i <= n; ++i){
    old[i] = mask[i];
  }
  sort(mask + 1, mask + n + 1);
  long long answer = 0;
  int cnt = 1;
  for(int i = 2; i <= n; ++i){
    if(mask[i] != mask[i - 1]){
      answer += (1LL * cnt * (cnt - 1)) / 2;
      cnt = 1;
    }
    else{
      ++cnt;
    }
  }
  answer += (1LL * cnt * (cnt - 1)) / 2;
  for(int i = 1; i <= n; ++i){
    mask[i] = old[i];
    mask[i].first -= powmd(2, i, mod);
    mask[i].second -= powmd(2, i, mod2);
    mask[i].first = (mask[i].first + mod) % mod;
    mask[i].second = (mask[i].second + mod2) % mod2;
  }
  sort(mask + 1, mask + n + 1);
  cnt = 1;
  for(int i = 2; i <= n; ++i){
    if(mask[i] != mask[i - 1]){
      answer += (1LL * cnt * (cnt - 1)) / 2;
      cnt = 1;
    }
    else{
      ++cnt;
    }
  }
  answer += (1LL * cnt * (cnt - 1)) / 2;
  cout << answer;
  return 0;
}