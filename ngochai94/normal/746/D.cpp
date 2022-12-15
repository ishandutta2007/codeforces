#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)
#define REP(i,a) FOR(i,0,(int)(a)-1)
#define reset(a,b) memset(a,b,sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl
#define PR(x,a,b) {cout << #x << " = "; FOR (_,a,b) cout << x[_] << ' '; cout << endl;}
#define mod 1000000007
#define pi acos(-1)
#define eps 0.00000001
#define pb push_back
#define sqr(x) (x) * (x)
#define _1 first
#define _2 second

long long n, a, b, k;

int main() {
  ios::sync_with_stdio(false);
  cin >> n >> k >> a >> b;
  if (a > (b + 1) * k || b > (a + 1) * k) {
    cout << "NO";
    return 0;
  }
  char G = 'G';
  char B = 'B';
  if (a < b) {
    swap(a, b);
    swap(G, B);
  }
  if (a == b) {
    REP (i, a) cout << "GB";
    return 0;
  }
  REP (i, a % (b + 1)) {
    REP (j, a / (b + 1) + 1) cout << G;
    cout << B;
  }
  REP (i, b + 1 - a % (b + 1)) {
    REP (j, a / (b + 1)) cout << G;
    if (i != b - a % (b + 1)) cout << B;
  }
}