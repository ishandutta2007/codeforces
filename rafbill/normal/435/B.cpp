#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <list>
#include <bitset>
#include <set>
#include <queue>
#include <stack>

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

string solve(string s, ll k){
  if(k == 0 || s.size() <= 1) return s;
  else{
    ll i = 0; char c = s[i];
    FOR(j, min<ll>(k+1, s.size())){
      if(s[j] > c) { i = j; c = s[j]; }
    }
    FORD(j, i-1, 0) s[j+1] = s[j];
    return string() + c + solve(s.substr(1), k-i);
  }
}

int main(int, char**){
  ios::sync_with_stdio(false);
  string s; ll k; cin >> s >> k;
  cout << solve(s, k) << endl;
  return 0;
}