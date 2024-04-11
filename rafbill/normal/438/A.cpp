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

ll V[1000];
ll I[1000];

int main(int, char**){
  ios::sync_with_stdio(false);
  ll n, m; cin >> n >> m;
  FOR(i, n) cin >> V[i];
  ll r = 0;
  FOR(i, m){
    ll x, y; cin >> x >> y;
    r += min(V[x-1], V[y-1]);
  }
  cout << r << endl;

  return 0;
}