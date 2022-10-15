#include <cstdio>
#include <algorithm>
#include <set>
#include <utility>

#define hash asdhjaskdhasd
using namespace std;

int one;

int const C = 17;

int zero[C + 1];

int const N = 1 << C;

int const M = 22345678;

int left[M], right[M], len[M], sum[M];
long long hash[M];
long long POW[N];

int const MOD1 = 999999937;
int const MOD2 = 1000000009;
int const X = 33533;

int const MOD = 1000000007;

int POW2[N];

int const G = 333333;

int from[G], to[G], he[G], ne[G], w[G], d[G];
int fr;

long long mul(long long a, long long b) {
  int r1 = (a >> 32) * (b >> 32) % MOD1;
  int r2 = (a & 0xFFFFFFFF) * (b & 0xFFFFFFFF) % MOD2;
  return ((long long) r1 << 32) | r2;
}

long long add(long long a, long long b) {
  int r1 = ((a >> 32) + (b >> 32)) % MOD1;
  int r2 = ((a & 0xFFFFFFFF) + (b & 0xFFFFFFFF)) % MOD2;
  return ((long long) r1 << 32) | r2;
}

int newNode(int v, int u) {
  left[fr] = v;
  right[fr] = u;
  len[fr] = len[v] + len[u];
  sum[fr] = sum[v] + sum[u];
  hash[fr] = add(mul(hash[v], POW[len[u]]), hash[u]);
  return fr++;
}

int getSum(int v, int l, int r, int ll, int rr) {
  if (r <= ll || rr <= l) return 0;
  if (ll <= l && r <= rr) {
    return sum[v];
  }
  int m = (l + r) >> 1;
  return getSum(left[v], l, m, ll, rr) + getSum(right[v], m, r, ll, rr);
}


int getKth(int v, int k) {
  int l = 0;
  int r = N;
  while (l < r - 1) {
    int mid = (l + r) >> 1;
    if (sum[left[v]] >= k) {
      r = mid;
      v = left[v];
    } else {
      k -= sum[left[v]];
      l = mid;
      v = right[v];
    }
  }
  return l;
}

int getPlace(int v, int x) {
  int s = getSum(v, 0, N, 0, x);
  return getKth(v, s + 1);
}

int fillZero(int v, int l, int r, int ll, int rr) {
  if (r <= ll || rr <= l) return v;
  if (ll <= l && r <= rr) {
    int q = 0;
    int clen = len[v];
    while (clen > 1) {
      q++;
      clen >>= 1;
    }
    return zero[q];
  }
  int m = (l + r) >> 1;  
  return newNode(fillZero(left[v], l, m, ll, rr), fillZero(right[v], m, r, ll, rr));
}

int setOne(int v, int l, int r, int x) {
  if (l + 1 > r) return -1;
  if (l + 1 == r) return one;
  int m = (l + r) >> 1;  
  if (x < m) {
    return newNode(setOne(left[v], l, m, x), right[v]);
  } else {
    return newNode(left[v], setOne(right[v], m, r, x));
  }
}

int compare(int v, int u) {
  int l = 0;
  int r = N;
  while (l < r - 1) {
    int mid = (l + r) >> 1;
    if (hash[right[v]] != hash[right[u]]) {
      l = mid;
      v = right[v];
      u = right[u];
    } else {
      r = mid;
      v = left[v];
      u = left[u];
    }
  }
  return hash[v] - hash[u];
}

int makeZero() {
  left[fr] = -1;
  right[fr] = -1;
  sum[fr] = 1;
  hash[fr] = 1;
  len[fr] = 1;
  return fr++;
}

int makeOne() {
  left[fr] = -1;
  right[fr] = -1;
  sum[fr] = 0;
  hash[fr] = 2;
  len[fr] = 1;
  return fr++;
}

long long calc(int v) {
  if (left[v] < 0 && right[v] < 0) return hash[v] - 1;
  long long ret = right[v] >= 0 ? calc(right[v]) : 0;
  ret = (ret * POW2[len[left[v]]] + calc(left[v])) % MOD;
  return ret;
}

struct comparer {
  bool operator()(pair<int, int> const & x, pair<int, int> const & y) const {
    int c = compare(x.first, y.first);
    if (c != 0) return c < 0;
    return x.second < y.second;
  }
};

int addN(int v, int x) {
  int z = getPlace(v, x);
  v = fillZero(v, 0, N, x, z);
  v = setOne(v, 0, N, z);
  return v;
}

int ans[G], last[G];

int main() {
  POW[0] = (1LL << 32) | 1;
  POW[1] = ((long long) X << 32) | X;
  for (int i = 2; i < N; i++) {
    POW[i] = mul(POW[i - 1], POW[1]);
  }
  POW2[0] = 1;
  for (int i = 1; i < N; i++) {
    POW2[i] = (POW2[i - 1] + POW2[i - 1]) % MOD;
  }
  int n, m;
  scanf("%d%d", &n, &m);
  fr = 0;
  zero[0] = makeZero();
  one = makeOne();
  for (int i = 1; i <= C; i++) {
    zero[i] = newNode(zero[i - 1], zero[i - 1]);
  }
  for (int i = 0; i < m; i++) {
    scanf("%d%d%d", from + i, to + i, w + i);
    --from[i];
    --to[i];    
    from[i + m] = to[i];
    to[i + m] = from[i];
    w[i + m] = w[i];
  }
  for (int i = 0; i < n; i++) he[i] = -1;
  for (int i = 0; i < m + m; i++) {
    ne[i] = he[from[i]];
    he[from[i]] = i;
  }
  set<pair<int, int>, comparer> q;
  for (int i = 0; i < n; i++) d[i] = -1;
  int st, fi;
  scanf("%d%d", &st, &fi);
  st--;
  fi--;
  d[st] = zero[C];
  q.insert(make_pair(d[st], st));
  while (!q.empty()) {
    pair<int, int> vv = *q.begin();
    q.erase(q.begin());
    int v = vv.second;
    int dv = vv.first;
    if (v == fi) break;
    for (int e = he[v]; e >= 0; e = ne[e]) {
      int f = addN(dv, w[e]);
//      printf("%d -> %d, costs %d\n", v, to[e], (int) calc(f));
      if (d[to[e]] < 0 || compare(d[to[e]], f) > 0) {
        q.erase(make_pair(d[to[e]], to[e]));
        d[to[e]] = f;
        last[to[e]] = e;
        q.insert(make_pair(d[to[e]], to[e]));
      }
    }
  }
  if (d[fi] < 0) {
    puts("-1");
    return 0;
  }
  int ac = 0;
  for (int v = fi; v != st; v = from[last[v]]) {
    ans[ac++] = v;
  }
  ans[ac++] = st;
  std::reverse(ans, ans + ac);
  printf("%d\n", (int) calc(d[fi]));
  printf("%d\n", ac);
  for (int i = 0; i < ac; i++) {
    if (i > 0) putchar(' ');
    printf("%d", ans[i] + 1);
  }
  puts("");
}