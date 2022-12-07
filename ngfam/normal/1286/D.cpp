#include<bits/stdc++.h>
#define left ratingis
#define right justanumber
 
using namespace std;
 
const int MAXN = 100010;
const int mod = 998244353;
 
int fpow(int x, int y) {
  if(y < 0) y += mod - 1;
  int ret = 1;
  for(; y > 0; y >>= 1, x = (1LL * x * x) % mod) {
    if(y & 1) ret = (1LL * ret * x) % mod;
  }
  return ret;
}
 
struct TimeStamp{
  pair < int, int > t;
  int id;
  int type;
 
  TimeStamp(){};
  TimeStamp(pair < int, int > t, int id, int type) : t(t), id(id), type(type) {}
 
    /***
      type 0: -> <-
      type 1: -> ->
      type 2: <- <-
      => At most 2 * N timestamps to be added
    ***/
 
  bool operator < (const TimeStamp &rhs) const {
    /// a / b < c / d => a * d < c * b
    return 1LL * t.first * rhs.t.second < 1LL * t.second * rhs.t.first;
  }
};
 
struct dsu{
  int lab[MAXN];
  dsu() {
    memset(lab, -1, sizeof lab);
  }
  int find(int x) {
    return lab[x] < 0 ? x : lab[x] = find(lab[x]);
  }
  int join(int x, int y) {
    x = find(x); y = find(y);
    if(x == y) return -1;
    if(x > y) swap(x, y);
    lab[x] += lab[y];
    lab[y] = x;
    return x;
  }
}dsu;
 
int n;
int x[MAXN], v[MAXN], p[MAXN], s[MAXN], left[MAXN], right[MAXN], a[MAXN];
 
int seg(int *a, int l, int r) {
  int ret = a[r];
  if(l > 0) ret = 1LL * ret * fpow(a[l - 1], -1) % mod;
  return ret;
}
 
int curprob(int id) {
  id = dsu.find(id);
  int l = left[id], r = right[id], ll = id, rr = id - dsu.lab[id] -1;
  if(l > r) return 0;
  return 1LL * (a[r] - a[l - 1] + mod) * (1LL * fpow(p[ll - 1], -1) * fpow(s[rr + 1], -1) % mod) % mod;
}
 
main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
 
  cin >> n;
  for(int i = 1; i <= n; ++i) {
    cin >> x[i] >> v[i] >> p[i];
 
    p[i] = 1LL * (100 - p[i]) * fpow(100, -1) % mod;
    s[i] = (mod + 1 - p[i]) % mod;
 
    left[i] = i; right[i] = i + 1;
    if(p[i] == 0) right[i] = i;
    if(s[i] == 0) left[i] = i + 1;
  }
 
  p[0] = 1;
  s[n + 1] = 1;
  for(int i = 1; i <= n; ++i) {
    p[i] = 1LL * p[i - 1] * p[i] % mod;
    if(p[i] == 0) p[i] = 1;
  }
 
  for(int i = n; i >= 1; --i) {
    s[i] = 1LL * s[i + 1] * s[i] % mod;
    if(s[i] == 0) s[i] = 1;
  }
 
  for(int i = 1; i <= n + 1; ++i) {
    a[i] = 1LL * p[i - 1] * s[i] % mod;
    (a[i] += a[i - 1]) %= mod;
  }
 
  vector < TimeStamp > vec;
  for(int i = 1; i < n; ++i) {
    vec.emplace_back(make_pair(x[i + 1] - x[i], v[i] + v[i + 1]), i, 0);
    if(v[i] > v[i + 1]) {
      vec.emplace_back(make_pair(x[i + 1] - x[i], v[i] - v[i + 1]), i, 1);
    }
    if(v[i] < v[i + 1]) {
      vec.emplace_back(make_pair(x[i + 1] - x[i], v[i + 1] - v[i]), i, 2);
    }
  }
 
  sort(vec.begin(), vec.end());
 
 
 
 
  /***
    event of type 0 always happens before corresponding type 1 and 2, so no need to worry about that
    type 0: -> <-
    type 1: -> ->
    type 2: <- <-
    => At most 2 * N timestamps to be added
 
    Note: Should also stop the solution as soon as some left[id] > right[id]
  ***/
 
  long long answer = 0, prob = 1, last = 0;
 
  for(auto event: vec) {
    if(prob == 0) break;
 
    int t = 1LL * event.t.first * fpow(event.t.second, -1) % mod;
    int id = event.id;
    int type = event.type;
    long long nextprob = prob;
 
    int u = dsu.find(id), v = dsu.find(id + 1), ru = v - 1, rv = v - dsu.lab[v] - 1;
    if(u != v) { /// this only happens when type = 0
      (nextprob *= fpow(curprob(u), -1)) %= mod;
      (nextprob *= fpow(curprob(v), -1)) %= mod;
 
      if(right[u] < ru + 1 && left[v] > v) nextprob = 0;
      else {
        if(right[u] == ru + 1 && left[v] == v) left[u] = left[u], right[u] = right[v];
        else {
          if(left[v] > v) left[u] = left[v], right[u] = right[v];
        }
      }
      dsu.join(u, v);
      (nextprob *= curprob(u)) %= mod;
    }
    else { /// when type != 0
      (nextprob *= fpow(curprob(u), -1)) %= mod;
      if(type == 1) {
        left[u] = max(left[u], id + 1);
      }
      else {
        right[u] = min(right[u], id + 1);
      }
      (nextprob *= curprob(u)) %= mod;
    }
 
    answer += 1LL * (t) * (prob - nextprob + mod) % mod;
    answer %= mod;
    last = t;
    prob = nextprob;
  }
 
  cout << answer << endl;
 
 
  return 0;
}