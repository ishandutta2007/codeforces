#include <bits/stdc++.h>
#define int long long
using namespace std;

/*
 * Bipartite matching in O(sqrt(V) * E).
 * g = neighbors of left partition
 * btoa = filled with -1, size of right partition
 * btoa[i] = vertex matched with i (i on the right), -1 if unmatched
 */

bool dfsMatching(int a, int L, vector<vector<int>> &g, vector<int> &btoa,
                 vector<int> &A, vector<int> &B) {
  if (A[a] != L)
    return 0;
  A[a] = -1;
  for (int b : g[a])
    if (B[b] == L + 1) {
      B[b] = 0;
      if (btoa[b] == -1 or dfsMatching(btoa[b], L + 1, g, btoa, A, B))
        return btoa[b] = a, 1;
    }
  return 0;
}

int hopcroftKarp(vector<vector<int>> &g, vector<int> &btoa) {
  int res = 0;
  vector<int> A(g.size()), B(btoa.size()), cur, next;
  for (;;) {
    fill(A.begin(), A.end(), 0LL);
    fill(B.begin(), B.end(), 0LL);
    cur.clear();
    for (int a : btoa)
      if (a != -1)
        A[a] = -1;
    for (int a = 0; a < (int)g.size(); ++a)
      if (!A[a])
        cur.push_back(a);
    for (int lay = 1;; lay++) {
      bool isLast = 0;
      next.clear();
      for (int a : cur)
        for (int b : g[a]) {
          if (btoa[b] == -1) {
            B[b] = lay;
            isLast = 1;
          } else if (btoa[b] != a and !B[b]) {
            B[b] = lay;
            next.push_back(btoa[b]);
          }
        }
      if (isLast)
        break;
      if (next.empty())
        return res;
      for (int a : next)
        A[a] = lay;
      cur.swap(next);
    }
    for (int a = 0; a < (int)g.size(); ++a)
      res += dfsMatching(a, 0, g, btoa, A, B);
  }
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nbDev, nbDoc;
  cin >> nbDev >> nbDoc;

  vector<string> access(nbDev);
  for (string &s : access)
    cin >> s;

  vector<vector<int>> adj(nbDoc);
  for (int i = 0; i < nbDoc; ++i)
    for (int j = 0; j < nbDoc; ++j)
      if (i != j) {
        bool ok = true;
        bool equiv = true;
        for (int k = 0; k < nbDev; ++k) {
          ok &= access[k][i] != '1' or access[k][j] == '1';
          equiv &= access[k][i] == access[k][j];
        }
        if (ok and (!equiv or i < j))
          adj[j].push_back(i);
      }

  vector<int> matchedWith(nbDoc, -1);
  int nbChemins = nbDoc - hopcroftKarp(adj, matchedWith);
  cout << nbChemins << endl;
  vector<int> nxt(nbDoc, -1);
  for (int i = 0; i < nbDoc; ++i)
    if (matchedWith[i] != -1)
      nxt[matchedWith[i]] = i;

  vector<vector<int>> chemins;
  vector<int> idChemin(nbDoc), posChemin(nbDoc);
  for (int i = 0; i < nbDoc; ++i)
    if (matchedWith[i] == -1) {
      vector<int> cur;
      int u = i;
      int p = 2;
      while (u != -1) {
        cur.push_back(u);
        idChemin[u] = chemins.size();
        posChemin[u] = p++;
        u = nxt[u];
      }
      chemins.push_back(cur);
    }
  for (int i = 0; i < nbDoc; ++i)
    cout << idChemin[i] + 1 << ' ';
  cout << endl;
  for (int i = 0; i < nbDoc; ++i)
    cout << posChemin[i] << ' ';
  cout << endl;

  for (int i = 0; i < nbDev; ++i) {
    for (int iChemin = 0; iChemin < nbChemins; ++iChemin) {
      int val = 1;
      while (val - 1 < (int)chemins[iChemin].size() and
             access[i][chemins[iChemin][val - 1]] == '1')
        ++val;
      cout << val << ' ';
    }
    cout << endl;
  }
}