//#include <bits/stdc++.h>
#include <vector>
#include <cstdio>
#include <set>
#include <map>
#include <iostream>
#include <utility>
#include <cmath>
#include <algorithm>
#include <cassert>

using namespace std;

#define ford(i, n) for (int i = (int) n - 1; i >= 0; --i)
#define forn(i, n) for (int i = 0; i < (int) n; ++i)
#define pb push_back
#define sz(c) ((int) (c).size())
#define fst first
#define snd second
#define all(c) (c).begin(), (c).end()
#define mp(x, y) make_pair(x, y)
#define left ________________left
#define right _______________right
#define hash ________________hash
#define y1 __________________y1

#define FILE_NAME ""

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;

const int MAXN = 4 * 3e4 + 10;

struct Rule {
  int a, b, c;
  int id;

  bool read(int i) {
    id = i;
    if  (scanf("%d%d%d", &a, &b, &c) < 3) {
      return false;
    }
    --a;
    --b;
    --c;
    return true;
  }
};

int deg[MAXN];

struct cmp {
  bool operator()(const Rule& x, const Rule& y) const {
    if  (deg[x.a] != deg[y.a]) {
      return deg[x.a] < deg[y.a];
    }
    if  (max(deg[x.b], deg[x.c]) != max(deg[y.b], deg[y.c])) {
      return max(deg[x.b], deg[x.c]) > max(deg[y.b], deg[y.c]);
    }
    if  (min(deg[x.b], deg[x.c]) != min(deg[y.b], deg[y.c])) {
      return min(deg[x.b], deg[x.c]) > min(deg[y.b], deg[y.c]);  
    }
    return x.id < y.id;
  }
};

set<Rule, cmp> rules;
int n;

vector<Rule> who[MAXN];

Rule all_rules[MAXN];

bool read() {
  if  (scanf("%d", &n) < 1) {
    return false;
  }
  forn(i, 4 * n) {
    Rule cur;
    assert(cur.read(i));
    rules.insert(cur);
    who[cur.a].pb(cur);
    who[cur.b].pb(cur);
    who[cur.c].pb(cur);
    all_rules[i] = cur;
  }                
  return true;
}

bool used[MAXN];

bool check(const vi& order) {
  forn(i, n) deg[i] = 4;
  forn(i, 4 * n) {
    auto r = all_rules[order[i]];
    --deg[r.a];
    ++deg[r.b];
    ++deg[r.c];
    if  (deg[r.b] > 9) {
      return false;
    }
    if  (deg[r.c] > 9) {
      return false;
    }
  }
  return true;
}

int main() {
#ifdef DEBUG
  freopen(FILE_NAME ".in", "r", stdin);
//  freopen(FILE_NAME ".out", "w", stdout);
#endif

  assert(read());

  forn(i, n) deg[i] = 4;
  for (const auto& r : rules) {
    --deg[r.a];
    ++deg[r.b];
    ++deg[r.c];
  }

//  forn(i, n) printf("%d ", deg[i]);
//  puts("");

  vi ans;
  forn(it, 4 * n) {
    auto best = *rules.begin();
    rules.erase(rules.begin());
    ans.pb(best.id);
    used[best.id] = true;

    for (int i : { best.a, best.b, best.c }) {
      for (auto r : who[i]) {
        if  (used[r.id]) {
          continue;
        }
        rules.erase(r);
      } 
    }

    ++deg[best.a];
    --deg[best.b];
    --deg[best.c];

    for (int i : { best.a, best.b, best.c }) {
      for (auto r : who[i]) {
        if  (used[r.id]) {
          continue;
        }
        rules.insert(r);
      } 
    }
  }

  reverse(all(ans));

  if  (!check(ans)) {
    puts("NO");
    return 0;
  }

  puts("YES");
  for (int x : ans) {
    printf("%d ", x + 1);
  }
  puts("");

  return 0;
}