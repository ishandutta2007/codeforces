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

ll n, k;
int l, m;

void cut(int &x) {
  if (x >= m) {
    x -= m;
  }
  if (x < 0) {
    x += m;
  }
}

class Matrix {
private:
  int **a;

  Matrix power(const Matrix &x, ll p) {
    if (p == 1) {
      return x;
    }

    if (p & 1) {
      return power(x, p - 1) * x;
    } else {
      Matrix tmp = power(x, p / 2);
      return tmp * tmp;
    }
  }

public:
  int n, m;

  Matrix() {}

  Matrix(int n, int m) : n(n), m(m) {
    a = new int*[n];
    for (int i = 0; i < n; i++) {
      a[i] = new int[m];
      fill(a[i], a[i] + m, 0);
    }
  }

  Matrix operator^(ll p) {
    return power(*this, p);
  }

  int* operator[](const int i) const {
    return a[i];
  }

  Matrix operator*(const Matrix &b) const {
    Matrix ans(n, b.m);

    for (int i = 0; i < ans.n; i++) {
      for (int j = 0; j < ans.m; j++) {
        for (int k = 0; k < m; k++) {
          ans[i][j] += (a[i][k] * 1LL * b[k][j]) % ::m;
          cut(ans[i][j]);
        }
      }
    }

    return ans;
  }
};

int power(int x, ll p) {
  if (p == 0) {
    return 1;
  }

  if (p & 1) {
    return (power(x, p - 1) * 1LL * x) % m;
  } else {
    const int tmp = power(x, p / 2);
    return (tmp * 1LL * tmp) % m;
  }
}

int get_fibb(ll i) {
  Matrix go(2, 2);
  go[0][0] = 0;
  go[0][1] = 1;
  go[1][0] = 1;
  go[1][1] = 1;

  Matrix start(1, 2);
  start[0][0] = 1;
  start[0][1] = 1;

  Matrix ans = start * (go ^ i);
  return ans[0][0];
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

  cin >> n >> k >> l >> m;

  int cnt = 0;
  for (int i = 0; i < 62; i++) {
    if (k & (1LL << i)) {
      cnt++;
      if (i >= l) {
        cout << "0\n";
        return 0;
      }
    }
  }

  int w = get_fibb(n + 1);
  int tmp = power(2, n) - w;
  cut(tmp);
  int ans = (power(w, l - cnt) * 1LL * power(tmp, cnt)) % m;
  cout << ans << "\n";

#ifdef DEBUG
	cerr << "TIME ELAPSED: " << (clock() - tbegin) / CLOCKS_PER_SEC << "\n";
#endif

	return 0;
}