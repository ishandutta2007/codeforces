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

int n, k, d[100005], cnt[100005];
vector<pair<int, int> > v, ans;
vector<int> avai[100005];

int main() {
  ios::sync_with_stdio(false);
  cin >> n >> k;
  FOR (i, 1, n) cin >> d[i];
  int cntt = 0;
  int root = 0;
  FOR (i, 1, n) if (d[i] == 0) {
    root = i;
    cntt++;
  }
  if (cntt != 1) {
    cout << -1;
    return 0;
  }
  FOR (i, 1, n) if (d[i]) v.pb({d[i], i});
  sort(v.begin(), v.end());
  avai[1].pb(root);
  for (auto p: v) {
    if (avai[p._1].empty()) {
      cout << -1;
      return 0;
    }
    int x = avai[p._1].back();
    ans.pb({x, p._2});
    cnt[x]++;
    cnt[p._2]++;
    if (cnt[p._2] < k) avai[p._1 + 1].pb(p._2);
    if (cnt[x] == k) avai[p._1].pop_back();
  }
  cout << ans.size() << endl;
  for (auto p: ans) cout << p._1 << ' ' << p._2 << endl;
}