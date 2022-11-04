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

const int N = 2e5 + 123;

int n, k, b, c;
int a[N];
vector<int> good[5];
queue<int> cur[5];

ll dist(ll f, ll t) {
  return min((t - f) * c, (t - f) / 5 * b + ((t - f) % 5) * c);
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

  cin >> n >> k >> b >> c;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  sort(a, a + n);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 5; j++) {
      good[((a[i] + j) % 5 + 5) % 5].pb(a[i] + j);
    }
  }

  ll ans = LINF;

  for (int j = 0; j < 5; j++) {
    sort(good[j].begin(), good[j].end());
    good[j].resize(unique(good[j].begin(), good[j].end()) - good[j].begin());

    for (int t = 0; t < 5; t++) {
      while (!cur[t].empty()) {
        cur[t].pop();
      }
    }

    int ptr = 0;
    ll cur_ans = 0;
    int prev_val = 0;
    int count = 0;

    for (int val : good[j]) {
      cur_ans += dist(prev_val, val) * count;

      while (ptr < n && a[ptr] <= val) {
        int r = (a[ptr] % 5 + 5) % 5;

        if (count < k) {
          cur[r].push(a[ptr]);
          cur_ans += dist(a[ptr], val);
          count++;
        } else {
          ll best = 0;
          int best_p = -1;

          for (int p = 0; p < 5; p++) {
            if (!cur[p].empty() && dist(cur[p].front(), val) - dist(a[ptr], val) > best) {
              best = dist(cur[p].front(), val) - dist(a[ptr], val);
              best_p = p;
            }
          }

          if (best_p != -1) {
            cur_ans -= dist(cur[best_p].front(), val);
            cur[best_p].pop();
            cur[r].push(a[ptr]);
            cur_ans += dist(a[ptr], val);
          }
        }

        ptr++;
      }
      debug(j << " " << val << " " << count << " "  << cur_ans);

      if (count == k) {
        ans = min(ans, cur_ans);
      }

      prev_val = val;
    }
  }

  cout << ans << "\n";

#ifdef DEBUG
	cerr << "TIME ELAPSED: " << (clock() - tbegin) / CLOCKS_PER_SEC << "\n";
#endif

	return 0;
}