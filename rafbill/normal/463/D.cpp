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

ll A[5][1000];
ll B[5][1000];

ll M[1000];

int main(int, char**){
  ios::sync_with_stdio(false);
  ll I[] = {0, 1, 2, 3, 4};
  ll n, k; cin >> n >> k;
  FOR(i, k) FOR(j, n){
    ll a; cin >> a;
    A[i][j] = a-1;
    B[i][a-1] = j;
  }

  ll r = 0;

  FOR(i, n) M[i] = 0;
  set<int> C;
  
  FOR(i, n){
    ll j = A[0][i];
    set<int> D;
    for(auto const& c : C){
      if(all_of(I, I+k, [&](ll a){
        return B[a][c] < B[a][j];
      })){
        D.insert(c);
      }
    }
    // for(auto const& d : D){ C.erase(d); }
    C.insert(j);
    M[j] = 1;
    for(auto const& d : D){
      M[j] = max(M[j], 1 + M[d]);
    }
  }

  FOR(i, n){
    // cout << i << " " << M[i] << endl;
    r = max(r, M[i]);
  }

  cout << r << endl;
  return 0;
}