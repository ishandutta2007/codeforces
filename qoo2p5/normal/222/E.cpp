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

void cut(int &x) {
  if (x >= MOD) x -= MOD;
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
          ans[i][j] += (a[i][k] * 1LL * b[k][j]) % MOD;
          cut(ans[i][j]);
        }
      }
    }

    return ans;
  }

  Matrix operator^(const ll p) const {
    if (p == 1) {
      return (*this);
    }

    if (p & 1) {
      return ((*this) ^ (p - 1)) * (*this);
    } else {
      const Matrix tmp = (*this) ^ (p / 2);
      return tmp * tmp;
    }
  }

  int* operator[](const int i) const {
    return a[i];
  }
};

int get(char c) {
  if ('a' <= c && c <= 'z') {
    return c - 'a';
  } else {
    return c - 'A' + 26;
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

  ll n;
  int m, k;
  cin >> n >> m >> k;

  Matrix go(m, m);
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < m; j++) {
      go[i][j] = 1;
    }
  }

  for (int i = 0; i < k; i++) {
    string s;
    cin >> s;
    go[get(s[0])][get(s[1])] = 0;
  }

  if (n == 1) {
    cout << m << "\n";
    return 0;
  }

  Matrix start(1, m);
  for (int i = 0; i < m; i++) {
    start[0][i] = 1;
  }

  Matrix ans = start * (go ^ (n - 1));
  int sum = 0;
  for (int i = 0; i < m; i++) {
    sum += ans[0][i];
    cut(sum);
  }

  cout << sum << "\n";

#ifdef DEBUG
	cerr << "TIME ELAPSED: " << (clock() - tbegin) / CLOCKS_PER_SEC << "\n";
#endif

	return 0;
}