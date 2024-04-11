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
const int MOD = 1e9 + 7;

#define TASKNAME ""

int x[4], y[4];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int ax[4], ay[4];

int get(int x0, int y0, int x1, int y1) {
  int a = abs(x0 - x1);
  int b = abs(y0 - y1);
  if (a > 0 && b > 0) {
    return -1;
  }
  
  return a == 0 ? b : a;
}

void solve() {
  vector<int> D;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < i; j++) {
      D.pb(abs(x[i] - x[j]));
      D.pb(abs(y[i] - y[j]));
    }
  }
  
  sort(D.begin(), D.end());
  D.resize(unique(D.begin(), D.end()) - D.begin());
  
  int best = -1;
  
  for (int d : D) {
    if (d == 0) {
      continue;
    }
    if (d == 9) debug("SHI");
    vector<int> X, Y;
    
    for (int i = 0; i < 4; i++) {
      X.pb(x[i] - d);
      X.pb(x[i]);
      X.pb(x[i] + d);
      Y.pb(y[i] - d);
      Y.pb(y[i]);
      Y.pb(y[i] + d);
    }
    
    int p[4] = {0, 1, 2, 3};
    
    do {
      vector<int> x_, y_;
      x_.pb(x[p[0]]);
      x_.pb(x[p[1]]);
      x_.pb(x[p[2]] - d);
      x_.pb(x[p[3]] - d);
      y_.pb(y[p[0]]);
      y_.pb(y[p[1]] - d);
      y_.pb(y[p[2]] - d);
      y_.pb(y[p[3]]);
      
      X.pb((*max_element(x_.begin(), x_.end()) + *min_element(x_.begin(), x_.end())) / 2);
      Y.pb((*max_element(y_.begin(), y_.end()) + *min_element(y_.begin(), y_.end())) / 2);
    } while (next_permutation(p, p + 4));
    
    for (int i = 0; i < 4; i++) p[i] = i;
    
    sort(X.begin(), X.end());
    X.resize(unique(X.begin(), X.end()) - X.begin());
    
    sort(Y.begin(), Y.end());
    Y.resize(unique(Y.begin(), Y.end()) - Y.begin());
    
    do {
      for (int xx : X) {
        for (int yy : Y) {
          vector<int> v;
          v.pb(get(xx, yy, x[p[0]], y[p[0]]));
          v.pb(get(xx, yy + d, x[p[1]], y[p[1]]));
          v.pb(get(xx + d, yy + d, x[p[2]], y[p[2]]));
          v.pb(get(xx + d, yy, x[p[3]], y[p[3]]));
          
          sort(v.begin(), v.end());
          
          if (v[0] >= 0) {
            if (best == -1 || v[3] < best) {
              best = v[3];
              ax[p[0]] = xx; ay[p[0]] = yy;
              ax[p[1]] = xx; ay[p[1]] = yy + d;
              ax[p[2]] = xx + d; ay[p[2]] = yy + d;
              ax[p[3]] = xx + d; ay[p[3]] = yy;
            }
          }
        }
      }
    } while (next_permutation(p, p + 4));
  }
  
  if (best == -1) {
    cout << "-1\n";
    return;
  }
  
  cout << best << "\n";
  for (int i = 0; i < 4; i++) {
    cout << ax[i] << " " << ay[i] << "\n";
  }
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	float tbegin = clock();
	srand(time(nullptr));

#ifdef DEBUG
	freopen("input.txt", "r", stdin);
#else
	if (TASKNAME != "") {
		freopen(TASKNAME ".in", "r", stdin);
		freopen(TASKNAME ".out", "w", stdout);
	}
#endif

  int t;
  cin >> t;
  
  for (int i = 0; i < t; i++) {
    for (int j = 0; j < 4; j++) {
      cin >> x[j] >> y[j];
    }
    solve();
  }

#ifdef DEBUG
	cerr << "TIME ELAPSED: " << (clock() - tbegin) / CLOCKS_PER_SEC << "\n";
#endif

	return 0;
}