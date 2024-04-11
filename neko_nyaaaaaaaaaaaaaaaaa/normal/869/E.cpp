#include <bits/stdc++.h>
using namespace std;

#define int long long

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int q;
int tree[2503][2503];
map<tuple<int, int, int, int>, int> que;

void update(int r, int c, int val) {
      for (int x = r; x < 2503; x += x & -x) {
            for (int y = c; y < 2503; y += y & -y) {
                  tree[x][y] += val;
            }
	}
}

void update(int r1, int c1, int r2, int c2, int val) {
      r2++; c2++;
      update(r1, c1, val);
      update(r2, c2, val);
      update(r1, c2, -val);
      update(r2, c1, -val);
}

int query(int r, int c) {
      int ans = 0;
      for (int x = r; x > 0; x -= x & -x) {
            for (int y = c; y > 0; y -= y & -y) {
                  ans += tree[x][y];
            }
	}
	return ans;
}

signed main() {
      ios::sync_with_stdio(0); cin.tie(0);

      cin >> q >> q >> q;
      for (int i = 1; i <= q; i++) {
            int t; cin >> t;

            if (t == 1) {
                  int r1, c1, r2, c2, val;
                  cin >> r1 >> c1 >> r2 >> c2;

                  val = rng()/2;
                  que[make_tuple(r1, c1, r2, c2)] = val;
                  update(r1, c1, r2, c2, val);
            } else if (t == 2) {
                  int r1, c1, r2, c2;
                  cin >> r1 >> c1 >> r2 >> c2;

                  int val = que[make_tuple(r1, c1, r2, c2)];
                  update(r1, c1, r2, c2, -val);
            } else if (t == 3) {
                  int r1, c1, r2, c2;
                  cin >> r1 >> c1 >> r2 >> c2;

                  if (query(r1, c1) == query(r2, c2)) {
                        cout << "Yes\n";
                  } else {
                        cout << "No\n";
                  }
            }
      }

      return 0;
}