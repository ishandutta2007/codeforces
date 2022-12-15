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

int n, lis[1 << 20], rec[22], val;
int q;
long long inv[22], neutral[22];
vector<int> v;

int main() {
  // ios::sync_with_stdio(false);
  scanf("%d", &n);
  REP (i, (1 << n)) scanf("%d", &lis[i]);
  scanf("%d", &q);
  long long ans = 0;
  int half = 1;
  FOR (ii, 1, n) {
    for (int st = 0; st < (1 << n); st += half + half) {
      // BUG(st);
      int p1 = st;
      int p2 = st + half;
      int lat = -1;
      int cnt = 0;
      while (p1 < st + half && p2 < st + half + half) {
        if (lis[p1] <= lis[p2]) {
          if (lis[p1] == lat) cnt++;
          else {
            lat = lis[p1];
            cnt = 1;
          }
          v.pb(lis[p1++]);
        } else {
          // BUG(lat);
          // cout << ii << ' ' << st << endl;
          if (lis[p2] == lat) neutral[ii] += cnt;
          v.pb(lis[p2++]);
          inv[ii] += st + half - p1;
        }
      }
      FOR (i, p1, st + half - 1) v.pb(lis[i]);
      FOR (i, p2, st + half + half - 1) {
        // BUG(cnt);
        v.pb(lis[i]);
        if (lis[i] == lat) neutral[ii] += cnt;
      }
      REP (i, half + half) lis[st + i] = v[i];
      v.clear();
      // BUG(inv[ii]);
      // BUG(half);
      // REP (i, 4) cout << lis[i] << ' ';cout << endl;
    }
    ans += inv[ii];
    // cout << ii << ' ' << inv[ii] << endl;
    half *= 2;
  }
  // REP (i, 4) cout << lis[i] << ' ';cout << endl;
  // BUG(ans);
  // BUG(neutral[1]);
  // BUG(neutral[2]);
  while (q--) {
    scanf("%d", &val);
    FORD (i, val, 1) {
      rec[i]++;
      if (rec[i] & 1) ans += (1ll << (n + i - 2)) - 2 * inv[i] - neutral[i];
      else ans -= (1ll << (n + i - 2)) - 2 * inv[i] - neutral[i];
    }
    printf("%lld\n", ans);
  }
}