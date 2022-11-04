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

const int N = 1100;

int mod4(int x) {
  while (x >= 4) x -= 4;
  return x;
}

int n, m;
char f[N][N];
int dist[N][N][4];

const int UP = 0;
const int RIGHT = 1;
const int DOWN = 2;
const int LEFT = 3;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int rev[4] = {DOWN, LEFT, UP, RIGHT};

map<char, vector<int>> allowed;
map<char, char> nxt;
map<char, char> precalc[4];

bool ok(int x, int y) {
  return 0 <= x && x < n && 0 <= y && y < m;
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	float tbegin = clock();
	srand(42);

#ifdef DEBUG
	freopen("input.txt", "r", stdin);
#else
	if (TASKNAME != "") {
		freopen(TASKNAME ".in", "r", stdin);
		freopen(TASKNAME ".out", "w", stdout);
	}
#endif

  allowed['+'].pb(UP);
  allowed['+'].pb(RIGHT);
  allowed['+'].pb(DOWN);
  allowed['+'].pb(LEFT);
  
  allowed['-'].pb(LEFT);
  allowed['-'].pb(RIGHT);
  
  allowed['|'].pb(UP);
  allowed['|'].pb(DOWN);
  
  allowed['^'].pb(UP);
  
  allowed['>'].pb(RIGHT);
  
  allowed['<'].pb(LEFT);
  
  allowed['v'].pb(DOWN);
  
  allowed['L'].pb(UP);
  allowed['L'].pb(RIGHT);
  allowed['L'].pb(DOWN);
  
  allowed['R'].pb(UP);
  allowed['R'].pb(DOWN);
  allowed['R'].pb(LEFT);
  
  allowed['U'].pb(RIGHT);
  allowed['U'].pb(DOWN);
  allowed['U'].pb(LEFT);
  
  allowed['D'].pb(UP);
  allowed['D'].pb(RIGHT);
  allowed['D'].pb(LEFT);
  
  nxt['+'] = '+';
  nxt['-'] = '|';
  nxt['|'] = '-';
  nxt['^'] = '>';
  nxt['>'] = 'v';
  nxt['v'] = '<';
  nxt['<'] = '^';
  nxt['L'] = 'U';
  nxt['U'] = 'R';
  nxt['R'] = 'D';
  nxt['D'] = 'L';
  nxt['*'] = '*';

  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> f[i][j];
    }
  }
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (int k = 0; k < 4; k++) {
        dist[i][j][k] = INF;
      }
    }
  }
  
  int x0, y0;
  int x1, y1;
  cin >> x0 >> y0;
  cin >> x1 >> y1;
  x0--; y0--;
  x1--; y1--;
  
  queue<pair<pair<int, int>, int>> q;
  q.push({{x0, y0}, 0});
  dist[x0][y0][0] = 0;
  
  for (int i = 0; i < 4; i++) {
    for (auto &it : nxt) {
      char cur = it.first;
      for (int j = 0; j < i; j++) {
        cur = nxt[cur];
      }
      
      precalc[i][it.first] = cur;
    }
  }
  
  while (!q.empty()) {
    auto el = q.front();
    q.pop();
    int x = el.first.first;
    int y = el.first.second;
    int d = el.second;
    char cur = precalc[d][f[x][y]];
    
    for (int dir : allowed[cur]) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if (!ok(nx, ny)) continue;
      char there = precalc[d][f[nx][ny]];
      bool found = false;
      for (int a : allowed[there]) {
        if (a == rev[dir]) found = true;
      }
      if (!found) continue;
      
      if (dist[x][y][d] + 1 < dist[nx][ny][d]) {
        dist[nx][ny][d] = dist[x][y][d] + 1;
        q.push({{nx, ny}, d});
        // printf("(%d, %d | %d: %c) --> (%d, %d | %d), cost = %d\n", x, y, d, cur, nx, ny, d, dist[nx][ny][d]);
      }
    }
    
    int nd = mod4(d + 1);
    if (dist[x][y][d] + 1 < dist[x][y][nd]) {
      dist[x][y][nd] = dist[x][y][d] + 1;
      q.push({{x, y}, nd});
      // printf("(%d, %d | %d: %c) --> (%d, %d | %d), cost = %d\n", x, y, d, cur, x, y, nd, dist[x][y][nd]);
    }
  }
  
  int ans = INF;
  
  for (int k = 0; k < 4; k++) {
    ans = min(ans, dist[x1][y1][k]);
  }
  
  cout << (ans == INF ? -1 : ans) << "\n";

#ifdef DEBUG
	cerr << "TIME ELAPSED: " << (clock() - tbegin) / CLOCKS_PER_SEC << "\n";
#endif

	return 0;
}