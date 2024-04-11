// NOT MY CODE
// https://codeforces.com/contest/1515/submission/115143855
 
#include <bits/stdc++.h>
///#pragma GCC target("sse4.2")
 
///#pragma GCC opimize("O1")
///#pragma GCC opimize("O2")
 
///#pragma GCC opimize("Os")
///#pragma GCC opimize("Ofast")
#pragma GCC target("avx,avx2")
///#pragma GCC target("avx2")
 
 
/**
#pragma GCC opimize("O3")
#pragma GCC opimization ("unroll-loops")
 
**/
using namespace std;
 
bool home = 1;
typedef long long ll;
typedef long double ld;
///#define int ll
signed realMain();
 
bool ok;
 
signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen ("tony_stark", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }
  realMain();
}
 
pair<ll, ll> operator + (pair<ll, ll> a, pair<ll, ll> b) {
  return {a.first + b.first, a.second + b.second};
}
 
struct T {
  ll cnt;
  int value;
  int weight;
  int ind;
};
 
bool operator < (T a, T b) {
  if (a.value == b.value) {
    return a.weight < b.weight;
  } else {
    return a.value > b.value;
  }
}
 
const int N = (int) 2e5 + 7;
const int KK = 19;
int K;
int sz[KK];
const ll INF = (ll) 1e18;
const ll INF_SMALL = (ll) 1e14;
int n, q, real_position[N];
int where[KK][N];
T a[N];
vector<int> inds[N];
 
ll aib_sum_weight[KK][N];
ll aib_sum_value[KK][N];
ll aib_sum_weight_light[KK][N];
ll aib_sum_value_light[KK][N];
 
ll mn[KK][4 * N];
ll lazy[KK][4 * N];
ll val[KK][N];
ll memo[KK][N];
 
void add_aib(ll aib[], int i, ll x, int sz) {
  if (!x) {
    return;
  }
  i++;
  while (i <= sz) {
    aib[i] += x;
    i += i & (-i);
  }
}
 
ll pre_aib(ll aib[], int i) {
  i++;
  ll sol = 0;
  while (i) {
    sol += aib[i];
    i -= i & (-i);
  }
  return sol;
}
 
void push(int k, int v, int tl, int tr) {
  if (!lazy[k][v]) {
    return;
  }
  mn[k][v] += lazy[k][v];
  if (tl < tr) {
    lazy[k][2 * v] += lazy[k][v];
    lazy[k][2 * v + 1] += lazy[k][v];
  }
  lazy[k][v] = 0;
}
 
void addx(int k, int v, int tl, int tr, int l, int r, ll x) {
  push(k, v, tl, tr);
  if (tr < l || r < tl) {
    return;
  }
  if (l <= tl && tr <= r) {
    lazy[k][v] += x;
    push(k, v, tl, tr);
    return;
  }
  int tm = (tl + tr) / 2;
  addx(k, 2 * v, tl, tm, l, r, x);
  addx(k, 2 * v + 1, tm + 1, tr, l, r, x);
  mn[k][v] = min(mn[k][2 * v], mn[k][2 * v + 1]);
}
 
ll get(int k, int v, int tl, int tr, int l, int r) {
  push(k, v, tl, tr);
  if (tr < l || r < tl) {
    return INF;
  }
  if (l <= tl && tr <= r) {
    return mn[k][v];
  }
  int tm = (tl + tr) / 2;
  return min(get(k, 2 * v, tl, tm, l, r), get(k, 2 * v + 1, tm + 1, tr, l, r));
}
 
bool is_light(int k, int i) {
  return (a[i].weight < (1 << k) / 2);
}
 
bool is_heavy(int k, int i) {
  return !is_light(k, i);
}
 
ll jmen[KK][N];
 
void bu(int k, int v, int tl, int tr) {
  if (tl == tr) {
    mn[k][v] = jmen[k][tl];
    return;
  }
  int tm = (tl + tr) / 2;
  bu(k, 2 * v, tl, tm);
  bu(k, 2 * v + 1, tm + 1, tr);
  mn[k][v] = min(mn[k][2 * v], mn[k][2 * v + 1]);
}
 
void build() {
  for (int i = 1; i <= n; i++) {
    for (int k = 0; k < K; k++) {
      if (where[k][i] != -1) {
        if (is_light(k, i)) {
          jmen[k][where[k][i]] += (ll) a[i].weight * a[i].cnt;
          memo[k][where[k][i]] = (ll) a[i].weight * a[i].cnt;
        }
        if (is_heavy(k, i) && a[i].cnt > 0) {
          jmen[k][where[k][i]] += a[i].weight;
          jmen[k][where[k][i] + 1] -= a[i].weight;
          val[k][where[k][i]] = a[i].weight;
        } else {
          jmen[k][where[k][i]] += INF_SMALL;
          jmen[k][where[k][i] + 1] -= INF_SMALL;
          val[k][where[k][i]] = INF_SMALL;
        }
      }
    }
  }
  for (int k = 0; k < K; k++) {
    if (!inds[k].empty()) {
      for (int i = 1; i < (int) inds[k].size(); i++) {
        jmen[k][i] += jmen[k][i - 1];
      }
      bu(k, 1, 0, (int) inds[k].size() - 1);
    }
  }
}
 
