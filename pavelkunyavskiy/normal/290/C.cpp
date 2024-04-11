#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <sstream>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <cstdlib>
#include <cstdio>
#include <iterator>
#include <functional>
#include <bitset>
#define mp make_pair
#define pb push_back

#ifdef LOCAL
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
#define eprintf(...)
#endif

#define TIMESTAMP(x) eprintf("["#x"] Time : %.3lf s.\n", clock()*1.0/CLOCKS_PER_SEC)

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

#define TASKNAME "C"

typedef long long ll;
typedef long double ld;


int main(){
  #ifdef LOCAL
    freopen(TASKNAME".in","r",stdin);
    freopen(TASKNAME".out","w",stdout);
  #endif

  //HAI
  //I HAS A TUX
  ll TUX;
  //GIMMEH TUX
  cin >> TUX;
  //I HAS A FOO ITS 0
  ll FOO = 0;
//  I HAS A BAR ITS 0
  ll BAR = 0;
//  I HAS A BAZ ITS 0
  ll BAZ = 0;
//  I HAS A QUZ ITS 1
  ll QUZ = 1;
//  TUX IS NOW A NUMBR
//  IM IN YR LOOP NERFIN YR TUX TIL BOTH SAEM TUX AN 0 ???
  while (TUX-- > 0){
//  I HAS A PUR
    ll PUR;
//  GIMMEH PUR
    cin >> PUR;
//  PUR IS NOW A NUMBR
//  FOO R SUM OF FOO AN PUR
    FOO = FOO + PUR;     
//  BAR R SUM OF BAR AN 1
    BAR = BAR + 1;
//  BOTH SAEM ((BIGGR OF PRODUKT OF FOO AN QUZ AN PRODUKT OF BAR BAZ) AN (PRODUKT OF FOO AN QUZ))
//  O RLY?
//  YA RLY
    if (max(FOO * QUZ, BAR * BAZ) == FOO * QUZ) {
//  BAZ R FOO
//  QUZ R BAR
        BAZ = FOO;
        QUZ = BAR;
    }        
//  OIC
//  IM OUTTA YR LOOP
    }
//  BAZ IS NOW A NUMBAR
//  VISIBLE SMOOSH QUOSHUNT OF BAZ QUZ
    printf("%.10lf",BAZ * 1.0 / QUZ);
//  KTHXBYE
  TIMESTAMP(end);
  return 0;
}