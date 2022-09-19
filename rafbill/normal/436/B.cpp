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
  ll n, m, k; cin >> n >> m >> k;
  FOR(i, m) A[i] = 0;
  FOR(i, n) FOR(j, m){
    char c; cin >> c;
    switch(c){
    case 'U':
      A[j] += ((i+1) % 2);
      break;
    case 'R':
      if(i+j < m) A[i+j] += 1;
      break;
    case 'L':
      if(j-i >= 0) A[j-i] += 1;
      break;
    }
  }
  FOR(i, m) cout << A[i] << " "; cout << endl;
  return 0;
}