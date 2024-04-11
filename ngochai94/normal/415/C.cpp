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

int n, k;

int main() {
  ios::sync_with_stdio(false);
  cin >> n >> k;
  if (n / 2 > k || k && n < 2) {
    cout << -1;
    return 0;
  }
  if (n == 1) {
    cout << 1;
    return 0;
  }
  k -= n / 2 - 1;
  cout << k << ' ' << k * 2 << ' ';
  FOR (i, 3, n) cout << 500000000 + i << ' ';
}