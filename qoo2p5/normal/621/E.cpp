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
  if (x < 0) x += MOD;
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
        for (int t = 0; t < m; t++) {
          ans[i][j] = (ans[i][j] + a[i][t] * 1LL * b[t][j]) % MOD;
        }
      }
    }

    return ans;
  }

  int* operator[](int i) const {
    return a[i];
  }
};

template<typename T> T power(const T &x, int p) {
  if (p == 1) {
    return x;
  }

  if (p & 1) {
    return power(x, p - 1) * x;
  } else {
    T tmp = power(x, p / 2);
    return tmp * tmp;
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

  int n, b, k, x;
  cin >> n >> b >> k >> x;
  int* a = new int[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  Matrix go(x, x);

  for (int from = 0; from < x; from++) {
    for (int i = 0; i < n; i++) {
      int to = (from * 10 + a[i]) % x;
      go[from][to]++;
    }
  }

  Matrix begin(1, x);
  begin[0][0] = 1;

  Matrix ans = begin * power(go, b);
  cout << ans[0][k] << "\n";

#ifdef DEBUG
	cerr << "TIME ELAPSED: " << (clock() - tbegin) / CLOCKS_PER_SEC << "\n";
#endif

	return 0;
}