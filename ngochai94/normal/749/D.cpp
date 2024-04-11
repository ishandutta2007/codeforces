#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)
#define REP(i,a) FOR(i,0,(int)(a)-1)
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

int n, a, b, best[200005], k;
set<int> each[200005], bidder;
set<pair<int, int> > all;
vector<int> v;

int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  REP (i, n) {
    cin >> a >> b;
    each[a].insert(b);
    bidder.insert(a);
    best[a] = max(best[a], b);
  }
  for (int i: bidder) all.insert({best[i], i});
  int q;
  cin >> q;
  while (q--) {
    cin >> k;
    v.clear();
    int val;
    REP (i, k) {
      cin >> val;
      v.pb(val);
      all.erase({best[val], val});
    }
    auto it = all.end();
    if (it == all.begin()) cout << "0 0" << endl;
    else {
      it--;
      a = it->_2;
      cout << a << ' ';
      int tmp = 0;
      if (all.size() > 1) {
        it--;
        tmp = it->_1;
      }
      auto itt = each[a].upper_bound(tmp);
      cout << *itt << endl;
    }
    for (int i: v) if (best[i]) all.insert({best[i], i});
  }
}