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

ll A[1000];
string B[1000];

int main(int, char**){
  ios::sync_with_stdio(false);
  ll n; cin >> n;
  FOR(i, n) cin >> A[i];
  ll width = accumulate(A, A+n, 0);
  FOR(i, 1000) B[i] = string(width, ' ');

  ll spos = 0;
  ll cpos = 0;
  FOR(i, n){
    cpos += ((i%2)?1:-1) * A[i];
    spos = max(spos, -cpos);
  }

  cpos = spos-1;
  ll dpos = 0;
  ll mpos = cpos;
  FOR(i, n){
    if(i%2){
      FOR(j, A[i]){
        B[cpos][dpos] = '\\';
        cpos += 1;
        dpos += 1;
      }
      cpos -= 1;
    }else{
      FOR(j, A[i]){
        B[cpos][dpos] = '/';
        cpos -= 1;
        dpos += 1;
      }
      cpos += 1;
    }
    mpos = max(mpos, cpos);
  }

  FOR(i, mpos+1) cout << B[i] << "\n";

  return 0;
}