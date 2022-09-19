#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <list>
#include <bitset>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
#include <cassert>
#include <array>

using namespace std;

#define ll long long
#define ull unsigned long long

#define FOR(i, n) for(ll i = 0; i < (n); ++i)
#define FORU(i, j, k) for(ll i = j; i <= (k); ++i)
#define FORD(i, j, k) for(ll i = j; i >= (k); --i)

#define pf push_front
#define pb push_back

#define mp make_pair
#define f first
#define s second

struct Node{
  Node(){}
  Node(ll s, ll l, ll r) : mL(l), mR(r), known_sum(s), df(0), dff(0){ }

  ll mL, mR;
  ll known_sum;
  ll df, dff;
};

ll   A[300000];
ll   F[1000000];
Node B[2000000];

const ll MOD = 1000000009;

struct Mat3{
  Mat3(){}
  static Mat3 ID(){
    Mat3 ret;
    ret.arr = {{1, 0, 0, 0, 1, 0, 0, 0, 1}};
    return ret;
  }
  static Mat3 INIT(){
    Mat3 ret;
    ret.arr = {{0, 1, 0, 1, 1, 0, 1, 0, 1}};
    return ret;
  }
  ll multV(ll a, ll b){
    return arr[6] * a + arr[7] * b;
  }
  Mat3 operator*(Mat3 const& other){
    Mat3 ret;
    FOR(i, 3) FOR(j, 3){
      ret.arr[3*i+j] = 0;
      FOR(k, 3){
        (ret.arr[3*i+j] += arr[3*i+k] * other.arr[3*k+j])%=MOD;
      }
    }
    return ret;
  }
  array<ll, 9> arr;
};

Mat3 FF[1000000];

ll sum_from_to(ll l, ll r, ll fi){
  return F[fi + r - l] - ((fi==0)?0:F[fi-1]);
}

ll fib(ll i){
  return sum_from_to(0, 0, i);
}

void make_tree(ll ni, ll l, ll r){
  if(l == r){
    B[ni] = Node(A[l-1], l, r);
  }else{
    ll mid = (l + r) / 2;
    make_tree(2 * ni, l, mid);
    make_tree(2 * ni + 1, mid+1, r);
    B[ni] = Node(B[2*ni].known_sum + B[2*ni+1].known_sum, l, r);
  }
}

void update_tree(ll ni, ll l, ll r, ll fi){
  auto& N = B[ni];
  if(l == N.mL && r == N.mR){
    (N.df += fib(fi))%=MOD;
    (N.dff += fib(fi+1))%=MOD;
  }else{
    (N.known_sum += sum_from_to(l, r, fi))%=MOD;
    ll mid = (N.mL + N.mR) / 2;
    if(r <= mid) update_tree(2 * ni, l, r, fi);
    else if(l > mid) update_tree(2 * ni + 1, l, r, fi);
    else{
      update_tree(2 * ni, l, mid, fi);
      update_tree(2 * ni + 1, mid + 1, r, fi + mid + 1 - l);
    }
  }
}

void undirty_tree(ll ni){
  auto& N = B[ni];
  if(N.df){

    (N.known_sum+=FF[N.mR - N.mL + 1].multV(N.df, N.dff))%=MOD;

    if(N.mL != N.mR){
      auto& NL = B[2*ni];
      auto& NR = B[2*ni+1];
      (NL.df += N.df)%=MOD;
      (NL.dff += N.dff)%=MOD;
      ll k = NL.mR - NL.mL + 1;
      if(k == 1){
        (NR.df  += N.dff)%=MOD;
        (NR.dff += N.df + N.dff)%=MOD;
      }else{
        (NR.df  += fib(k-2) * N.df + fib(k-1) * N.dff)%=MOD;
        (NR.dff += fib(k-1) * N.df + fib(k-0) * N.dff)%=MOD;
      }
    }
    N.df  = 0;
    N.dff = 0;
  }
}

ll get_tree(ll ni, ll l, ll r){
  auto& N = B[ni];
  undirty_tree(ni);
  if(N.mL == l && N.mR == r) return N.known_sum;
  else{
    ll mid = (N.mL + N.mR) / 2;
    if(r <= mid) return get_tree(2 * ni, l, r);
    else if(l > mid) return get_tree(2 * ni + 1, l, r);
    else{
      return get_tree(2 * ni, l, mid) + get_tree(2 * ni + 1, mid + 1, r) % MOD;
    }
  }
}

ll sf_mod(ll a){
  ll r = a % MOD;
  return r<0?r+MOD:r;
}

int main(int, char**){
  ios::sync_with_stdio(false);
  F[0] = 1; F[1] = 1; FORU(i, 2, 999999) F[i] = (F[i-1] + F[i-2]) % MOD;
  FORU(i, 1, 999999) { F[i] += F[i-1]; F[i] %= MOD; }
  FF[0] = Mat3::ID();
  FF[1] = Mat3::INIT();
  FORU(i, 2, 999999) FF[i] = FF[i-1] * FF[1];

  ll n, m; cin >> n >> m;
  FOR(i, n) cin >> A[i];

  make_tree(1, 1, n);

  FOR(osef, m){
    ll x,l,r; cin >> x >> l >> r;
    if(x == 1){
      update_tree(1, l, r, 0);
    }else{
      printf("%d\n", sf_mod(get_tree(1, l, r)));
    }
  }
  return 0;
}