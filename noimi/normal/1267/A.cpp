#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(v) v.begin(),v.end()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vii vector<vi>
#define vl vector<ll>
#define vll vector<vl>

#define rep(i,n) for(int i = 0; i < n; i++)

bool cmp(pair<pll, ll> a, pair<pll, ll> b) {
  if (a.first.first != b.first.first) {
    return a.first.first < b.first.first;
  }
  else {
    if (a.second != b.second) {
      return a.second < b.second;
    }
    else {
      return a.first.second > b.first.second;
    }
  }
}

signed main() {
  int n;
  cin >> n;
  vector<pair<pll, ll>> abt(n);
  rep (i, n) {
    cin >> abt[i].first.first >> abt[i].first.second >> abt[i].second;
  }
  sort(all(abt), cmp);
  vl a(n);
  rep (i, n) {
    a[i] = abt[i].first.first;
  }

  ll now = a[0];
  int ai = 1;
  priority_queue<pll, vector<pll>, greater<pll>> tb;
  tb.push(pll(abt[0].second, abt[0].first.second));
  ll ans = 0;
  a.push_back(2000000000000000000);
  while (ai < n or tb.size() > 0) {
    while (ai < n and a[ai] <= now) {
      tb.push(pll(abt[ai].second, abt[ai].first.second));
      ai++;
    }
    ll nex = a[ai];
    while (tb.size() > 0) {
      pll to = tb.top();
      if (now + to.first > to.second) tb.pop();
      else break;
    }
    if (tb.size() == 0) {
      now = nex;
      continue;
    }

    ll t;
    pll to = tb.top();
    if (to.second <= nex) {
      ans += (to.second - now) / to.first;
      now += (to.second - now) / to.first * to.first;
      tb.pop();
      continue;
    }
    else {
      ans += (nex - now) / to.first;
      now += (nex - now) / to.first * to.first;
      t = to.first;
      if (now + to.first > to.second) {
        tb.pop();
        continue;
      }
    }

    ll last = now + t;
    int aj = ai;
    while (a[aj] < now + t) {
      if (last > a[aj] + abt[aj].second) {
        last = a[aj] + abt[aj].second;
        for (int k = ai; k <= aj; k++) {
          tb.push(pll(abt[k].second, abt[k].first.second));
        }
        ai = aj + 1;
      }
      aj++;
    }
    ans++;
    now = last;
  }
  cout << ans << endl;
}