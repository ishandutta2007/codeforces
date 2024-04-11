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

ll W[26];

int main(int, char**){
  string s; cin >> s;
  ll k; cin >> k;
  FOR(i, 26) cin >> W[i];
  ll WM = *max_element(W, W + 26);
  ll r = 0;
  FOR(i, s.size()){
    r += W[s[i] - 'a'] * (i + 1);
  }
  FORU(i, s.size(), s.size() + k - 1){
    r += WM * (i + 1);
  }
  cout << r << endl;
  return 0;
}