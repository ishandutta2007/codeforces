#include <bits/stdc++.h>
#define int long long
using namespace std;

const int L = 12;
const int nbMasques = 1 << L;
const int INF = 1e18;
int nbMots;

struct AhoCorasick {
  enum { alpha = 12, first = 'a' };

  struct Node {
    int back, next[alpha], start = -1, end = -1, totOcc = 0;
    Node(int v) { memset(next, v, sizeof(next)); }
  };

  vector<Node> N;
  vector<int> backp;

  void insert(string &s, int j, int val) {
    assert(!s.empty());
    int n = 0;
    for (char c : s) {
      int &m = N[n].next[c - first];
      if (m == -1) {
        n = m = N.size();
        N.emplace_back(-1);
      } else {
        n = m;
      }
    }
    if (N[n].end == -1)
      N[n].start = j;
    backp.push_back(N[n].end);
    N[n].end = j;
    N[n].totOcc += val;
  }

  AhoCorasick(vector<pair<string, int>> &pat) : N(1, -1) {
    for (int i = 0; i < (int)pat.size(); ++i)
      insert(pat[i].first, i, pat[i].second);
    N[0].back = N.size();
    N.emplace_back(0);

    queue<int> q;
    for (q.push(0); !q.empty(); q.pop()) {
      int n = q.front(), prev = N[n].back;
      for (int i = 0; i < alpha; ++i) {
        int &ed = N[n].next[i], y = N[prev].next[i];
        if (ed == -1)
          ed = y;
        else {
          N[ed].back = y;
          (N[ed].end == -1 ? N[ed].end : backp[N[ed].start]) = N[y].end;
          N[ed].totOcc += N[y].totOcc;
          q.push(ed);
        }
      }
    }
  }
};

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> nbMots;
  vector<string> mots(nbMots);
  vector<pair<string, int>> patterns;
  for (string &s : mots) {
    int val;
    cin >> val;
    cin >> s;
    array<array<int, L>, L> adj;
    for (int i = 0; i < L; ++i)
      adj[i].fill(0);
    for (int i = 0; i < (int)s.size() - 1; ++i) {
      adj[s[i] - 'a'][s[i + 1] - 'a'] = 1;
      adj[s[i + 1] - 'a'][s[i] - 'a'] = 1;
    }
    bool ok = true;
    array<int, L> deg;
    deg.fill(0);
    for (int i = 0; i < L; ++i) {
      for (int j = 0; j < L; ++j)
        deg[i] += adj[i][j];
      if (deg[i] > 2)
        ok = false;
    }
    if (!ok)
      continue;
    int leaf = 0;
    while (leaf < L and deg[leaf] != 1)
      ++leaf;
    if (leaf == L)
      continue;
    string pat = string(1, 'a' + leaf);
    int prv = -1;
    while (true) {
      for (int i = 0; i < L; ++i)
        if (adj[leaf][i] and i != prv) {
          prv = leaf;
          leaf = i;
          break;
        }
      pat += 'a' + leaf;
      if (deg[leaf] == 1)
        break;
    }
    patterns.emplace_back(pat, val);
    reverse(pat.begin(), pat.end());
    patterns.emplace_back(pat, val);
  }

  AhoCorasick aho(patterns);

  int nbEtats = aho.N.size();

  array<vector<int>, nbMasques> dp;
  array<vector<pair<int, int>>, nbMasques> pred;
  for (int i = 0; i < nbMasques; ++i) {
    dp[i].assign(nbEtats, -INF);
    pred[i].assign(nbEtats, pair(-1, -1));
  }
  dp[0][0] = 0;
  for (int msk = 0; msk < nbMasques; ++msk) {
    for (int etat = 0; etat < nbEtats; ++etat) {
      for (int nxt = 0; nxt < L; ++nxt)
        if (!((1 << nxt) & msk)) {
          int nxtEtat = aho.N[etat].next[nxt];
          int nxtMsk = msk | (1 << nxt);
          int nxtSol = dp[msk][etat] + aho.N[nxtEtat].totOcc;
          if (nxtSol > dp[nxtMsk][nxtEtat]) {
            dp[nxtMsk][nxtEtat] = nxtSol;
            pred[nxtMsk][nxtEtat] = pair(nxt, etat);
          }
        }
    }
  }
  string sol = "";
  int msk = nbMasques - 1;
  int curEtat = 0;
  for (int i = 1; i < nbEtats; ++i)
    if (dp[msk][i] > dp[msk][curEtat])
      curEtat = i;
  while (msk) {
    auto [c, nxtEtat] = pred[msk][curEtat];
    sol += char('a' + c);
    curEtat = nxtEtat;
    msk ^= 1 << c;
  }
  reverse(sol.begin(), sol.end());
  cout << sol << endl;
}