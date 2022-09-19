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

enum DIR{
  D1, D2, D3, D4, D6, D7, D8, D9
};

bool A[500][500];
ll C[502][502][8];

int main(int, char**){
  ios::sync_with_stdio(false);
  ll n, m; cin >> n >> m;
  FOR(i, n) FOR(j, m) { char c; cin >> c; A[i][j] = c == '0'; }

  auto inB = [&](ll i, ll j){ return i < n && j < m && 0 <= i && 0 <= j; };

  FOR(i, n+2) FOR(j, m+2) FOR(d, 8) C[i][j][d] = 0;

  FOR(j, m) FOR(i, n) C[i+1][j+1][D4] = A[i][j] * (C[i+1][j][D4] + 1);
  FORD(j, m-1, 0) FOR(i, n) C[i+1][j+1][D6] = A[i][j] * (C[i+1][j+2][D6] + 1);
  FOR(i, n) FOR(j, m) C[i+1][j+1][D8] = A[i][j] * (C[i][j+1][D8] + 1);
  FORD(i, n-1, 0) FOR(j, m) C[i+1][j+1][D2] = A[i][j] * (C[i+2][j+1][D2] + 1);

  FORU(ipj, 0, n+m){
    FORU(i, 0, n){
      ll j = ipj - i;
      if(inB(i, j)){
        C[i+1][j+1][D7] = A[i][j] * (C[i][j][D7] + 1);
        C[n-i][j+1][D1] = A[n-i-1][j] * (C[n-i+1][j][D1] + 1);
        C[i+1][m-j][D9] = A[i][m-j-1] * (C[i][m-j+1][D9] + 1);
        C[n-i][m-j][D3] = A[n-i-1][m-j-1] * (C[n-i+1][m-j+1][D3] + 1);
      }
    }
  }

  FOR(i, n+2) FOR(j, m+2) FOR(d, 8) C[i][j][d] -= 1;
//   FOR(i, n+2){

//     FOR(j, m+2) {
//       cout << C[i][j][D9] << "\t";
//   }cout << endl;
// }


  ll r = 0;

  FOR(i, n) FOR(j, m){
    // (i, j) H
    for(ll p = 2; p <= min(C[i+1][j+1][D6], 2*C[i+1][j+1][D3]); p += 2){
      if(C[i+1+p/2][j+1+p/2][D9] >= p/2){
        r += 1;
      }
    }
    for(ll p = 2; p <= min(C[i+1][j+1][D6], 2*C[i+1][j+1][D9]); p += 2){
      if(C[i+1-p/2][j+1+p/2][D3] >= p/2){
        r += 1;
      }
    }
    for(ll p = 2; p <= min(C[i+1][j+1][D2], 2*C[i+1][j+1][D3]); p += 2){
      if(C[i+1+p/2][j+1+p/2][D1] >= p/2){
        r += 1;
      }
    }
    for(ll p = 2; p <= min(C[i+1][j+1][D2], 2*C[i+1][j+1][D1]); p += 2){
      if(C[i+1+p/2][j+1-p/2][D3] >= p/2){
        r += 1;
      }
    }

    // V
    for(ll p = 1; p <= min(C[i+1][j+1][D6], C[i+1][j+1][D3]); p += 1){
      if(C[i+1][j+1+p][D2] >= p){
        r += 1;
      }
    }
    for(ll p = 1; p <= min(C[i+1][j+1][D6], C[i+1][j+1][D9]); p += 1){
      if(C[i+1][j+1+p][D8] >= p){
        r += 1;
      }
    }
    for(ll p = 1; p <= min(C[i+1][j+1][D4], C[i+1][j+1][D1]); p += 1){
      if(C[i+1][j+1-p][D2] >= p){
        r += 1;
      }
    }
    for(ll p = 1; p <= min(C[i+1][j+1][D4], C[i+1][j+1][D7]); p += 1){
      if(C[i+1][j+1-p][D8] >= p){
        r += 1;
      }
    }
  }

  cout << r << endl;

  return 0;
}