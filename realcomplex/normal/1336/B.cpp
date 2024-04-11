#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
  fastIO;
  int tc;
  cin >> tc;
  for(int t = 1; t <= tc; t ++ ){
    int n[3];
    cin >> n[0] >> n[1] >> n[2];
    set<ll> c[3];
    ll x;
    ll ans = (ll)4e18;
    for(int i = 0 ; i < 3; i ++ ){
      for(int j = 0 ; j < n[i]; j ++ ){
        cin >> x;
        c[i].insert(x);
      }
    }
    vector<int> ord = {0,1,2};
    ll a, b;
    do{
      for(auto x : c[ord[1]]){
        auto it = c[ord[0]].upper_bound(x);
        if(it == c[ord[0]].begin()) continue;
        it--;
        a = x - (*it);
        it = c[ord[2]].lower_bound(x);
        if(it == c[ord[2]].end()) continue;
        b = (*it - x);
        ans = min(ans, 2ll * (a * a + b * b + a * b));
      }
    }while(next_permutation(ord.begin(),ord.end()));
    cout << ans << "\n";
  }
  return 0;
}