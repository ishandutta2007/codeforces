#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)
#define REP(i,a) FOR(i,0,(int)(a)-1)
#define reset(a,b) memset(a,b,sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl
#define mod 1000000007
#define pi acos(-1)
#define eps 0.00000001
#define pb push_back
#define sqr(x) (x) * (x)
#define _1 first
#define _2 second

int n;
string grid[333];

int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  REP (i, n) cin >> grid[i];
  bool flag = false;
  if (grid[0][0] == grid[0][1]) flag = true;
  REP (i, n) REP (j, n) {
    if (i == j || i + j == n - 1) {
      if (grid[i][j] != grid[0][0]) flag = true;
    } else {
      if (grid[i][j] != grid[0][1]) flag = true;
    }
  }
  if (flag) cout << "NO";
  else cout << "YES";
}