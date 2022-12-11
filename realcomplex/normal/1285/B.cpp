#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void solve(){
  int n;
  cin >> n;
  multiset<ll> pf;
  multiset<ll> a1, a2;
  pf.insert(0ll);
  ll a;
  ll s = 0;
  for(int i = 1; i <= n; i ++ ){
    cin >> a;
    s += a;
    auto it = pf.begin();
    for(int j = 0 ; j < 2; j ++ ){
      if(it != pf.end()){
        a1.insert(s-*it);
        if(i!=n)a2.insert(s-*it);
        it++;
      }
    }
    if(i==n){
      pf.erase(pf.find(0));
      it = pf.begin();
      for(int j = 0 ; j < 2; j ++ ){
        if(it != pf.end()){
          a2.insert(s-*it);
          it++;
        }
      }
    }
    pf.insert(s);
  }
  auto i1 = a1.end();
  --i1;
  auto i2 = a2.end();
  --i2;
  if(*i1 > *i2){
    cout << "YES\n";
  }
  else{
    cout << "NO\n";
  }
}

int main(){
  fastIO;
  int testc;
  cin >> testc;
  for(int tt = 1; tt <= testc; tt ++ ){
    solve();
  }
  return 0;
}