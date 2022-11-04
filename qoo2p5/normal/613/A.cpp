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
const ld EPS = 1e-11;
const ld PI = 3.141592653589;

#define TASKNAME ""

struct vect {
  ll x, y;

  vect() {}
  vect(ll x, ll y) : x(x), y(y) {}
  vect(vect a, vect b) : x(b.x - a.x), y(b.y - a.y) {}

  ll operator*(const vect &other) const {
    return x * other.y - other.x * y;
  }

  ll operator^(const vect &other) const {
    return x * other.x + y * other.y;
  }

  vect operator-(const vect &other) const {
    return vect(x - other.x, y - other.y);
  }
};

ld dist(vect a, vect b) {
  return sqrt((ld) (b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
}

ld dist(vect a, vect b, vect c) {
  if ((vect(b, c) ^ vect(b, a)) > 0 && (vect(c, b) ^ vect(c, a)) > 0) {
    return abs(vect(b, c) * vect(b, a)) / dist(b, c);
  }

  return min(dist(a, b), dist(a, c));
}

vect read_vect() {
  ll x, y;
  cin >> x >> y;
  return vect(x, y);
}

ld area(ld r) {
  return PI * r * r;
}

int n;
vector<vect> a;
vect p;

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

  cin >> n;
  vect p = read_vect();

  for (int i = 0; i < n; i++) {
    a.pb(read_vect());
  }

  ld dist_max = 0;
  ld dist_min = 1e10;

  a.pb(*a.begin());

  for (int i = 0; i < n; i++) {
    dist_max = max(dist_max, dist(p, a[i]));
    dist_min = min(dist_min, dist(p, a[i]));
    dist_min = min(dist_min, dist(p, a[i], a[i + 1]));
  }

  cout << fixed << setprecision(20) << area(dist_max) - area(dist_min) << endl;

#ifdef DEBUG
	cerr << "TIME ELAPSED: " << (clock() - tbegin) / CLOCKS_PER_SEC << "\n";
#endif

    return 0;
}