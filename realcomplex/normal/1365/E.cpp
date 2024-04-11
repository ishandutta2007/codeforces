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
  int n;
  cin >> n;
  vector<ll> t(n);
  for(int i = 0 ; i < n; i ++ ){
    cin >> t[i];
  }
  ll res = 0;
  for(int i = 0 ; i < n; i ++ ){
    for(int j = 0 ; j < n; j ++ ){
      for(int k = 0; k < n; k ++ ){
        res = max(res, (t[i]|t[j]|t[k]));
      }
    }
  }
  cout << res << "\n";
  return 0;
}