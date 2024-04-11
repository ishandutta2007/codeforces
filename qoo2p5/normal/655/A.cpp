#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned ll
#define ld long double
#define sz(x) (int) x.size()
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define eq(a, b) abs(a - b) < EPS

#ifdef DEBUG
  #define debug(x) cerr << "\033[31m" << x << "\033[39m" << endl;
#else
  #define debug(x)
#endif

const int INF = 1e9;
const ll LINF = 1e18;
const ld EPS = 1e-10;
const ld PI = 3.141592653589;
const int MOD = 1e9 + 7;

#define TASKNAME ""

vector<vector<char>> f(2, vector<char>(2)), t(2, vector<char>(2));

bool ok(int a, int b) {
  return 0 <= a && a < 2 && 0 <= b && b < 2;
}

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void solve(vector<vector<char>> cur, int step = 0) {
  if (cur == t) {
    cout << "YES\n";
    exit(0);
  }

  if (step == 10) {
    return;
  }

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      if (cur[i][j] == 'X') {
        for (int dir = 0; dir < 4; dir++) {
          int ni = i + dx[dir];
          int nj = j + dy[dir];

          if (ok(ni, nj)) {
            auto ncur = cur;
            ncur[i][j] = ncur[ni][nj];
            ncur[ni][nj] = 'X';
            solve(ncur, step + 1);
          }
        }

        return;
      }
    }
  }
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

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      cin >> f[i][j];
    }
  }

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      cin >> t[i][j];
    }
  }

  solve(f);

  cout << "NO\n";

#ifdef DEBUG
  cerr << "TIME ELAPSED: " << (clock() - tbegin) / CLOCKS_PER_SEC << "\n";
#endif

  return 0;
}