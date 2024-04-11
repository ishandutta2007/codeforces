#include <bits/stdc++.h>

using namespace std;

struct TVertex{
  int par;
  int cntx;
  int cnty;
  TVertex(){
    par = cntx = cnty = 0;
  }
};

const int N = 300005;

TVertex lab[N + N];

int find(int x) {
  if(lab[x].par < 0) return x;
  return find(lab[x].par);
}

#define mid ((l + r) >> 1)

vector < pair < int, int > > edges[N * 4];
void addEdge(int x, int l, int r, int u, int v, pair < int, int > edge){
  if(r < u || l > v) return;
  if(l >= u && r <= v) {
    edges[x].emplace_back(edge);
    return;
  }
  addEdge(x + x, l, mid, u, v, edge);
  addEdge(x + x + 1, mid + 1, r, u, v, edge);
}

long long answer[N];

void solve(int x, int l, int r, long long cur) {
  list < pair < int, TVertex > > lst;
  for(auto &e : edges[x]) {
    int u = find(e.first), v = find(e.second);
    if(u == v) continue;
    if(lab[u].par > lab[v].par) swap(u, v);
    
    lst.emplace_front(u, lab[u]);
    lst.emplace_front(v, lab[v]);
    cur += 1LL * lab[u].cntx * lab[v].cnty;
    cur += 1LL * lab[u].cnty * lab[v].cntx;
    lab[u].par += lab[v].par;
    lab[u].cntx += lab[v].cntx;
    lab[u].cnty += lab[v].cnty;
    lab[v].par = u;
  }
  if(l == r) {
    answer[r] = cur;
  }
  else{
    solve(x + x, l, mid, cur);
    solve(x + x + 1, mid + 1, r, cur);
  }
  for(auto p : lst) {
    lab[p.first] = p.second;
  }
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  int q;
  cin >> q;
  
  map < pair < int, int >, int > f;
  
  for(int i = 1; i <= q; ++i) {
    int u, v;
    cin >> u >> v;

    v += N;

    if(f.count(make_pair(u, v))) {
      addEdge(1, 1, q, f[make_pair(u, v)], i - 1, make_pair(u, v));
      f.erase(make_pair(u, v));
    }
    else{
      f[make_pair(u, v)] = i;
    }
  }

  while(!f.empty()) {
    auto p = f.begin() -> first;
    addEdge(1, 1, q, f[p], q, p);
    f.erase(f.begin());
  }

  for(int i = 1; i < N + N; ++i) {
    lab[i].par = -1;
    lab[i].cntx = (i < N);
    lab[i].cnty = (i > N);
  }

  solve(1, 1, q, 0);

  for(int i = 1; i <= q; ++i) {
    cout << answer[i] << " ";
  }

  return 0;
}