#include <bits/stdc++.h>

using namespace std;

int nDigit(int x) {
  return x ? 1 + nDigit(x / 10) : 0;
}

const int N = 600010;
const long long mod = 1e9 + 7;

int n, m;
int done[N];
int dist[N];
long long ans[N];
vector < pair < int, int > > ds[N];

int height[N];
int jump[N][20];

pair < int, int > lca(int x, int y) {
  if(x == y) return make_pair(x, x);
  for(int lg = 19; lg >= 0; --lg) {
    if(jump[x][lg] != jump[y][lg]) {
      x = jump[x][lg];
      y = jump[y][lg];
    }
  }
  return make_pair(x, y);
}

int cnt;
int cpar[N];
int trie[N][11];

string getNum(int x) {
  if(x == 0) return "";
  return getNum(x / 10) + char(x % 10 + '0');
}

void addNode(int x, int p, int c) {
  trie[p][c] = x;
  cpar[x] = c;
  height[x] = height[p] + 1;
  ans[x] = ans[p] * 10 + c;
  ans[x] %= mod;
  jump[x][0] = p;
  for(int lg = 1; lg < 20; ++lg) jump[x][lg] = jump[jump[x][lg - 1]][lg - 1];
}

int add(int start, string key) {
  for(auto &c : key) {
    c -= '0';
    if(!trie[start][c]) addNode(++cnt, start, c);
    start = trie[start][c];
  }
  return start;
}

int at[N];
map < pair < int, int >, int > idx;

int main(){
	ios_base::sync_with_stdio(false); 
  cin.tie(NULL); cout.tie(NULL); 

  cin >> n >> m;
  for(int i = 1; i <= m; ++i) {
    int u, v;
    cin >> u >> v;
    idx[make_pair(u, v)] = i;
    idx[make_pair(v, u)] = i;
    ds[u].emplace_back(v, nDigit(i));
    ds[v].emplace_back(u, nDigit(i));
  }

  memset(dist, 60, sizeof dist);

  set < pair < int, int > > pq; 
  pq.emplace(dist[1] = 0, 1);

  vector < int > ordered;

  while(!pq.empty()) {
    int x = pq.begin() -> second; pq.erase(pq.begin());
    if(done[x]) continue;
    done[x] = 1;

    ordered.push_back(x);

    for(auto &e : ds[x]) {
      if(dist[e.first] > dist[x] + e.second) {
        dist[e.first] = dist[x] + e.second;
        pq.emplace(dist[e.first], e.first);
      }
    }
  }


  for(int i = 1; i < n; ++i) {
    int v = ordered[i];
    at[v] = -1;

    for(auto &e : ds[v]) {
      int s = e.first, w = e.second;
      if(dist[s] + w != dist[v]) continue;

      int r = add(at[s], getNum(idx[make_pair(s, v)]));
      if(at[v] == -1) {
        at[v] = r;
        continue;
      }

      auto p = lca(at[v], r);

      if(p.first == p.second) continue;
      if(cpar[p.first] > cpar[p.second]) at[v] = r;
    } 
  }

  for(int i = 2; i <= n; ++i) cout << ans[at[i]] << "\n";

  return 0;
}