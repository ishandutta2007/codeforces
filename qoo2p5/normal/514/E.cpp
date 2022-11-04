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

const int INF = 1e9;
const ll LINF = 1e18;
const ld EPS = 1e-10;
const ld PI = 3.141592653589;
const ll MOD = 1e9 + 7;

#define TASKNAME ""

const int N = 1e5 + 123;

int n, x;
int d[N];

void cut(int &x) {
  if (x >= MOD) {
    x -= MOD;
  }
}

void add(int &x, int y) {
  x += y;
  cut(x);
}

struct Matrix {
  int n, m;
  int **a;

  Matrix() {}

  Matrix(int n, int m) : n(n), m(m) {
    a = new int*[n];
    for (int i = 0; i < n; i++) {
      a[i] = new int[m];
      fill(a[i], a[i] + m, 0);
    }
  }

  Matrix operator*(const Matrix &b) const {
    Matrix ans(n, b.m);

    for (int i = 0; i < ans.n; i++) {
      for (int j = 0; j < ans.m; j++) {
        for (int k = 0; k < m; k++) {
          add(ans[i][j], (a[i][k] * 1LL * b[k][j]) % MOD);
        }
      }
    }

    return ans;
  }

  Matrix operator^(const int p) const {
    if (p == 1) {
      return (*this);
    }
    if (p & 1) {
      return (*this) * ((*this) ^ (p - 1));
    }
    Matrix tmp = (*this) ^ (p / 2);
    return tmp * tmp;
  }

  int* operator[](const int i) const {
    return a[i];
  }
};

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

  cin >> n >> x;
  for (int i = 0; i < n; i++) {
    cin >> d[i];
  }

  if (x == 0) {
    cout << "1\n";
    return 0;
  }

  Matrix go(102, 102);
  for (int i = 1; i < 101; i++) {
    go[i][i - 1]++;
  }
  for (int i = 0; i < n; i++) {
    int from = 100 - d[i];
    go[from + 1][100]++;
  }
  go[100][101] = 1;
  go[101][101] = 1;

  Matrix start(1, 101);
  start[0][100] = 1;

  Matrix res = start * (go ^ x);
  int ans = res[0][100] + res[0][101];
  cut(ans);
  cout << ans << "\n";

#ifdef DEBUG
	cerr << "TIME ELAPSED: " << (clock() - tbegin) / CLOCKS_PER_SEC << "\n";
#endif

	return 0;
}