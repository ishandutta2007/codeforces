#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <cstdlib>
#include <memory>
#include <queue>
#include <cassert>
#include <cmath>
#include <ctime>

using namespace std;

#define pb push_back
#define f first
#define s second
#define mp make_pair 
#define sz(C) ((int) (C).size())
#define forn(i, n) for (int i = 0; i < (int) n; ++i)
#define ford(i, n) for (int i = ((int) n) - 1; i >= 0; --i)
#define y1 gftxdtrtfhyjfctrxujkvbhyjice
#define y0 ehfoiuvhefroerferjhfjkehfjke
#define left sdhfsjkshdjkfsdfgkqqweqweh
#define right yytrwtretywretwreytwreytwr
#define all(C) begin(C), end(C)

#define debug(x) cerr << #x" = " << x << '\n';

template <typename T>
inline T sqr(T x) {
  return x * x;
}

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair <int,int> pii;
typedef pair <ll, ll> pll;
typedef vector <ll> vll;
typedef vector <int> vi;
typedef vector <vector <int> > vvi;
typedef vector <pii> vii;

const double EPS = 1e-9;

void ret() {
  printf("-1 -1\n");
  exit(0);
}

bool can(int m, int S) {
  return 0 <= S && S <= m * 9;
}
 
string get(int g) {
  string s;
  s += '0' + g;
  return s;
}

string get_mn(int m, int S, bool first) {
  if  (!can(m, S)) {
    ret();
    return "";
  }

  if  (m == 1) {
    return get(S);  
  }

  for (int i = (first ? 1 : 0); i <= 9; ++i) {
    if  (can(m - 1, S - i)) {
      return get(i) + get_mn(m - 1, S - i, 0);
    }
  }      

  return "";
}

string get_mx(int m, int S, bool first) {
  if  (!can(m, S)) {
    ret();
    return "";
  }

  if  (m == 1) {
    return get(S);  
  }

  for (int i = 9; i >= (first ? 1 : 0); --i) {
    if  (can(m - 1, S - i)) {
      return get(i) + get_mx(m - 1, S - i, 0);
    }
  }

  return "";    
}

int main() {
#ifdef LOCAL
  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
#endif

  int m, S;
  scanf("%d%d", &m, &S);

  if  (S == 0) {
    if  (m > 1) {
      ret();
    }
    printf("0 0");
    return 0;
  }

  auto mn = get_mn(m, S, 1);
  auto mx = get_mx(m, S, 1);

  cout << mn << " ";
  cout << mx << endl;  

  return 0;
}