// cycle xor space is pretty nice
// but not this fucking problem
//
// idek why the setter made it even more annoying with the tricycle going around vertice 0
// its like u learn nothing but some physical memory for your hands solving this problem
//
// Like author, like problem. Fuck you mr Danil.

#include<bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
const int SPACE = 374;

int add(int x, int y) {
  x += y;
  if(x >= mod) x -= mod;
  if(x < 0) x += mod;
  return x;
}

int sub(int x, int y) {
  x -= y;
  if(x >= mod) x -= mod;
  if(x < 0) x += mod;
  return x;
}

int mult(int x, int y) {
  return 1LL * x * y % mod;
}

int binpow(int x, int y) {
  int ret = 1;
  for(; y > 0; x = mult(x, x), y >>= 1) {
    if(y & 1) ret = mult(ret, x);
  }
  return ret;
}

int inverse_modulo(int x) {
  return binpow(x, mod - 2);
}

const int LG = 5;
const int MAXK = 35;
const int MAXN = 100005;

typedef array<int, 5> ftype;

map<ftype, int> id;

bool normalize(ftype &base) {
  bool tag = false;
  for(int i = LG - 1; i >= 0; --i) {
    for(int j = 0; j < i; ++j) {

      if(base[i] & (1 << j)) {
        base[i] ^= base[j];
        if(base[j] > 0) tag = true;
      }
    }
  }
  return tag;
}

ftype ins(ftype base, int vec) {
  for(int i = LG - 1; i >= 0; --i) {
    if(vec & (1 << i)) {
      if(base[i] > 0) vec ^= base[i];
      else {
        base[i] = vec;
        break;
      }
    }
  }
  normalize(base);
  return base;
}

void debug(ftype a) {
  cout << "[";
  for(int i = 0; i < LG; ++i) cout << a[i] << (i == LG - 1 ? "" : ", ");
  cout << "]" << endl;
}

int nxt[SPACE + 2][1 << LG];
ftype of[SPACE + 2];

int h[MAXN];
int visited[MAXN];
vector<pair<int ,int>> g[MAXN];

int used[MAXN];
int baseid[MAXN];
int currentmark = 0;

int f[MAXN][SPACE + 2], foo[MAXN][SPACE + 2];

void dfs(int v, int p, int &cur) {
  visited[v] = currentmark;

  for(auto &e : g[v]) {
    int s = e.first, w = e.second;
    if(s == p || s == 0) continue;
    if(visited[s]) {
      if(s < v) {
        cur = nxt[cur][h[s] ^ h[v] ^ w];
        }
    }
    else {
      h[s] = h[v] ^ w;
      dfs(s, v, cur);
    }
  }
}

map<pair<int, int>, int> weights;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  queue<ftype> que;
  que.push(ftype());

  id[ftype()] = 0;

  while(!que.empty()) {
    ftype cur = que.front();
    que.pop();

    of[id[cur]] = cur;

    for(int i = 0; i < 32; ++i) {
      ftype now = ins(cur, i);
      normalize(now);
      if(!id.count(now)) {
        id[now] = id.size();
        que.push(now);
      }
      nxt[id[cur]][i] = id[now];
    }
  }

  for(int i = 0; i < SPACE; ++i) {
    for(int j = 0; j < 32; ++j) {
      nxt[SPACE + 1][j] = SPACE + 1;
      if(nxt[i][j] == i) nxt[i][j] = SPACE + 1;
    }
  }


  int n, m;
  cin >> n >> m;

  for(int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    g[--u].emplace_back(--v, w);
    g[v].emplace_back(u, w);

    weights[{u, v}] = weights[{v, u}] = w;
  }


  for(auto e : g[0]) {
    int v = e.first;
    currentmark = v;

    if(visited[v]) {
      used[v] = 1;
      int x = v, y = visited[v], z = 0;
      int curweight = weights[{x, y}] ^ weights[{y, z}] ^ weights[{z, x}];
      f[y][baseid[y]] = 2;
      f[y][nxt[baseid[y]][curweight]] = 1;
      continue;
    }
    dfs(v, 0, baseid[v]);
    f[v][baseid[v]] = 1;
  }


  foo[0][0] = 1;
  for(int i = 0; i < g[0].size(); ++i) {
    int v = g[0][i].first;

    for(int msk = 0; msk < SPACE; ++msk) {
      foo[i + 1][msk] = add(foo[i + 1][msk], foo[i][msk]);
      if(!f[v][msk] || used[v]) continue;


      ftype cur = of[msk];
      for(int now = 0; now < SPACE; ++now) {
        int nwmsk = now;
        if(!foo[i][now]) continue;

        for(int x : cur) if(x > 0) nwmsk = nxt[nwmsk][x];
        if(nwmsk < SPACE) {
          foo[i + 1][nwmsk] = add(foo[i + 1][nwmsk], mult(foo[i][now], f[v][msk]));
        }
      }
    }
  }

  int ans = 0;
  for(int i = 0; i < SPACE; ++i) {
    ans = add(ans, foo[g[0].size()][i]);
  }

  cout << ans << endl;

  return 0;
}