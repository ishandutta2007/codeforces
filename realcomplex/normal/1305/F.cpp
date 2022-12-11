#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

map<ll,int> pri;
vector<ll> tri;

void add(ll x){ 
  if(!pri.count(x)){
    pri[x]=1;
    tri.push_back(x);
  }
}

void fac(ll x){ 
  for(ll i = 2; i * i <= x; i ++ ){
    if(x % i == 0){
      add(i);
      while(x % i == 0)
        x /= i;
    }
  }
  if(x != 1)
    add(x);
}

int main(){
  fastIO;
  int n;
  cin >> n;
  vector<ll> cur(n);
  for(int i = 0 ; i < n; i ++ ){
    cin >> cur[i];
  }
  int id;
  for(int T = 0; T < 20; T ++ ){
    id = ((int)rng() % n + n) % n;
    fac(cur[id]);
    if(cur[id] > 1)fac(cur[id]-1);
    fac(cur[id]+1);
  }
  ll ans = n;
  ll rr = 0;
  ll mod;
  for(auto p : tri){
    rr = 0;
    for(int i = 0 ; i < n; i ++ ){
      mod = cur[i] % p;
      if(cur[i] < p)
        rr += p - mod;
      else
        rr += min(mod, p - mod);
    }
    ans = min(ans, rr);
  }
  cout << ans << "\n";
  return 0;
}