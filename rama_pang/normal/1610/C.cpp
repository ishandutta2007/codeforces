#include <bits/stdc++.h>
using namespace std;

using lint = long long;
const lint INF = 1e18;
#define int lint

// segtree_lazy.cpp
// Eric K. Zhang; Nov. 22, 2017

// #include <bits/stdc++.h>
// using namespace std;

#define MAXSEG 1048576

class SegTree {
public:
int N, Q;
pair<int, int> st[MAXSEG];
int lazy[MAXSEG];

void push(int lo, int hi, int node) {
	if (lazy[node] == 0) return;
	st[node].first += lazy[node];
	if (lo != hi) {
		lazy[2 * node + 1] += lazy[node];
		lazy[2 * node + 2] += lazy[node];
	}
	lazy[node] = 0;
}

void update_range(int s, int e, int x, int lo=0, int hi=-1, int node=0) {
	if (hi == -1) hi = N - 1;
	push(lo, hi, node);
	if (hi < s || lo > e) return;
	if (lo >= s && hi <= e) {
		lazy[node] = x;
		push(lo, hi, node);
		return;
	}
	int mid = (lo + hi) / 2;
	update_range(s, e, x, lo, mid, 2 * node + 1);
	update_range(s, e, x, mid + 1, hi, 2 * node + 2);
	st[node] = min(st[2 * node + 1], st[2 * node + 2]);
}

pair<int, int> query(int s, int e, int lo=0, int hi=-1, int node=0) {
	if (hi == -1) hi = N - 1;
	push(lo, hi, node);
	if (hi < s || lo > e) return {1e9, -1};
	if (lo >= s && hi <= e) return st[node];
	int mid = (lo + hi) / 2;
	return min(query(s, e, lo, mid, 2 * node + 1), query(s, e, mid + 1, hi, 2 * node + 2));
}

void set(int s, int e, pair<int, int> v, int lo=0, int hi=-1, int node=0) {
	if (hi == -1) hi = N - 1;
	push(lo, hi, node);
	if (hi < s || lo > e) return;
	if (lo >= s && hi <= e) {
    st[node] = v;
    return;
  }
	int mid = (lo + hi) / 2;
	set(s, e, v, lo, mid, 2 * node + 1);
  set(s, e, v, mid + 1, hi, 2 * node + 2);
	st[node] = min(st[2 * node + 1], st[2 * node + 2]);
}
};

SegTree lo, hi;

void Main() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    swap(a[i], b[i]);
  }

  const auto Check = [&](int S) {
    // [1, a[i] + 1]
    // [S - b[i], S]
    int id = 1;
    for (int i = 0; i < n; i++) if (id <= S) {
      if (id <= a[i] + 1 && S - b[i] <= id) {
        id += 1;
      }
    }
    return id > S;
  };

  int l = 1, r = n;
  while (l < r) {
    int m = (l + r + 1) / 2;
    if (Check(m)) {
      l = m;
    } else {
      r = m - 1;
    }
  }
  cout << l << '\n';

  // lo.N = hi.N = n;
  // for (int i = 0; i < n; i++) {
  //   lo.set(i, i, {a[i] - i, i});
  //   hi.set(i, i, {b[i] - (n - 1 - i), i});
  //   // lo.st[i] = {i, i};
  //   // hi.st[i] = {n - 1 - i, i};
  //   // lo.lazy[i] = hi.lazy[i] = 0;
  // }

  // // lo[i] > a[i]
  // // hi[i] 

  // int ans = n;
  // const auto Delete = [&](int id) {
  //   lo.set(id, id, {1e9, -1});
  //   hi.set(id, id, {1e9, -1});
  //   lo.update_range(id, n - 1, 1);
  //   hi.update_range(0, id, 1);
  //   ans--;
  //   // cout << id << ' ';
  // };
  // while (true) {
  //   if (lo.query(0, n - 1).first < 0) {
  //     int id = lo.query(0, n - 1).second;
  //     Delete(id);
  //   } else if (hi.query(0, n - 1).first < 0) {
  //     int id = hi.query(0, n - 1).second;
  //     Delete(id);
  //   } else {
  //     break;
  //   }
  // }

  // cout << ans << '\n';
}

int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}