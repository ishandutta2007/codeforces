#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 9;
int n;
vector<ll> p;

ll x, y, a, b;

ll check(int m){ 
  m=min(m,n);
  int ps = 0;
  ll tot = 0;
  for(int i = 1; i <= m; i ++ ){
    if(i % a == 0 && i % b == 0){
      tot += (p[ps] * (x + y)) / 100ll;
      ps ++ ;
    }
  }
  if(x > y){
    for(int i = 1; i <= m; i ++ ){
      if(i % a == 0 && i % b == 0) continue;
      if(i % a == 0){
        tot += (p[ps] * x) / 100ll;
        ps ++ ;
      }
    }
    for(int i = 1; i <= m; i ++ ){
      if(i % a == 0 && i % b == 0) continue;
      if(i % b == 0){
        tot += (p[ps] * y) / 100ll;
        ps ++ ;
      }
    }
  }
  else{
    for(int i = 1; i <= m; i ++ ){
      if(i % a == 0 && i % b == 0) continue;
      if(i % b == 0){
        tot += (p[ps] * y) / 100ll;
        ps ++ ;
      }
    }
    for(int i = 1; i <= m; i ++ ){
      if(i % a == 0 && i % b == 0) continue;
      if(i % a == 0){
        tot += (p[ps] * x) / 100ll;
        ps ++ ;
      }
    }
  }
  return tot;
}

void solve(){
  cin >> n;
  p.resize(n);
  for(int i = 0 ; i < n ; i ++ )
    cin >> p[i];
  sort(p.begin(), p.end());
  reverse(p.begin(), p.end());
  cin >> x >> a >> y >> b;
  ll k;
  cin >> k;
  int l = 0, r = n;
  int m;
  while(l < r){
    m = (l + r) / 2;
    if(check(m) >= k)
      r = m;
    else
      l = m + 1;
  }
  if(check(r) < k)
    cout << -1 << "\n";
  else
    cout << r << "\n";
}

int main(){ 
  fastIO;
  int qr;
  cin >> qr;
  for(int t = 0 ; t < qr; t ++ )
    solve();
  return 0;
}