#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
  fastIO;
  int n;
  cin >> n;
  pii x[n];
  for(int i = 0 ; i < n ; i ++ ){
    cin >> x[i].fi;
  }
  for(int i = 0 ; i < n ; i ++ ){
    cin >> x[i].se;
  }
  sort(x, x + n);
  ll res = 0 ;
  ll cur = 0;
  priority_queue<ll> cc;
  ll p;
  ll nx;
  for(int i = 0 ; i < n ; i ++ ){
    cc.push(x[i].se);
    cur += x[i].se;
    if(i + 1 == n || x[i].fi != x[i + 1].fi){
      p = x[i].fi;
      if(i + 1 == n) nx = (ll)2e9;
      else nx = x[i + 1].fi;
      while(!cc.empty() && p < nx){
        cur -= cc.top();
        cc.pop();
        res += cur;
        p ++ ;
      }
    }
  }
  cout << res << "\n";
  return 0;
}