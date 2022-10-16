#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m;
vector<int> p(2008);
vector<int> taken(2008);
vector<pair<int, int>> pr;

void solve1() {
      int turn = n;
      while (turn--) {
            int taking = 0;
            for (auto u: pr) {
                  if (taken[u.first] && taken[u.second]) continue;
                  if (p[u.first] > p[u.second]) {
                        taking = u.first;
                  } else {
                        taking = u.second;
                  }
                  break;
            }

            if (taking != 0) {
                  cout << taking << endl;
                  int x; cin >> x;
                  taken[x] = 1;
                  taken[taking] = 1;
            } else {
                  for (int i = 1; i <= 2*n; i++) {
                        if (taken[i]) continue;
                        if (p[i] > p[taking]) taking = i;
                  }
                  cout << taking << endl;
                  int x; cin >> x;
                  taken[x] = 1;
                  taken[taking] = 1;
            }
      }
      exit(0);
}

void solve2() {
      int turn = n;
      while (turn--) {
            int x; cin >> x;
            taken[x] = 1;
            int taking = 0;
            for (auto u: pr) {
                  if (taken[u.first] && taken[u.second]) continue;
                  if (u.first == x) {
                        taking = u.second;
                        break;
                  } else if (u.second == x) {
                        taking = u.first;
                        break;
                  }
            }

            if (taking != 0) {
                  cout << taking << endl;
                  taken[taking] = 1;
            } else {
                  for (auto u: pr) {
                        if (taken[u.first] && taken[u.second]) continue;
                        if (p[u.first] > p[u.second]) {
                              taking = u.first;
                        } else {
                              taking = u.second;
                        }
                        break;
                  }

                  if (taking != 0) {
                        cout << taking << endl;
                        taken[taking] = 1;
                  } else {
                        for (int i = 1; i <= 2*n; i++) {
                              if (taken[i]) continue;
                              if (p[i] > p[taking]) taking = i;
                        }
                        cout << taking << endl;
                        taken[taking] = 1;
                  }
            }
      }
      exit(0);
}

signed main() {
	//ios::sync_with_stdio(0); cin.tie(0);

      cin >> n >> m;
      for (int i = 1; i <= 2*n; i++) {
            cin >> p[i];
      }
      for (int i = 0; i < m; i++) {
            int a, b; cin >> a >> b;
            pr.push_back({a, b});
      }

      int t; cin >> t;
      if (t == 1) {
            solve1();
      } else {
            solve2();
      }

	return 0;
}