void upd(int i) {
  for (int k = 0; k < K; k++) {
    if (where[k][i] != -1) {
      if (is_light(k, i)) {
        addx(k, 1, 0, (int) inds[k].size() - 1, where[k][i], (int) inds[k].size() - 1, (ll) a[i].weight * a[i].cnt - memo[k][where[k][i]]);
        memo[k][where[k][i]] = (ll) a[i].weight * a[i].cnt;
      }
      if (is_heavy(k, i) && a[i].cnt > 0) {
        addx(k, 1, 0, (int) inds[k].size() - 1, where[k][i], where[k][i], a[i].weight - val[k][where[k][i]]);
        val[k][where[k][i]] = a[i].weight;
      } else {
        addx(k, 1, 0, (int) inds[k].size() - 1, where[k][i], where[k][i], INF_SMALL - val[k][where[k][i]]);
        val[k][where[k][i]] = INF_SMALL;
      }
    }
  }
}
 
void proc(ll &c, ll &sol, int i) {
  ll take = min(a[i].cnt, c / (ll) a[i].weight);
  c -= take * (ll) a[i].weight;
  sol += take * (ll) a[i].value;
}
 
int ffind, solution;
ll limit, small;
 
int steps;
 
void rec_third(int k, int v, int tl, int tr) {
  steps++;
  push(k, v, tl, tr);
  if (tr < ffind || small < limit) {
    return;
  }
  if (tl == tr) {
    small = min(small, mn[k][v]);
    if (small >= limit) {
      solution = tl + 1;
    }
    return;
  }
  int tm = (tl + tr) / 2;
  if (ffind <= tl) {
    push(k, 2 * v, tl, tm);
    if (mn[k][2 * v] >= limit) {
      solution = tm + 1;
      rec_third(k, 2 * v + 1, tm + 1, tr);
      return;
    }
  }
  rec_third(k, 2 * v, tl, tm);
  rec_third(k, 2 * v + 1, tm + 1, tr);
}
 
ll get_aib(ll aib[], int l, int r) {
  return pre_aib(aib, r) - pre_aib(aib, l - 1);
}
 
int go_bs;
 
