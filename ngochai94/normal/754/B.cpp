#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (long long i = (a); i <= (b); i++)
#define FORD(i,a,b) for (long long i = (a); i >= (b); i--)
#define REP(i,a) FOR(i,0,(long long)(a)-1)
#define reset(a,b) memset(a,b,sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl
#define PR(x,a,b) {cout << #x << " = "; FOR (_,a,b) cout << x[_] << ' '; cout << endl;}
#define CON(x) {cout << #x << " = "; for(auto i:x) cout << i << ' '; cout << endl;}
#define mod 1000000007
#define pi acos(-1)
#define eps 0.00000001
#define pb push_back
#define sqr(x) (x) * (x)
#define _1 first
#define _2 second

int n;
string grid[4];

bool ok() {
  REP (i, 4) REP (j, 2) {
    bool tmp = false;
    FOR (k, 0, 2) if (grid[i][j + k] != 'x') tmp = true;
    if (!tmp) return true;
  }
  REP (i, 4) REP (j, 2) {
    bool tmp = false;
    FOR (k, 0, 2) if (grid[j + k][i] != 'x') tmp = true;
    if (!tmp) return true;
  }
  REP (i, 2) REP (j, 2) {
    bool tmp = false;
    FOR (k, 0, 2) if (grid[i + k][j + k] != 'x') tmp = true;
    if (!tmp) return true;
  }
  REP (i, 2) FOR (j, 2, 3) {
    bool tmp = false;
    FOR (k, 0, 2) if (grid[i + k][j - k] != 'x') tmp = true;
    if (!tmp) return true;
  }
  return false;
}

int main() {
  // ios::sync_with_stdio(false);
  REP (i, 4) cin >> grid[i];
  REP (i, 4) REP (j, 4) if (grid[i][j] == '.') {
    grid[i][j] = 'x';
    if (ok()) {
      // BUG(i);
      // BUG(j);
      cout << "YES";
      return 0;
    }
    grid[i][j] = '.';
  }
  cout << "NO";
}