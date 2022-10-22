#include <bits/stdc++.h>
#include <variant>
#define FOR(i,k,n)  for(int i = (k);i < (n);++i)
#define REP(i,n)    FOR(i,0,n)
#define ALL(x) begin(x),end(x)

using namespace std;
using ll = int64_t;
using vecint = vector<int>;
using vecll = vector<ll>;

struct Node {
  Node() : children(26, nullptr) {}
  vector<Node*> children;
};

int merge(const Node& node) {
  int sum = 0;
  int cnt = 0;
  REP(i,26) {
    if (node.children[i] != nullptr) ++cnt;
  }
  if (cnt >= 2) sum += cnt - 1;
  if (cnt <= 1) return 0;
  REP(i,26) {
    Node nx;
    REP(j,26) {
      if (node.children[j] != nullptr) {
        nx.children[j] = node.children[j]->children[i];
      }
    }
    sum += merge(nx);
  }
  return sum;
}

Node* dfs(const vector<vector<tuple<int,char>>>& g, int i) {
  auto ptr = new Node;
  for (auto&&[to, ch] : g[i]) {
    ptr->children[ch-'a'] = dfs(g, to);
  }
  return ptr;
}

void solve(const Node& node, int depth, vecint& ans) {
  ans[depth] += merge(node);
  bool has_child = false;
  REP(i,26) {
    if (node.children[i] != nullptr) {
      has_child = true;
      solve(*node.children[i], depth+1, ans);
    }
  }
  if (has_child) ++ans[depth];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin>>n;
  vector<vector<tuple<int,char>>> g(n);
  REP(i,n-1) {
    int u,v;
    string x;
    cin>>u>>v>>x;
    --u;--v;
    g[u].emplace_back(v, x[0]);
  }
  auto root = dfs(g, 0);
  vecint ans(n);
  solve(*root, 1, ans);
  auto itr = max_element(ALL(ans));
  cout<<n-*itr<<endl;
  cout<<(itr-begin(ans))<<endl;
  return 0;
}