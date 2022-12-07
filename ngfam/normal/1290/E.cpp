// already came up with an idea last night
//
// Every node on cartesian tree convers some continous segment as its subtree
//
// let l[i] and r[i] be this range
//
// the query of adding some element(which is larger than any previous one)
// is equivalent to maximize some l[i] with its position + 1 and some r[i]
// with its position - 1
//
// and add count to the result
// Each elements  contribute f(r[i]) - f(l[i] - 1) to answer
//
// adding the largest element does change f(i) individually but not f(r) - f(l - 1) cause
// no range covers it
//
// only matters later

//
// Todo: Segment tree beats
//
// maybe needs count for min and max element as well
// still thinking if i should use std:arrray
// code might look bad
//
// after joining first and second largest, what will be second largest next?
/// im dumb

/// later...

#define mid ((l + r) >> 1)
#define lc (x << 1)
#define rc (lc | 1)

#include<bits/stdc++.h>

using namespace std;

const int N = 150010;

int n;
int a[N];
int p[N];
long long ans = 0;

struct fenwick{
  int fwt[N];

  int get(int x) {
    x += 5;
    int ans = 0;
    for(; x > 0; x -= x & -x) ans += fwt[x];
    return ans;
  }

  void upd(int x) {
    x += 5;
    for(; x < N; x += x & -x) fwt[x]++;
  }
}fwt;

bool operator != (pair<int, int> a, pair<int, int> b) {
  return a.first != b.first;
}

namespace SegMin{
  pair<int, int> maxsum(pair<int, int> u, pair<int, int> v) {
    if(u < v) swap(u, v);
    if(u.first == v.first) u.second += v.second;
    return u;
  }


  struct BeatMax{
    pair<int, int> a, b;
  };

  BeatMax operator +(BeatMax lhs, BeatMax rhs) {
    BeatMax ret;
    if(lhs.a < rhs.a) swap(lhs, rhs);
    ret = lhs;
    ret.a = maxsum(ret.a, rhs.a);
    ret.b = maxsum(ret.b, rhs.b);
    if(rhs.a != ret.a) ret.b = maxsum(ret.b, rhs.a);
    return ret;
  }

  int lazymin[N << 3];
  BeatMax treemin[N << 2];

  void build(int x, int l, int r) {
    lazymin[x] = N;
    if(l == r) {
      treemin[x].a = {-1, 1};
      treemin[x].b = {-1, 0};
      return;
    }
    build(lc, l, mid);
    build(rc, mid + 1, r);
    treemin[x] = treemin[lc] + treemin[rc];
  }

  void applymin(int x, long long add = 0) {
    if(lazymin[x] >= treemin[x].a.first) {
      lazymin[x] = N;
      return;
    }
    if(treemin[x].b.first < lazymin[x]) {
      ans -= add * treemin[x].a.second * fwt.get(treemin[x].a.first);
      treemin[x].a.first = lazymin[x];
      ans += add * treemin[x].a.second * fwt.get(treemin[x].a.first);
      /// changes go here
    }
    lazymin[lc] = min(lazymin[lc], lazymin[x]);
    lazymin[rc] = min(lazymin[rc], lazymin[x]);
    lazymin[x] = N;
  }

  void upd(int x, int l, int r, int u, int v, int val) {
    applymin(x);
    if(val >= treemin[x].a.first) return;
    if(l > v || r < u) return;
    if(l >= u && r <= v) {
      if(treemin[x].b.first < val) {
        lazymin[x] = val;
        applymin(x, 1);
        return;
      }
    }
    upd(lc, l, mid, u, v, val);
    upd(rc, mid + 1, r, u, v, val);
    treemin[x] = treemin[lc] + treemin[rc];
  }

  void modify(int x, int l, int r, int pos, int val) {
    applymin(x);
    if(l == r) {
      treemin[x].a = {val, 1};
      treemin[x].b = {-1, 0};
      return;
    }
    if(pos <= mid) modify(lc, l, mid, pos, val);
    else modify(rc, mid + 1, r, pos, val);
    applymin(lc); applymin(rc);
    treemin[x] = treemin[lc] + treemin[rc];
  }

