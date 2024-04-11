#include<bits/stdc++.h>

using namespace std;

const int MAXN = 200010;

int done[MAXN];
int answer[MAXN];
set < int > s[MAXN];
vector < int > of[MAXN];
set < pair < int, int > > que;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int n, m; cin >> n >> m;

  for(int i = 0; i < n; ++i) {
    int k; cin >> k;
    for(int j = 0 ; j < k; ++j) {
      int x; cin >> x;
      s[i].insert(x);
      of[abs(x)].push_back(i);
    }
    que.emplace((int)s[i].size(), i);
  }

  while(!que.empty()) {
    int id = que.begin() -> second; que.erase(que.begin());
    if(s[id].empty()) return cout << "NO", 0;
    int x = *s[id].begin();
    if(x > 0) answer[x] = 1;
    done[id] = 1;
    for(int v : of[abs(x)]) if(!done[v]){
      que.erase(make_pair((int)s[v].size(), v));
      if(s[v].count(x)) continue;
      s[v].erase(x);
      s[v].erase(-x);
      que.emplace((int)s[v].size(), v);
    }
  }

  cout << "YES\n";
  for(int i = 0; i < m; ++i) cout << answer[i + 1];

  return 0;
}