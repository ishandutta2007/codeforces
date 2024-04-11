#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 3e5;

vector<int> adj1[MAXN], adj2[MAXN];
int deb[MAXN], fin[MAXN];
int curTime;
int ans;
set<pair<int, int>> curSet;

void dfs1(int u) {
  deb[u] = curTime++;
  for (auto v : adj2[u])
    dfs1(v);
  fin[u] = curTime++;
}

void dfs2(int u) {

  vector<pair<int, int>> erased;
  auto it = curSet.lower_bound(make_pair(deb[u], 0));
  if (it == curSet.end() or it->first > fin[u]) {
    if (it != curSet.begin()) {
      --it;
      if (it->second > fin[u]) {
        erased.push_back(*it);
        curSet.erase(it);
      }
    }
    curSet.insert(make_pair(deb[u], fin[u]));
  }

  ans = max(ans, (int)curSet.size());
  for (auto v : adj1[u])
    dfs2(v);
  if (curSet.count(make_pair(deb[u], fin[u])))
    curSet.erase({deb[u], fin[u]});
  for (auto p : erased)
    curSet.insert(p);
}

void solve() {
  int nbSommets;
  cin >> nbSommets;
  curTime = 0;
  ans = 0;
  for (int iSommet = 0; iSommet < nbSommets; ++iSommet) {
    adj1[iSommet].clear();
    adj2[iSommet].clear();
  }

  for (int iSommet = 1; iSommet < nbSommets; ++iSommet) {
    int p;
    cin >> p;
    adj1[p - 1].push_back(iSommet);
  }
  for (int iSommet = 1; iSommet < nbSommets; ++iSommet) {
    int p;
    cin >> p;
    adj2[p - 1].push_back(iSommet);
  }
  dfs1(0);
  dfs2(0);
  cout << ans << '\n';
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nbTests;
  cin >> nbTests;
  for (int iTest(0); iTest < nbTests; ++iTest)
    solve();
}