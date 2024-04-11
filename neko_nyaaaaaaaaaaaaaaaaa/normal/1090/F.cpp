#include <bits/stdc++.h>
using namespace std;

#define int long long

struct linear_equation{
	double eps = 1e-12;
	int n, m;
	vector<vector<int>> a;
	vector<int> b;
	vector<int> ans;

	linear_equation(vector<vector<int>> a, vector<int> b) {
		this->a = a;
		this->b = b;

		n = a.size(); m = a[0].size();
		for (int i = 0; i < n; i++) {
			this->a[i].push_back(b[i]);
		}
		ans.resize(m);
	}

	int gauss() {
		vector<int> ind(m, -1);
		for (int col = 0, row = 0; col < m && row < n; col++) {
			int piv = row;
			for (int i = row; i < n; i++) {
				if (abs(a[i][col]) > abs(a[piv][col])) piv = i;
			}

			if (abs(a[piv][col]) < eps) continue;

			for (int i = col; i <= m; i++) swap(a[piv][i], a[row][i]);
			ind[col] = row;

			for (int i = 0; i < n; i++) {
				if (i != row) {
					double c = a[i][col]*1.0/a[row][col];
					for (int j = col; j <= m; j++) {
						a[i][j] -= a[row][j] * c;
					}
				}
			}

			row++;
		}

		// solving
		for (int i = 0; i < m; i++) {
			if (ind[i] != -1) {
                        if (a[ind[i]][i] == 0 || a[ind[i]][m] % a[ind[i]][i]) return 0;
                        ans[i] = a[ind[i]][m]/a[ind[i]][i];
                  }
		}

		for (int i = 0; i < n; i++) {
			double sum = 0;
			for (int j = 0; j < m; j++) {
				sum += ans[j]*a[i][j];
			}

			if (abs(sum - a[i][m]) > eps) return 0;
		}

		for (int i = 0; i < m; i++) {
			if (ind[i] == -1) return 2;		// infinity roots
		}

		return 1;
	}

	vector<int> solve() {
		int k = gauss();
		if (k == 1) {
			return ans;
		} else {
		      ans.clear(); return ans;
		}
	}
};

map<tuple<int, int, int>, int> mp;

//int inp[] = {0, 1, 0, 2, 1, 3, 1, 0, 2, 1, 3};

int query(int x, int y, int z) {
      vector<int> k = {x, y, z};
      sort(k.begin(), k.end());
      tuple<int, int, int> q = make_tuple(k[0], k[1], k[2]);

      if (mp.find(q) != mp.end()) {
            return mp[q];
      } else {
            cout << "? " << k[0] << ' ' << k[1] << ' ' << k[2] << endl;

//            int a = 0, b = 1000000000;
//            for (int i = 0; i < 3; i++) {
//                  a = max(a, inp[k[i]]);
//                  b = min(b, inp[k[i]]);
//            }
//            int xx = a+b;
//            return mp[q] = xx;

            int x; cin >> x;
            return mp[q] = x;
      }
}

vector<int> solve5(int s) {
      for (int i = 1; i <= 5; i++) {
            for (int j = i+1; j <= 5; j++) {
                  for (int k = j+1; k <= 5; k++) {
                        query(i+s, j+s, k+s);
                  }
            }
      }

      vector<int> ord(1, 0);
      for (int i = 1; i <= 5; i++) ord.push_back(i+s);

      do {
            vector<vector<int>> a;
            vector<int> b;

            for (int i = 1; i <= 5; i++) {
                  for (int j = i+1; j <= 5; j++) {
                        for (int k = j+1; k <= 5; k++) {
                              int x = query(i+s, j+s, k+s);

                              b.push_back(x);

                              vector<int> eq(6);
                              if (ord[i] > ord[j] && ord[i] > ord[k]) {
                                    eq[ord[i] - s]++;
                              } else if (ord[j] > ord[i] && ord[j] > ord[k]) {
                                    eq[ord[j] - s]++;
                              } else if (ord[k] > ord[j] && ord[k] > ord[i]) {
                                    eq[ord[k] - s]++;
                              }

                              if (ord[i] < ord[j] && ord[i] < ord[k]) {
                                    eq[ord[i] - s]++;
                              } else if (ord[j] < ord[i] && ord[j] < ord[k]) {
                                    eq[ord[j] - s]++;
                              } else if (ord[k] < ord[j] && ord[k] < ord[i]) {
                                    eq[ord[k] - s]++;
                              }

                              eq.erase(eq.begin());
                              a.push_back(eq);
                        }
                  }
            }

            linear_equation e(a, b);
            vector<int> ans = e.solve();

            if (ans.size() == 0) continue;
            else {
                  vector<int> actual_ans;
                  for (int i = 1; i < ord.size(); i++) {
                        actual_ans.push_back(ans[ord[i] - 1 - s]);
                  }
                  return actual_ans;
            }

      } while (next_permutation(ord.begin()+1, ord.end()));
}

void answer(vector<int> ans) {
      cout << "! ";
      for (int i: ans) cout << i << ' ';
      cout << endl;
      exit(0);
}

signed main() {
      //ios::sync_with_stdio(0); cin.tie(0);

      int n; cin >> n;
      vector<int> ans;
      for (int i = 0; i+5 <= n; i += 5) {
            vector<int> s = solve5(i);
            for (int j: s) ans.push_back(j);
      }

      if (n % 5 == 0) answer(ans);

      vector<int> s = solve5(n - 5);
      while (s.size() > n % 5) s.erase(s.begin());

      for (int j: s) ans.push_back(j);
      answer(ans);

      //cout << ans;

      return 0;
}