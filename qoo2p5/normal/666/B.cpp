#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned ll
#define ld long double
#define sz(x) (ll) x.size()
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define eq(a, b) abs(a - b) < EPS

#ifdef DEBUG
	#define debug(x) cerr << "\033[31m" << x << "\033[39m" << endl;
#else
	#define debug(x)
#endif

const ll INF = 1e9;
const ll LINF = 1e18;
const ld EPS = 1e-9;
const ld PI = 3.141592653589;
const ll MOD = 1e9 + 7;

#define TASKNAME ""

const int N = 3010;

int n, m;
vector<int> g[N];
int dist[N][N];
bool used[N][N];

void dijkstra(int v) {
  fill(dist[v], dist[v] + n, INF);
  dist[v][v] = 0;
  priority_queue<pair<int, int>> q;
  q.push({0, v});
  
  while (!q.empty()) {
    auto el = q.top();
    q.pop();
    int u = el.second;
    
    if (used[v][u]) {
      continue;
    }
    
    used[v][u] = 1;
    
    for (int to : g[u]) {      
      if (dist[v][u] + 1 < dist[v][to]) {
        dist[v][to] = dist[v][u] + 1;
        q.push({-dist[v][to], to});
      }
    }
  }
}

vector<pair<int, int>> st_out[N];
vector<pair<int, int>> st_in[N];

void build(int v) {
  st_out[v].reserve(n);
  st_in[v].reserve(n);
  
  for (int i = 0; i < n; i++) {
    int d = dist[v][i] == INF ? 0 : dist[v][i];
    st_out[v].pb(mp(d, i));
  }
  
  for (int i = 0; i < n; i++) {
    int d = dist[i][v] == INF ? 0 : dist[i][v];
    st_in[v].pb(mp(d, i));
  }
  
  sort(st_out[v].begin(), st_out[v].end());
  sort(st_in[v].begin(), st_in[v].end());
}

int w[3];

pair<int, int> get(int v, vector<pair<int, int>> &s) {
  for (int i = n - 1; i >= 0; i--) {
    bool ok = true;
    for (int j = 0; j < 3; j++) {
      if (s[i].second == w[j]) {
        ok = false;
      }
    }
    
    if (ok) {
      return s[i];
    }
  }
  
  return {0, 0};
}

pair<int, int> get_in(int v, int w1, int w2, int w3) {
  w[0] = w1;
  w[1] = w2;
  w[2] = w3;
  return get(v, st_in[v]);
}

pair<int, int> get_out(int v, int w1, int w2, int w3) {
  w[0] = w1;
  w[1] = w2;
  w[2] = w3;
  return get(v, st_out[v]);
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	float tbegin = clock();
	srand(time(nullptr));

#ifdef DEBUG
	freopen("input.txt", "r", stdin);
#else
	if (TASKNAME != "") {
		freopen(TASKNAME ".in", "r", stdin);
		freopen(TASKNAME ".out", "w", stdout);
	}
#endif

  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    g[u].pb(v);
  }
  
  for (int i = 0; i < n; i++) {
    dijkstra(i);
  }
  
  for (int i = 0; i < n; i++) {
    build(i);
  }
  
  int best = 0;
  int c[4] = {1, 2, 3, 4};
  
  for (int c2 = 0; c2 < n; c2++) {
    for (int c3 = 0; c3 < n; c3++) {
      if (c2 == c3 || dist[c2][c3] == INF) {
        continue;
      }
      
      for (int i = 0; i < 1; i++) {
        int cur = dist[c2][c3];
        pair<int, int> t1 = get_in(c2, c2, c3, -1);
        if (t1.first == 0) {
          continue;
        }
        cur += t1.first;
        int c1 = t1.second;
        pair<int, int> t2 = get_out(c3, c1, c2, c3);
        if (t2.first == 0) {
          continue;
        }
        int c4 = t2.second;
        cur += t2.first;
        
        if (cur > best) {
          best = cur;
          c[0] = c1;
          c[1] = c2;
          c[2] = c3;
          c[3] = c4;
        }
      }
      
      for (int i = 0; i < 1; i++) {
        int cur = dist[c2][c3];
        pair<int, int> t1 = get_out(c3, c2, c3, -1);
        if (t1.first == 0) {
          continue;
        }
        cur += t1.first;
        int c4 = t1.second;
        pair<int, int> t2 = get_in(c2, c2, c3, c4);
        if (t2.first == 0) {
          continue;
        }
        int c1 = t2.second;
        cur += t2.first;
        
        if (cur > best) {
          best = cur;
          c[0] = c1;
          c[1] = c2;
          c[2] = c3;
          c[3] = c4;
        }
      }

    }
  }
    
  for (int i = 0; i < 4; i++) {
    cout << c[i] + 1 << " ";
  }
  cout << "\n";

#ifdef DEBUG
	cerr << "TIME ELAPSED: " << (clock() - tbegin) / CLOCKS_PER_SEC << "\n";
#endif

	return 0;
}