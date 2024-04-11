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

ll A[2001];

int main(int, char**){
  ios::sync_with_stdio(false);
  string s; ll k; cin >> s >> k;
  ll cl = 0;
  FORU(l, 1, (s.size() + k) / 2){
    ll cons = 0;
    FORU(n, 0, s.size() + k - l - 1){
      if(n+l >= s.size() || s[n] == s[n+l]) cons += 1;
      else cons = 0;
      if(cons >= l) cl = l;
    }
  }
  cout << 2*cl << endl;
  return 0;
}