#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;
const int MOD = 1000000007;
const int INF = 1e9;

int n, m, k;
string p[N], s[N];

char ss[5];
int mt[N];

int deg[N];
vector<int> edges[N];

vector<string> patterns(string s) {
  vector<string> ret;
  for (int i = 0; i < 1 << k; ++i) {
    string p;
    for (int j = 0; j < k; ++j) {
      if (i >> j & 1) p += s[j];
      else p += '_';
    }
    ret.push_back(p);
  }
  return ret;
}

int solve() {
  scanf("%d %d %d", &n, &m, &k);
  map<string, int> frst;
  for (int i = 0; i < n; ++i) {
    scanf("%s", ss);
    p[i] = string(ss);

    frst[p[i]] = -1;
  }
  for (int i = 0; i < m; ++i) {
    scanf("%s %d", ss, &mt[i]);
    --mt[i];
    s[i] = string(ss);

    for (int j = 0; j < k; ++j) {
      if (p[mt[i]][j] != '_' && p[mt[i]][j] != s[i][j]) return 0 * printf("NO\n");
    }
    if (frst[p[mt[i]]] != -1 && frst[p[mt[i]]] != mt[i]) return 0 * printf("NO\n");
    frst[p[mt[i]]] = mt[i];
  }
  for (int i = 0; i < n; ++i) {
    if (frst[p[i]] == -1) frst[p[i]] = i;
  }

  for (int i = 0; i < m; ++i) {
    int u = frst[p[mt[i]]];
    for (string pp : patterns(s[i])) {
      if (pp == p[mt[i]]) continue;
      if (frst.find(pp) != frst.end()) {
        int v = frst[pp];

        edges[u].push_back(v);
        ++deg[v];
        // cerr << u << " " << v << endl;
      }
    }
  }

  queue<int> q;
  vector<int> ans;
  for (int i = 0; i < n; ++i) {
    if (frst[p[i]] != -1 && deg[i] == 0) q.push(i);
  }
  while (q.size()) {
    int u = q.front();
    q.pop();
    ans.push_back(u);

    for (int v : edges[u]) {
      if (--deg[v] == 0) {
        q.push(v);
      }
    }
  }
  for (int i = 0; i < n; ++i) if (frst[p[i]] == -1) ans.push_back(i);

  if (ans.size() < n) return 0 * printf("NO\n");
  printf("YES\n");
  for (int u : ans) printf("%d ", u + 1);
  printf("\n");
  return 0;
}

int main() {
  int t = 1;
  // scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc+1);
    solve();
  }
  return 0;
}