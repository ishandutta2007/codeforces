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
  ll n, a, b, k;
  cin >> n >> a >> b >> k;
  ll h;
  vector<ll> dd;
  for(int i = 1; i <= n; i ++ ){
    cin >> h;
    h %= (a + b);
    if(h==0)h=(a+b);
    dd.push_back((h+a-1)/a-1);
  }
  sort(dd.begin(), dd.end());
  ll res = 0;
  for(auto x : dd){
    if(k - x >= 0){
      k -= x;
      res ++ ;
    }
  }
  cout << res << "\n";
  return 0;
}