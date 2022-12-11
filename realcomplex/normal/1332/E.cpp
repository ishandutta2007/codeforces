#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

// FUCK MATRIX EXPONENTION!!!!!!!!!!!!!!

const int MOD = 998244353;

vector<vector<ll>> mult(vector<vector<ll>> A, vector<vector<ll>> B){
  vector<vector<ll>> C(2);
  for(int i = 0 ; i < 2; i ++ ){
    C[i].resize(2);
    for(int j = 0 ; j < 2; j ++ ){
      for(int x = 0; x < 2; x ++ ){
        C[i][j] += (A[i][x] *1ll * B[x][j]) % MOD;
        C[i][j] %= MOD;
      }
    }
  }
  return C;
}

vector<vector<ll>> powr(vector<vector<ll>> A, ll k){
  if(k == 0){
    return {{1,0},{0,1}};
  }
  vector<vector<ll>> p = powr(A,k/2);
  p = mult(p, p);
  if(k % 2 == 1) p = mult(p, A);
  return p;
}

ll f(ll n, ll bit, ll A, ll B){
  if(n == 0) return (bit != 1);
  vector<vector<ll>> init = {{1,0},{0,0}};
  vector<vector<ll>> P = powr({{A,B},{B,A}},n);
  init = mult(init, P);
  return init[0][bit];
}

int main(){
  fastIO;
  ll n, m, l, r;
  cin >> n >> m >> l >> r;
  ll WHITE = (n/2) * (m/2) + (n+1)/2 * (m+1)/2;
  ll BLACK = n * m - WHITE;
  ll w0, w1;
  w0 = w1 = (r - l + 1)/2;
  if((r - l + 1) % 2 == 1){
    if(l % 2 == 1) w1 ++ ;
    else w0 ++ ;
  }
  ll ans = (f(WHITE,0,w0,w1) * 1ll * f(BLACK,0,w0,w1)) % MOD;
  ans += (f(WHITE,1,w0,w1) * 1ll * f(BLACK,1,w0,w1)) % MOD;
  if(WHITE % 2 != BLACK % 2){
    ans += (f(WHITE,1,w0,w1) * 1ll * f(BLACK,0,w0,w1)) % MOD;
    ans += (f(WHITE,0,w0,w1) * 1ll * f(BLACK,1,w0,w1)) % MOD;
  }
  ans %= MOD;
  cout << ans << "\n";
  return 0;
}