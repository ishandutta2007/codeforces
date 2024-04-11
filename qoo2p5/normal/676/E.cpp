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

const int N = 1e5 + 123;

int n, k;
bool known[N];
int q[N];

void yes() {
  cout << "Yes\n";
  exit(0);
}

void no() {
  cout << "No\n";
  exit(0);
}

int mods[15] = {1000000007, 1000000009, 179, 1000000000, 31, 37, 1000000001, 985315641, 0, 0, 0, 0, 0, 0, 0};

int mod(ll a, int m) {
  int r = a % m;
  while (r < 0) r += m;
  return r;
}

int power(int a, int p, int m) {
  if (p == 0) {
    return 1;
  }
  
  if (p & 1) {
    return mod(power(a, p - 1, m) * 1LL * a, m);
  }
  
  int tmp = power(a, p / 2, m);
  return mod(tmp * 1LL * tmp, m);
}

void cut(int &x, int m) {
  while (x >= m) x -= m;
  while (x < 0) x += m;
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

  for (int i = 8; i < 15; i++) {
    mods[i] = abs(rand() % 1000000000) + 1;
  }

  cin >> n >> k;
  for (int i = 0; i < n + 1; i++) {
    string s;
    cin >> s;
    
    if (s[0] != '?') {
      known[i] = true;
      q[i] = stoi(s);
    }
  }
  
  int a = 0;
  int b = 0;
  for (int i = 0; i < n + 1; i++) {
    if (known[i]) a++;
    else b++;
  }
  
  if (a == n + 1) {
    bool ok = true;
    
    for (int d = 0; d < 15; d++) {
      int sum = 0;
      int m = mods[d];
      
      for (int i = 0; i < n + 1; i++) {
        sum += mod(power(k, i, m) * 1LL * q[i], m);
        cut(sum, m);
      }
      
      ok &= (sum == 0);
    }
    
    if (ok) {
      yes();
    } else {
      no();
    }
  }
  
  if (k == 0) {
    if (known[0]) {
      if (q[0] != 0) {
        no();
      } else {
        yes();
      }
    } else {
      if (a % 2 == 1) {
        yes();
      } else {
        no();
      }
    }
  }
  
  if ((n + 1) % 2 == 0) {
    yes();
  } else {
    no();
  }

#ifdef DEBUG
	cerr << "TIME ELAPSED: " << (clock() - tbegin) / CLOCKS_PER_SEC << "\n";
#endif

	return 0;
}