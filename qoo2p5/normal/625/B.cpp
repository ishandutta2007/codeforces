#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned ll
#define ld long double
#define sz(x) (int) x.size()
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define eq(a, b) abs(a - b) < EPS

const int INF = 1e9;
const ll LINF = 1e18;
const ld EPS = 1e-10;
const ld PI = 3.141592653589;

#define TASKNAME ""

string s, t;
bool arr[1000000];

int main() {
  ios::sync_with_stdio(false);
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

  cin >> s >> t;

  for (int i = 0; i <= sz(s) - sz(t); i++) {
    if (s.substr(i, sz(t)).compare(t) == 0) {
      arr[i + sz(t) - 1] = true;
    }
  }

  int ans = 0;

  for (int i = 0; i < sz(s); ) {
    if (arr[i]) {
      ans++;
      i += sz(t);
    } else {
      i++;
    }
  }

  cout << ans << endl;

#ifdef DEBUG
	cerr << "TIME ELAPSED: " << (clock() - tbegin) / CLOCKS_PER_SEC << "\n";
#endif

  return 0;
}