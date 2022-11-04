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

int n, k;

int dist(char a, char b) {
  return abs(a - b);
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

  cin >> n >> k;
  string s;
  cin >> s;
  string t;

  for (int i = 0; i < n; i++) {
    char c = s[i];
    int a = dist(c, 'z');
    int b = dist(c, 'a');
    if (a > b) {
      if (a <= k) {
        k -= a;
        t += 'z';
      } else {
        t += (char) (c + k);
        k = 0;
      }
    } else {
      if (b <= k) {
        k -= b;
        t += 'a';
      } else {
        t += (char) (c - k);
        k = 0;
      }
    }
  }

  if (k) {
    cout << "-1\n";
  } else {
    cout << t << "\n";
  }

#ifdef DEBUG
  cerr << "TIME ELAPSED: " << (clock() - tbegin) / CLOCKS_PER_SEC << "\n";
#endif

  return 0;
}