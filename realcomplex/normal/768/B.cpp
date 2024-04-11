#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef long double db;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO std::ios::sync_with_stdio(false);cin.tie(NULL);
#define TEST freopen("in.txt","r",stdin);
#define ones(a) __builtin_popcount(a);
#define pq priority_queue

map<ll, ll> cnt;

ll fin(ll x){
  if(cnt[x] != 0)
    return cnt[x];
  if(x == 0 or x == 1){
    cnt[x] = 1;
    return 1;
  }
  cnt[x] = fin(x/2) + fin(x%2) + fin(x/2);
  return cnt[x];
}

ll ix(ll n, ll target){
  if(n <= 1)
    return n;
  ll li, md;
  li = fin(n/2);
  md = li + 1;
  if(li >= target){
    return ix(n/2, target);
  }
  if(md >= target){
    return n%2;
  }
  return ix(n/2, target - md);
}

int main(){
  fastIO;
  ll n, l, r;
  cin >> n >> l >> r;
  fin(n);
  ll sum = 0;
  for(ll j = l; j <= r;j ++ ){
    sum += ix(n, j);
  }
  cout << sum;
  return 0;
}