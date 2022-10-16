#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define N 50

int n, k;
int w[N];
bool g[N][N], g1[N][N];
int res;

void maximumIndependentSet(vi& oldSet, int ne, int ce, int curSum) {
	int nod = 0;
	int minnod = ce;
	int fixp = -1;
	int s = -1;

	for (int i = 0; i < ce && minnod != 0; i++) {
		int p = oldSet[i];
		int cnt = 0;
		int pos = -1;

		for (int j = ne; j < ce; j++)
			if (g[p][oldSet[j]]) {
				if (++cnt == minnod)
					break;
				pos = j;
			}

			if (minnod > cnt) {
				minnod = cnt;
				fixp = p;
				if (i < ne)
					s = pos;
				else {
					s = i;
					nod = 1;
				}
			}
	}

	vi newSet(ce);

	for (int k = minnod + nod; k >= 1; k--) {
		int sel = oldSet[s];
		oldSet[s] = oldSet[ne];
		oldSet[ne] = sel;

		int newne = 0;
		for (int i = 0; i < ne; i++)
			if (!g[sel][oldSet[i]])
				newSet[newne++] = oldSet[i];

		int newce = newne;
		long remain = 0;
		for (int i = ne + 1; i < ce; i++)
			if (!g[sel][oldSet[i]]) {
				newSet[newce++] = oldSet[i];
				remain += w[oldSet[i]];
			}

			curSum += w[sel];

			if (newce == 0) {
				res = max(res, curSum);
			} else if (newne < newce) {
				if (curSum + remain > res)
					maximumIndependentSet(newSet, newne, newce, curSum);
			}

			curSum -= w[sel];

			++ne;
			if (k > 1)
				for (s = ne; !g[fixp][oldSet[s]]; s++)
					;
	}
}

void init() {
      memset(g1, 0, sizeof(g1));

      int p, q; cin >> p >> q;
      vector<int> s(p);
      vector<string> ss(p);
      int petr = 0;

      map<string, int> id;
      for (int i = 0; i < p; i++) {
            cin >> s[i];
            if (s[i] == 2) {
                  cin >> ss[i];

                  if (id.find(ss[i]) == id.end()) {
                        id[ss[i]] = petr++;
                  }
            }
      }

      set<int> st;
      for (int i = 0; i < p; i++) {
            if (s[i] == 1) {
                  for (int u: st) {
                        for (int v: st) {
                              if (u != v) g1[v][u] = g1[u][v] = 1;
                        }
                  }
                  st.clear();
            } else {
                  st.insert(id[ss[i]]);
            }
      }
      for (int u: st) {
            for (int v: st) {
                  if (u != v) g1[v][u] = g1[u][v] = 1;
            }
      }
      st.clear();

      n = q;
}

int main() {
      ios::sync_with_stdio(0); cin.tie(0);

	int t = 1;
	while (t-- > 0) {
            init();

		vi w1(n);
		for (int i = 0; i < n; i++) {
			w1[i] = 1;
		}

		int q = 1;

		for (int i = 0; i < q; i++) {
			int qn = n;

			vi a(qn);
			for (int j = 0; j < qn; j++) a[j] = j;

			for (int j = 0; j < qn; j++){
				w[j] = w1[a[j]];
				for (int k = 0; k < qn; k++) g[j][k]=g1[a[j]][a[k]];
			}

			vi all(qn);
			for (int i = 0; i < qn; i++) all[i] = i;

			res = 0;
			maximumIndependentSet(all, 0, qn, 0);

			cout << res;
		}

		cout << '\n';
	}
}