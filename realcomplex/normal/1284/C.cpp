#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll m;
const int N = (int)3e5 + 9;
ll f[N];

ll mult(ll a, ll b){
  return (a * 1ll * b) % m;
}

int main(){
  ll n;
  cin >> n >> m;
  f[0] = 1ll;
  for(int i = 1; i < N ; i ++ ){
    f[i] = (f[i - 1] * 1ll * i) % m;
  }
  ll res = 0;
  ll c;
  for(ll i = 1; i <= n; i ++ ){
    c = mult(f[i], f[n-i]);
    c = mult(c, n - i + 1);
    c = mult(c, n - i + 1);
    res = (res + c) % m;
  }
  cout << res;
  return 0;
}