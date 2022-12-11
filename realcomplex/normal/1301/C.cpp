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
  for(int i = 0 ; i < tc; i ++ ){
    ll n, m;
    cin >> n >> m;
    ll z = n - m;
    ll q = m+1;
    ll k = z/q;
    ll res = q * k * 1ll * (k + 1) / 2ll;
    z -= q * k;
    res += (k + 1) * z;
    cout << n*(n+1)/2ll-res<<"\n";
  }
  return 0;
}