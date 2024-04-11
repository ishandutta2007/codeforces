#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int K = (int)2e5 + 10;
const int N = K * 2 + 100;
vector<pii> F[2];

int main(){
  //fastIO;
  int n;
  cin >> n;
  int x, y;
  int p, q;
  for(int i = 0 ; i < n ; i ++ ){
    cin >> x >> y;
    p = x + y + K;
    q = y - x + K; 
    F[p % 2].push_back(mp(p, q));
  }
  int pi;
  int l, r;
  ll ans = 0;
  for(int par = 0; par < 2 ; par ++ ){
    for(auto &x : F[par]){
      x.fi /= 2;
      x.se /= 2;
    }
    multiset<int> aa, bb;
    sort(F[par].begin(), F[par].end());
    for(auto t : F[par])
      bb.insert(t.se);
    pi = 0;
    for(int i = 0 ; i < N; i ++ ){
      while(pi < F[par].size() && F[par][pi].fi <= i){
        aa.insert(F[par][pi].se);
        bb.erase(bb.find(F[par][pi].se));
        pi ++ ;
      }
      if(aa.size() <= 1 || bb.size() <= 1) continue;
      l = 0, r = N - 1;
      auto it = aa.begin();
      l = max(l, *it);
      it = bb.begin();
      l = max(l, *it);
      it = aa.end();
      -- it;
      r = min(r, *it);
      it = bb.end();
      -- it;
      r = min(r, *it);
      ans += max(0, r - l);
    }
  }
  cout << ans << "\n";
  return 0;
}