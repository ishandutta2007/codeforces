#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)
#define REP(i,a) FOR(i,0,(int)(a)-1)
#define reset(a,b) memset(a, b, sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl;
#define BUGP(x) cout << #x << " = " << x._1 << ", " << x._2 << endl;
#define pb push_back
#define _1 first
#define _2 second
#define PR(x,a,b) { cout << #x << " = "; FOR(_,a,b) cout << x[_] << ' '; cout << endl; }
#define CON(x) { cout << #x << " = "; for (auto i: x) cout << i << ' '; cout << endl; }
#define eps 1e-9
#define sqr(x) ((x) * (x))
#define all(x) x.begin(), x.end()
#define mod 1000000007


long long n, k, m, l, r, core[200500], price[200500], ans;
long long avai[1100100], cost[1100100];
vector<pair<long long, long long>> v;

long long get(int x, long long* arr) {
  long long res = 0;
  while (x) {
    res += arr[x];
    x -= x & -x;
  }
  return res;
}

void put(int x, long long val, long long* arr) {
  while (x < 1100100) {
    arr[x] += val;
    x += x & -x;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin >> n >> k >> m;
  FOR (i, 1, m) {
    cin >> l >> r >> core[i] >> price[i];
    v.pb({l, i});
    v.pb({r + 1, -i});
  }
  sort(all(v));
  reverse(all(v));

  FOR (i, 1, n) {
    while (v.size() && v.back()._1 == i) {
      int id = v.back()._2;
      if (id > 0) {
        put(price[id], core[id], avai);
        put(price[id], price[id] * core[id], cost);
      } else {
        id = -id;
        put(price[id], -core[id], avai);
        put(price[id], -price[id] * core[id], cost);
      }
      v.pop_back();
    }

    if (get(1000000, avai) <=  k) {
      ans += get(1000000, cost);
      continue;
    }

    long long high = 1000001, low = 0;
    while (high > low) {
      long long chs = (high + low) / 2;
      if (get(chs, avai) >= k) high = chs;
      else low = chs + 1;
    }
    long long tmp = get(high - 1, avai);
    ans += get(high - 1, cost) + high * (k - tmp);
  }

  cout << ans;
}