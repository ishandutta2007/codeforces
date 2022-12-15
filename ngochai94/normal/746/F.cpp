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

long long n, w, k, a[200005], t[200005], ans, curans, curt;
multiset<int> full, half;

void add(int x) {
  full.insert(t[x]);
  curans += a[x];
  curt += t[x];
  while (half.size() < w && !full.empty())  {
    auto it = full.end();
    it--;
    half.insert(*it);
    curt -= (*it) / 2;
    full.erase(it);
  }
  if (!full.empty()) {
    auto it1 = full.end();
    it1--;
    auto it2 = half.begin();
    if (*it1 > *it2) {
      int tmp1 = *it1;
      int tmp2 = *it2;
      curt += tmp2 / 2 - tmp1 / 2;
      full.erase(it1);
      half.erase(it2);
      full.insert(tmp2);
      half.insert(tmp1);
    }
  }
}

void del(int x) {
  // curt -= t[x];
  curans -= a[x];
  if (full.find(t[x]) != full.end()) {
    full.erase(full.find(t[x]));
    curt -= t[x];
  } else {
    curt -= (t[x] + 1) / 2;
    half.erase(half.find(t[x]));
    if (!full.empty()) {
      auto it = full.end();
      it--;
      half.insert(*it);
      curt -= (*it) / 2;
      full.erase(it);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin >> n >> w >> k;
  REP (i, n) cin >> a[i];
  REP (i, n) cin >> t[i];
  int p = 0;
  while (p < n) {
    add(p);
    if (curt > k) {
      del(p);
      p--;
      break;
    }
    p++;
  }
  ans = curans;
  // BUG(p);
  // BUG(ans);
  FOR (i, 1, n - 1) {
    // BUG(i);
    p++;
    if (p != i - 1) del(i - 1);
    else p = i;
    // BUG(curans);
    while (p < n) {
      add(p);
      // BUG(p);
      // BUG(curt);
      if (curt > k) {
        del(p);
        p--;
        break;
      }
      p++;
    }
    ans = max(ans, curans);
    // cout << i << ' ' << p << ' ' << curans << endl;
  }
  cout << ans;
}