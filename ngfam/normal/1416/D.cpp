#include<bits/stdc++.h>

using namespace std;

const int maxn = 500005;

int n, m, q;
int a[maxn];
int perm[maxn];
int del_time[maxn];
pair<int, int> edge[maxn], queries[maxn];

int cnt[maxn];
int lab[maxn], inv[maxn];
vector<int> vertices[maxn];
vector<pair<int, int>> root[maxn];

int find(int v) {
  return (lab[v] == -1 ? v : find(lab[v]));
}

void join(int u, int v, int w) {
  if ((u = find(u)) == (v = find(v))) return;
  if (vertices[u].size() < vertices[v].size()) swap(u, v);
  lab[v] = u;
  for(int x : vertices[v]) {
    vertices[u].push_back(x);
    root[x].emplace_back(u, w);
  }
}

bool is_connected(int u, int v, int w) {
  for(auto p : root[u]) {
    if(p.second >= w){
      ++cnt[p.first];
    }
  }

  int ans = 0;

  for(auto q : root[v]) {
    if(q.second >= w) {
      if(cnt[q.first]) ans = 1;
    }
  }

  for(auto p : root[u]) {
    cnt[p.first] = 0;
  }
  return ans;
}

#define lc ((x << 1))
#define rc ((x << 1) | 1)
#define mid ((l + r) >> 1)

pair<int, int> tree[maxn << 2];

pair<int, int> query(int l, int r) {
  pair<int, int> res = make_pair(-1, -1);
  for(l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
    if (l&1) res = max(res, tree[l++]);
    if (r&1) res = max(res, tree[--r]);
  }
  return res;
}

void modify(int p, pair<int, int> val) {
  for(tree[p += n] = val; p > 1; p >>= 1) tree[p >> 1] = max(tree[p], tree[p^1]);
}

#undef mid

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  cin >> n >> m >> q;

  for(int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  for(int i = 0; i < m; ++i) {
    perm[i] = i;
    del_time[i] = maxn;
    cin >> edge[i].first >> edge[i].second;
    --edge[i].first; --edge[i].second;
  }

  for(int i = 0; i < q; ++i) {
    cin >> queries[i].first >> queries[i].second;
    --queries[i].second;
    if(queries[i].first == 2) {
      del_time[queries[i].second] = i;
    }
  }

  sort(perm, perm + m, [&](int u, int v) {
    return del_time[u] > del_time[v];
  });

  memset(lab, -1, sizeof lab);

  for(int i = 0; i < n; ++i){
    root[i].emplace_back(i, maxn);
    vertices[i].push_back(i);
  }

  for(int i = 0; i < m; ++i) {
    int id = perm[i];
    join(edge[id].first, edge[id].second, del_time[id]);
  }

  vector<int> all;
  for(int i = 0; i < n; ++i) {
    if (find(i) == i) {
      for(int x : vertices[i]) all.push_back(x);
    }
  }

  for(int i = 0; i < n; ++i) {
    int v = all[i];
    inv[v] = i;
    modify(i, make_pair(a[v], i));
  }


  for(int i = 0; i < q; ++i) {
    if(queries[i].first == 1) {
      int v = queries[i].second, id = inv[v], ansl = id, ansr = id;
      {
        int l = 0, r = id;
        while(l <= r) {
          int mid = (l + r) >> 1;
          if(is_connected(all[id], all[mid], i)) {
            r = mid - 1;
            ansl = mid;
          }
          else {
            l = mid + 1;
          }
        }
      }
      {
        int l = id, r = n - 1;
        while(l <= r) {
          int mid = (l + r) >> 1;
          if(is_connected(all[id], all[mid], i)) {
            l = mid + 1;
            ansr = mid;
          }
          else{
            r = mid - 1;
          }
        }
      }


      auto ans = query(ansl, ansr);
      if(ans.first != -1) {
        modify(ans.second, make_pair(-1, -1));
        cout << ans.first << "\n";
      }
      else {
        cout << 0 << "\n";
      }
    }
  }



  return 0;
}