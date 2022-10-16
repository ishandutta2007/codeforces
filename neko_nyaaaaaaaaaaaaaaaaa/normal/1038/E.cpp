/*
      https://codeforces.com/contest/1038/problem/E


*/

#include <bits/stdc++.h>
using namespace std;

struct DSU {
	vector<int> P, S;
	DSU(int n) {
		P.resize(n+1);
		S.resize(n+1, 1);
		for (int i = 1; i <= n; i++) P[i] = i;
	}

	void reset() {
		for (int i = 1; i <= P.size(); i++) P[i] = i, S[i] = 1;
	}

	int find(int x) {
		while (x != P[x]) x = P[x];
		return x;
	}

	void merge(int a, int b) {
		a = find(a); b = find(b);
		if (S[a] < S[b]) swap(a, b);

		S[a] += S[b];
		P[b] = a;
	}

	int same(int a, int b) {
		return find(a) == find(b);
	}
};

int n;
DSU d(4);
int deg[5];
int ans[5];
int x[101], y[101], w[101];

int output(int ind) {
      memset(ans, 0, sizeof(ans));
      for (int i = 0; i < n; i++) {
            if (i == ind) continue;
            ans[d.find(x[i])] += w[i];
      }
      return *max_element(ans, ans + 5);
}

int solve(int a, int b) {
      d.reset(); int ind = -1;
      for (int i = 0; i < n; i++) {
            if (x[i] == a && y[i] == b) {
                  if (ind == -1 || w[i] < w[ind]) ind = i;
            }
      }
      if (ind == -1) return 0;

      for (int i = 0; i < n; i++) {
            if (i == ind) continue;
            if (!d.same(x[i], y[i])) {d.merge(x[i], y[i]);}
      }
      return output(ind);
}

signed main() {
      ios::sync_with_stdio(0); cin.tie(0);

      cin >> n;
      int cc = 4;
      for (int i = 0; i < n; i++) {
            cin >> x[i] >> w[i] >> y[i];
            if (x[i] > y[i]) swap(x[i], y[i]);
            if (!d.same(x[i], y[i])) {d.merge(x[i], y[i]); cc--;}
            deg[x[i]]++; deg[y[i]]++;
      }

      int c = 0;
      for (int i = 1; i <= 4; i++) {
            c += deg[i] % 2;
      }

      if (c == 4 && cc == 1) {
            int answer = 0;
            for (int i = 1; i <= 4; i++) {
                  for (int j = 1; j < i; j++) {
                        answer = max(answer, solve(j, i));
                  }
            }
            cout << answer;
      } else {
            cout << output(-1);
      }

      return 0;
}