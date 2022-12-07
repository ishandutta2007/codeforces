#include<bits/stdc++.h>

using namespace std;

const int MAXN = 3030;

struct dsu{
  int par[MAXN];
  void clear() {
    for(int i = 0; i < MAXN; ++i) par[i] = i;
  }
  int find(int x) {
    return par[x] == x ? x : par[x] = find(par[x]);
  }
  bool join(int u, int v) {
    if((u = find(u)) == (v = find(v))) return false;
    par[v] = u;
    return true;
  }
}dsu;

// one swap can conneect 2 rings, break a ring


int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);


  int n; cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; ++i) cin >> a[i], a[i]--;

  int m; cin >> m;

 /***
   a ring of length l will cost l - 1
 ***/



  vector<pair<int, int>> moves;

  int step = 0;

  while(true) {
    dsu.clear();

    int cst = 0;
    for(int i = 0; i < n; ++i) cst += dsu.join(i, a[i]);

    vector<int> b(n);
    for(int i = 0; i < n; ++i) b[a[i]] = i;

    if(cst < m) { /// should connect 2 rings
      int u = 0;
      int v = 1;
      while(dsu.find(u) == dsu.find(v)) v++;
      moves.emplace_back(u, v);
      swap(a[u], a[v]);
    }
    else if(cst > m){ /// break a ring
      int u = 0;
      while(a[u] == u) u++;
      int v = u + 1;
      while(dsu.find(v) != dsu.find(u)) v++;
      moves.emplace_back(u, v);
      swap(a[u], a[v]);
    }
    else break;
  }

  cout << moves.size() << "\n";
  for(auto &p : moves) cout << p.first + 1 << " " << p.second + 1 << " ";

  return 0;
}