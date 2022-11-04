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

const int N = 2e5 + 123;

int n, b;
int t[N], d[N];
ll ans[N];

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

  cin >> n >> b;
  for (int i = 0; i < n; i++) {
    cin >> t[i] >> d[i];
  }

  queue<int> q;
  ll cur = t[0];
  q.push(0);

  for (int i = 1; i < n; i++) {
    while (!q.empty()) {
      int v = q.front();
      ll end = max(cur, (ll) t[v]) + d[v];
      if (end <= t[i]) {
        ans[v] = end;
        q.pop();
        cur = end;
      } else {
        break;
      }
    }

    if (sz(q) == b + 1) {
      ans[i] = -1;
    } else {
      q.push(i);
    }
  }

  while (!q.empty()) {
    int v = q.front();
    ll end = max(cur, (ll) t[v]) + d[v];
    ans[v] = end;
    cur = end;
    q.pop();
  }

  for (int i = 0; i < n; i++) {
    cout << ans[i] << " ";
  }
  cout << "\n";

#ifdef DEBUG
  cerr << "TIME ELAPSED: " << (clock() - tbegin) / CLOCKS_PER_SEC << "\n";
#endif

  return 0;
}