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

const ll inf = (ll)1e18 + 10;

vector<ll> res, f1, f2;

void dfs(ll c, int idx, vector<int> P){
  if(idx == P.size()){
    res.push_back(c);
    return;
  }
  dfs(c, idx + 1, P);
  while(1){
    if(c >= (inf+P[idx])/P[idx]){
      break;
    }
    c *= P[idx];
    dfs(c, idx + 1, P);
  }
}

ll f(ll t){ 
  int p = f2.size();
  ll ans = 0;
  for(int i = 0 ; i < f1.size(); i ++ ){
    while(p > 0 && f1[i] > t/f2[p-1]){
      p -- ;
    }
    ans += p;
  }
  return ans;
}

int main(){
  fastIO;
  int n;
  cin >> n;
  vector<int> A, B;
  int x;
  for(int i = 1; i <= n; i ++ ){
    cin >> x;
    if(i <= 6) A.push_back(x);
    else B.push_back(x);
  }
  ll k;
  cin >> k;
  dfs(1ll, 0, A);
  f1 = res;
  res.clear();
  dfs(1ll, 0, B);
  f2 = res;
  res.clear();
  sort(f1.begin(), f1.end());
  sort(f2.begin(), f2.end());
  ll li = 1, ri = inf;
  ll mid;
  while(li < ri){
    mid = (li + ri) / 2;
    if(f(mid) < k)
      li = mid + 1;
    else
      ri = mid;
  }
  cout << li << "\n";
  return 0; 
}