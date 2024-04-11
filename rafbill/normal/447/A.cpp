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
#include <tuple>

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

bool A[300];

int main(int, char**){
  ios::sync_with_stdio(false);
  ll n, p; cin >> p >> n;
  auto h = [&](ll x){ return x % p; };
  FOR(i, p) A[i] = false;
  FOR(i, n){
    ll x; cin >> x;
    ll hx = h(x);
    if(A[hx]){
      cout << i+1 << endl;
      return 0;
    }else{
      A[hx] = true;
    }
  }
  cout << -1 << endl;
  return 0;
}