#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (long long i = (a); i <= (b); i++)
#define FORD(i,a,b) for (long long i = (a); i >= (b); i--)
#define REP(i,a) FOR(i,0,(a)-1)
#define reset(a,b) memset(a,b,sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl
#define mod 1000000007
#define pi acos(-1)
#define eps 0.00000001
#define pb push_back
#define sqr(x) (x) * (x)
#define _1 first
#define _2 second

int n, k, h[333][333];
vector<pair<long double, long double> > pivot[333], tmp;
long double ans;

int main(){
  ios::sync_with_stdio(0);
  long double zero = 0.0;
  cin >> n >> k;
  REP (i, n) FOR (j, 0, k) cin >> h[i][j];
  ans = 0;
  REP (i, k) {
    ans += (h[0][i] + h[0][i + 1]) / 2.0;
    pivot[i].pb({0, h[0][i]});
    pivot[i].pb({1, h[0][i + 1]});
  }
  cout << setprecision(11) << ans << endl;
  FOR (i, 1, n - 1) {
    ans = 0;
    REP (j, k) {
      long double lef = h[i][j];
      long double rig = h[i][j + 1];
      tmp.clear();
      tmp.pb({0, max(pivot[j][0]._2, lef)});
      REP (z, pivot[j].size() - 1) {
        long double olef = pivot[j][z]._2;
        long double orig = pivot[j][z + 1]._2;
        long double x1 = pivot[j][z]._1;
        long double x2 = pivot[j][z + 1]._1;
        long double nlef = lef + (rig - lef) * x1;
        long double nrig = lef + (rig - lef) * x2;
        if (olef > nlef && orig < nrig || olef < nlef && orig > nrig) {
          long double midx = (x2 * (olef - nlef) + x1 * (nrig - orig)) / (olef - nlef + nrig - orig);
          long double midy = nlef + (nrig - nlef) * (midx - x1) / (x2 - x1);
          tmp.pb({midx, midy});
          ans += max(zero, (nrig - orig) * (x2 - midx) / 2.0) + max(zero, (nlef - olef) * (midx - x1) / 2.0);
        }
        if (nlef >= olef && nrig >= orig) ans += (nrig + nlef - orig - olef) * (x2 - x1) / 2.0;
        tmp.pb({x2, max(orig, nrig)});
      }
      pivot[j] = tmp;
    }
    cout << setprecision(11) << ans << endl;
  }
}