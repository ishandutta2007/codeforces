#pragma optimize ("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef double db;
typedef pair<ll,ll> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);
#define TEST freopen("in.txt","r",stdin);
#define _ones(a) __builtin_popcount(a)

ll choose(ll n, ll k){
  ll ans = 1;
  for(ll i = k + 1; i <= n;i ++ ){
    ans *= i;
    ans /= i - k;
  }
  return ans;
}

ll calc = 0;

ll cnt[10];

void apply_combinatorics(ll chosen[]){
  int rem = 0;
  for(int i = 0;i < 10;i ++ )
    rem += chosen[i];
  ll tot = 1LL;
  if(chosen[0] != 0){
    tot *= choose(rem - 1, chosen[0]);
    rem -= chosen[0];
  }
  for(int i = 1;i < 10;i ++ ){
    if(chosen[i] == 0)
      continue;
    tot *= choose(rem, chosen[i]);
    rem -= chosen[i];
  }
  calc += tot;
}

void brute_force(int p, ll current[]){
  if(p == 10){
    apply_combinatorics(current);
    return;
  }
  if(cnt[p] == 0){
    current[p] = 0;
    brute_force(p + 1, current);
    return;
  }
  for(ll k = 1;k <= cnt[p]; k ++ ){
    current[p] = k;
    brute_force(p + 1, current);
  }
}

int main(){
  fastIO;
  string s;
  cin >> s;
  for(char x : s){
    cnt[x - '0'] ++ ;
  }
  ll store[10];
  memset(store, 0, sizeof store);
  brute_force(0, store);
  cout << calc;
  return 0;
}