  void query(int x, int l, int r, int pos) {
    applymin(x);
    if(l == r) {
      cout << treemin[x].a.first << " ";
      return;
    }
    if(pos <= mid) query(lc, l, mid, pos);
    else query(rc, mid + 1, r, pos);
  }
}
namespace SegMax{
  pair<int, int> minsum(pair<int, int> u, pair<int, int> v) {
    if(u > v) swap(u, v);
    if(u.first == v.first) u.second += v.second;
    return u;
  }

  struct BeatMin{
    pair<int, int> a, b;
  };

  BeatMin operator +(BeatMin lhs, BeatMin rhs) {
    BeatMin ret;
    if(lhs.a > rhs.a) swap(lhs, rhs);
    ret = lhs;
    ret.a = minsum(ret.a, rhs.a);
    ret.b = minsum(ret.b, rhs.b);
    if(rhs.a != ret.a) ret.b = minsum(ret.b, rhs.a);
    return ret;
  }

  int lazymax[N << 3];
  BeatMin treemax[N << 2];

  void build(int x, int l, int r) {
    lazymax[x] = -1;
    if(l == r) {
      treemax[x].a = {N, 1};
      treemax[x].b = {N, 0};
      return;
    }
    build(lc, l, mid);
    build(rc, mid + 1, r);
    treemax[x] = treemax[lc] + treemax[rc];
  }

  void applymax(int x, long long add = 0) {
    if(lazymax[x] <= treemax[x].a.first) {
      lazymax[x] = -1;
      return;
    }
    if(treemax[x].b.first > lazymax[x]) {
      ans += add * treemax[x].a.second * fwt.get(treemax[x].a.first);
      treemax[x].a.first = lazymax[x];
      ans -= add * treemax[x].a.second * fwt.get(treemax[x].a.first);
      /// changes go here

    }
    lazymax[lc] = max(lazymax[lc], lazymax[x]);
    lazymax[rc] = max(lazymax[rc], lazymax[x]);
    lazymax[x] = -1;
  }

  void upd(int x, int l, int r, int u, int v, int val) {
    // cout << l << " " << r << " " << treemax[x].a << " " << treemax[x].b << " " << lazymax[x] << endl;
    applymax(x);
    if(val <= treemax[x].a.first) return;
    if(l > v || r < u) return;
    if(l >= u && r <= v) {
      if(treemax[x].b.first > val) {
        lazymax[x] = val;
        applymax(x, 1);
        return;
      }
    }
    upd(lc, l, mid, u, v, val);
    upd(rc, mid + 1, r, u, v, val);
    treemax[x] = treemax[lc] + treemax[rc];
  }

  void modify(int x, int l, int r, int pos, int val) {
    applymax(x);
    if(l == r) {
      treemax[x].a = {val, 1};
      treemax[x].b = {N, 0};
      return;
    }
    if(pos <= mid) modify(lc, l, mid, pos, val);
    else modify(rc, mid + 1, r, pos, val);

    applymax(lc); applymax(rc);

    treemax[x] = treemax[lc] + treemax[rc];

  }

  void query(int x, int l, int r, int pos) {
    applymax(x);
    if(l == r) {
      cout << treemax[x].a.first << " ";
      return;
    }
    if(pos <= mid) query(lc, l, mid, pos);
    else query(rc, mid + 1, r, pos);
    treemax[x] = treemax[lc] + treemax[rc];
  }
};

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  cin >> n;
  for(int i = 0; i < n; ++i) cin >> a[i], --a[i];
  for(int i = 0; i < n; ++i) p[a[i]] = i;

  SegMin::build(1, 0, n - 1);
  SegMax::build(1, 0, n - 1);

  for(int i = 0; i < n; ++i) {
    ans += i + 1;
    int pos = p[i];
    //cout << pos << endl;
    if(pos > 0) SegMin::upd(1, 0, n - 1, 0, pos - 1, pos - 1);
    if(pos < n - 1) SegMax::upd(1, 0, n - 1, pos + 1, n - 1, pos);
    SegMax::modify(1, 0, n - 1, pos, -1);
    SegMin::modify(1, 0, n - 1, pos, n - 1);
    fwt.upd(pos);
    cout << ans << "\n";

    //cout << "[";
  //  for(int i = 0; i < n; ++i) SegMax::query(1, 0, n - 1, i);
  //  cout << "]" << endl;
  }

  return 0;
}