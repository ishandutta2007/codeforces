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

#define mt make_tuple
#define mp make_pair
#define F first
#define S second

int ioc(char c){
  switch(c){
    case 'R': return 0;
    case 'G': return 1;
    case 'B': return 2;
    case 'Y': return 3;
    case 'W': return 4;
  }
}

int ioc2(char c){
  switch(c){
    case '1': return 0;
    case '2': return 1;
    case '3': return 2;
    case '4': return 3;
    case '5': return 4;
  }
}

bitset<5> A[6];
bitset<5> B[6];

ll solve(){
  ll sol = 10;
  FOR(a, 32) FOR(b, 32){
    bitset<5> C(a);
    bitset<5> D(b);
    ll CNT[6][6]; FOR(i, 6) FOR(j, 6) CNT[i][j] = 0;
    FOR(i, 5) FOR(j, 5){
      if(A[i][j]){
        CNT[C[i] == 0 ? 0 : i+1][D[j] == 0 ? 0 : j+1] += 1;
      }
    }
    FOR(i, 6) FOR(j, 6) if(CNT[i][j] > 1) goto ugly_label;
    // cout << "OK" << endl;
    sol = min<ll>(sol, C.count() + D.count());
ugly_label:
 int osef = 0;
  }
  return sol;
}

int main(int, char**){
  ios::sync_with_stdio(false);
  ll n; cin >> n;
  FOR(i, 5) A[i].reset();
  FOR(i, 5) B[i].reset();
  FOR(i, n){
    char c, d;
    cin >> c >> d;
    A[5][ioc2(d)] = true;
    A[ioc(c)][ioc2(d)] = true;
    B[5][ioc(c)] = true;
    B[ioc2(d)][ioc(c)] = true;
  }
  cout << solve() << endl;
  return 0;
}