ll rec(ll c, int pos, int k) {
  if (k < 0) {
    assert(0);
    return 0;
  }
  ll sol = 0;
  int ind = -1;
  {
    int l = 0, r = (int) inds[k].size() - 1;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (pos <= inds[k][mid]) {
        ind = mid;
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
  }
  if (ind == -1) {
    return 0;
  }
  {
    int ff = ind, kek = -1;
    ll val = 0;
    if (ind >= 1) {
      val = pre_aib(aib_sum_weight[k], ind - 1);
    }
    val += c - (1 << k);
    if (val - c + (1 << k) + a[where[k][ind]].weight <= val) {
      for (int jump = go_bs; jump; jump /= 2) {
        if (kek + jump < (int) inds[k].size()) {
          if (aib_sum_weight[k][kek + jump + 1] <= val) {
            kek += jump;
            val -= aib_sum_weight[k][kek + 1];
          }
        }
      }
      ind = max(ind, kek + 1);
    }
    if (ff <= ind - 1) {
      int i = ind;
      while (i >= 1) {
        sol += aib_sum_value[k][i];
        c -= aib_sum_weight[k][i];
        i -= i & (-i);
      }
      i = ff;
      while (i >= 1) {
        sol -= aib_sum_value[k][i];
        c += aib_sum_weight[k][i];
        i -= i & (-i);
      }
    }
  }
  if (ind < (int) inds[k].size()) {
    proc(c, sol, inds[k][ind]);
    ind++;
  }
  if (ind == (int) inds[k].size()) {
    return sol;
  }
  ll scad = 0;
  if (ind >= 1) {
    scad = pre_aib(aib_sum_weight_light[k], ind - 1);
  }
  int ff = ind, ultimul = ff - 1;
  if (c - (1 << k) / 2 + 1 > 0) {
 
    int l = 0, r = (int) inds[k].size() - 1, kek = -1;
    ll val = c - (1 << k) / 2;
    if (ff - 1 >= 0) {
      val += pre_aib(aib_sum_weight_light[k], ff - 1);
    }
    for (int jump = go_bs; jump; jump /= 2) {
      if (kek + jump < (int) inds[k].size() && aib_sum_weight_light[k][kek + jump + 1] <= val) {
        kek += jump;
        val -= aib_sum_weight_light[k][kek + 1];
      }
    }
    ultimul = min((int) inds[k].size() - 1, kek + 1);
  }
  if (ff <= ultimul) {
    ffind = ff;
    limit = c + scad + 1;
    solution = ff;
    small = 2 * INF;
    rec_third(k, 1, 0, (int) inds[k].size() - 1);
    ind = min(solution, ultimul) + 1;
  }
  if (ff <= ind - 1) {
    if (ff <= ind - 2) {
      int i = ind - 1;
      while (i >= 1) {
        sol += aib_sum_value_light[k][i];
        c -= aib_sum_weight_light[k][i];
        i -= i & (-i);
      }
      i = ff;
      while (i >= 1) {
        sol -= aib_sum_value_light[k][i];
        c += aib_sum_weight_light[k][i];
        i -= i & (-i);
      }
    }
    proc(c, sol, inds[k][ind - 1]);
  }
 
  if (ind == (int) inds[k].size()) {
    return sol;
  }
  return sol + rec(c, inds[k][ind], k - 1);
}
 
signed realMain() {
  cin >> n >> q;
  go_bs = log2(n);
  go_bs = (1 << (go_bs + 1));
  assert(go_bs > n);
  int mx = 0;
  ok = (n == 200000 && q == 100000);
  for (int i = 1; i <= n; i++) {
    cin >> a[i].cnt >> a[i].weight >> a[i].value;
    if (i == 1) {
      ok &= (a[i].cnt == 1 && a[i].weight == 1 && a[i].value == 1);
    }
    mx = max(mx, a[i].weight);
    a[i].ind = i;
  }
  K = log2(mx);
  K += 2;
  assert(K < KK);
  sort(a + 1, a + n + 1);
  for (int k = 0; k < K; k++) {
    for (int i = 1; i <= n; i++) {
      if (a[i].weight < (1 << k)) {
        where[k][i] = sz[k]++;
        inds[k].push_back(i);
      } else {
        where[k][i] = -1;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    real_position[a[i].ind] = i;
    for (int k = 0; k < K; k++) {
      if (where[k][i] != -1) {
        add_aib(aib_sum_weight[k], where[k][i], (ll) a[i].cnt * a[i].weight, (int) inds[k].size());
        add_aib(aib_sum_value[k], where[k][i], (ll) a[i].cnt * a[i].value, (int) inds[k].size());
        add_aib(aib_sum_weight_light[k], where[k][i], (ll) a[i].cnt * a[i].weight * is_light(k, i), (int) inds[k].size());
        add_aib(aib_sum_value_light[k], where[k][i], (ll) a[i].cnt * a[i].value * is_light(k, i), (int) inds[k].size());
      }
    }
  }
  build();
  if (ok) {
    //return 0;
  }
  int mxs = 0;
  int c1 = 0, c2 = 0;
  for (int iq = 1; iq <= q; iq++) {
    int type;
    cin >> type;
    if (type == 1) {
      int grow, i;
      cin >> grow >> i;
      i = real_position[i];
      a[i].cnt += grow;
      for (int k = 0; k < K; k++) {
        if (where[k][i] != -1) {
          add_aib(aib_sum_weight[k], where[k][i], (ll) grow * a[i].weight, (int) inds[k].size());
          add_aib(aib_sum_value[k], where[k][i], (ll) grow * a[i].value, (int) inds[k].size());
          add_aib(aib_sum_weight_light[k], where[k][i], (ll) grow * a[i].weight * is_light(k, i), (int) inds[k].size());
          add_aib(aib_sum_value_light[k], where[k][i], (ll) grow * a[i].value * is_light(k, i), (int) inds[k].size());
        }
      }
      upd(i);
      c1++;
    }
    if (type == 2) {
      int take, i;
      cin >> take >> i;
      i = real_position[i];
      a[i].cnt -= take;
      for (int k = 0; k < K; k++) {
        if (where[k][i] != -1) {
          add_aib(aib_sum_weight[k], where[k][i], -(ll) take * a[i].weight, (int) inds[k].size());
          add_aib(aib_sum_value[k], where[k][i], -(ll) take * a[i].value, (int) inds[k].size());
          add_aib(aib_sum_weight_light[k], where[k][i], -(ll) take * a[i].weight * is_light(k, i), (int) inds[k].size());
 
          add_aib(aib_sum_value_light[k], where[k][i], -(ll) take * a[i].value * is_light(k, i), (int) inds[k].size());
        }
      }
      upd(i);
      c1++;
    }
    if (type == 3) {
      ll c;
      cin >> c;
      cout << rec(c, 1, K - 1) << "\n";
      c2++;
    }
    mxs = max(mxs, steps);
    steps = 0;
   /** if (ok && iq == 90000) {
      cout << "#" << c1 << "," << c2 << ":" << mxs << "\n";
      return 0;
    }**/
  }
  return 0;
}